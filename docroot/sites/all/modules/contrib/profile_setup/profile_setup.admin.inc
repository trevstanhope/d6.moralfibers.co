<?php

/**
 * @file
 * Holds all the custom worker functions related to the pageroute route
 */

/**
 * username change functions
 */
/**
 * validate and save username
 */
function profile_setup_username_form_validate($form, &$form_state) {
  $account = $form_state['values']['_account'];
  if ($form_state['values']['name']) {
    // only validate if they've changed the username
    if ($form_state['values']['name'] != $account->name) {
      if ($error = user_validate_name($form_state['values']['name'])) {
        form_set_error('name', $error);
        return false;
      }
      else if (db_result(db_query("SELECT COUNT(*) FROM {users} WHERE uid <> %d AND LOWER(name) = LOWER('%s')", $account->uid, $form_state['values']['name'])) > 0) {
        form_set_error('name', t('The name %name is already taken.', array('%name' => $form_state['values']['name'])));
        return false;
      }
      else if (drupal_is_denied('user', $form_state['values']['name'])) {
        form_set_error('name', t('The name %name has been denied access.', array('%name' => $form_state['values']['name'])));
        return false;
      }
    }
  }
  return true;
}

/**
 * validate and save username
 */
function profile_setup_username_form_submit($form, &$form_state) {
  global $user;
  if ($form_state['values']['name']) {
    if ($form_state['values']['name'] != $user->name) {
      $account = $form_state['values']['_account'];
      unset($form_state['values']['_account'], $form_state['values']['op'], $form_state['values']['submit'], $form_state['values']['delete'], $form_state['values']['form_token'], $form_state['values']['form_id'], $form_state['values']['_category']);
      if ($new = user_save($account, $form_state['values'])) {
        $user->name = $new->name;
		drupal_set_message(t('Your username was successfully updated'));
		return true;
      }
    }
  }
}
 
 
/**
 * profile picture upload
 */
/**
 * validation
 */
function _profile_setup_profile_picture_validate($file, $account) {
  global $user;
  // Check that uploaded file is an image, with a maximum file size
  // and maximum height/width.
  $info = image_get_info($file->filepath);
  list($maxwidth, $maxheight) = explode('x', variable_get('user_picture_dimensions', '85x85'));

  if (!$info || !$info['extension']) {
    form_set_error('picture_upload', t('The uploaded file was not an image.'));
    return FALSE;
  }
  else if (image_get_toolkit()) {
    image_scale($file->filepath, $file->filepath, $maxwidth, $maxheight);
  }
  else if (filesize($file->filepath) > (variable_get('user_picture_file_size', '30') * 1000)) {
    form_set_error('picture_upload', t('The uploaded image is too large; the maximum file size is %size kB.', array('%size' => variable_get('user_picture_file_size', '30'))));
    return FALSE;
  }
  else if ($info['width'] > $maxwidth || $info['height'] > $maxheight) {
    form_set_error('picture_upload', t('The uploaded image is too large; the maximum dimensions are %dimensions pixels.', array('%dimensions' => variable_get('user_picture_dimensions', '85x85'))));
    return FALSE;
  }

  //Rename picture with unique id - taken from unique_avatar.module
  $dest = variable_get('user_picture_path', 'pictures') .'/picture-'. $user->uid .'-'. md5(time()) .'.'. $info['extension'];
  if (file_move($file->filepath, $dest)) {
    //Clean up existing picture
    if (module_exists('imagecache')) {
      imagecache_image_flush($user->picture);
    }
    file_delete($user->picture);

    //Assign new picture
    $edit['picture'] = file_directory_path() .'/'. $dest;
    $user->picture = file_directory_path() .'/'. $dest;
    db_query("UPDATE {users} SET picture = '%s' WHERE uid = %d", $user->picture, $user->uid);
    return TRUE;
  }
  return FALSE;
}

/**
 * validate and store user profile picture
 */
function profile_setup_picture_form_submit($form, &$form_state) {
  // If required, validate the uploaded picture.
  $validators = array(
    'file_validate_is_image' => array(),
    'file_validate_image_resolution' => array(variable_get('user_picture_dimensions', '85x85')),
    'file_validate_size' => array(variable_get('user_picture_file_size', '30') * 1024),
  );
  
  $account = $form_state['values']['_account'];
  if ($file = file_save_upload('picture_upload', $validators)) {
    if (!_profile_setup_profile_picture_validate($file, $account)) {
      return false;
    }
    else {
      drupal_set_message(t('Your profile picture was successfully uploaded'));
      return true;
    }
  }
  else {
    return true;
  }		
} 


/** 
 * account form
 */
/**
 * determines if account category is produced by content profile module
 */
function profile_setup_page_is_content_profile_type($category) {
  if(function_exists("is_content_profile")) {  
    return is_content_profile($category);
  }
  else {
    return FALSE;
  }
}

/**
 * user_profile type form validation
 * 
 * Because _user_edit_validate() function passes arg(1) 
 * from user_user() we can just use user_module_invoke as our URL may not contain arg(1)
 */
function profile_setup_user_profile_form_validate(&$form_state) {
  profile_setup_user_invoke('validate', $form_state['values'], $form_state['values']['_account'], $form_state['values']['_category'], array('user'));
  // Validate input to ensure that non-privileged users can't alter protected data.
  if ((!user_access('administer users') && array_intersect(array_keys($form_state['values']), array('uid', 'init', 'session'))) || (!user_access('administer permissions') && isset($form_state['values']['roles']))) {
    watchdog('security', 'Detected malicious attempt to alter protected user fields.', array(), WATCHDOG_WARNING);
    // set this to a value type field
    form_set_error('category', t('Detected malicious attempt to alter protected user fields.'));
    return FALSE;
  }
  if (form_get_errors()) {
    return FALSE;
  }
  return TRUE;
}

/**
 * user_profile type form submission
 */
function profile_setup_user_profile_form_submit(&$form_state) {
  $account = $form_state['values']['_account'];
  $category = $form_state['values']['_category'];
  unset($form_state['values']['_account'], $form_state['values']['op'], $form_state['values']['submit'], $form_state['values']['delete'], $form_state['values']['form_token'], $form_state['values']['form_id'], $form_state['values']['_category']);
  user_module_invoke('submit', $form_state['values'], $account, $category);
  user_save($account, $form_state['values'], $category);

  // Clear the page cache because pages can contain usernames and/or profile information:
  cache_clear_all();

  drupal_set_message(t('The changes have been saved.'));
  return;
}

/**
 * custom profile validation function
 */
function profile_setup_user_invoke($type, &$array, &$user, $category = NULL, $exclude = array()) {
  if ($category == 'account') {
    _user_edit_validate($user->uid, $array); //invoke user module separately
  }
  foreach (module_list() as $module) {
    if (!in_array($module, $exclude)) {
	  $function = $module .'_user';
      if (function_exists($function)) {
        $function($type, $array, $user, $category);
      }
	}
  }
}
 