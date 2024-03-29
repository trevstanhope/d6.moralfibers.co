<?php
// $Id$
/**
 * Implementation of hook_admin_settings() for configuring the module
 */
function google_adwords_admin_settings(&$form_state) {
  
  $form['conversion'] = array(
    '#type' => 'fieldset',
    '#title' => t('General Conversion settings'),
    '#collapsible' => FALSE,
  );
  
  $form['conversion']['google_adwords_conversion_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Conversion ID'),
    '#default_value' => variable_get('google_adwords_conversion_id', ''),
    '#size' => 15,
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['conversion']['google_adwords_conversion_language'] = array(
    '#type' => 'textfield',
    '#title' => t('Conversion Language'),
    '#default_value' => variable_get('google_adwords_conversion_language', 'en'),
    '#size' => 15,
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['conversion']['google_adwords_conversion_format'] = array(
    '#type' => 'select',
    '#title' => t('Conversion Format'),
    '#default_value' => variable_get('google_adwords_conversion_format', '2'),
    '#options' => _google_adwords_conversion_formats(),
    '#required' => TRUE,
  );
  $form['conversion']['google_adwords_conversion_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Conversion Color'),
    '#default_value' => variable_get('google_adwords_conversion_color', 'FFFFFF'),
    '#size' => 10,
    '#maxlength' => 10,
    '#required' => TRUE,
  );
  $form['conversion']['google_adwords_external_script'] = array(
    '#type' => 'textfield',
    '#title' => t('External JavaScript'),
    '#default_value' => variable_get('google_adwords_external_script', 'https://www.googleadservices.com/pagead/conversion.js'),
    '#size' => 80,
    '#maxlength' => 255,
    '#required' => TRUE,
  );
      // Render the role overview.
  $result = db_query('SELECT * FROM {role} ORDER BY name');

  $form['conversion']['roles'] = array(
        '#type' => 'fieldset',
        '#title' => t('User Role Tracking'),
        '#collapsible' => TRUE,
        '#description' => t('Define what user roles should be tracked.')
  );

  while ($role = db_fetch_object($result)) {
     // can't use empty spaces in varname
    $role_varname = $string = str_replace(' ', '_', $role->name);
    $form['conversion']['roles']["google_adwords_track_{$role_varname}"] = array(
      '#type' => 'checkbox',
      '#title' => t($role->name),
      '#default_value' => variable_get("google_adwords_track_{$role_varname}", FALSE),
    );
  }

  $form['conversion']['google_adwords_conversion_pages'] = array(
      '#type' => 'textarea',
      '#title' => t('Label | Pages'),
      '#default_value' => variable_get('google_adwords_conversion_pages', ''),
      '#description' => t("Enter one entry per line seperated with a '|', in the format: <em>label|path</em>. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );

  return system_settings_form($form);
  
}