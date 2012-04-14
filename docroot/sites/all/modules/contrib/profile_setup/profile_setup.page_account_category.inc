<?php
// $Id: profile_setup.page_account_category.inc,v 1.1.2.1.4.5 2009/10/12 21:08:42 thomjjames Exp $

/**
 * @file
 * Page user edit type
 */

include_once(drupal_get_path('module', 'pageroute') .'/pageroute.route.inc');

class profilesetupPageaccount_category extends PageroutePage {

  public function getForm(&$form, &$form_state, &$args) {
    $form = array();
    if ($args && isset($args['uid'])) {
      $account = user_load(array('uid' => $args['uid']));
    }
    else {
      $account = user_load(array('uid' => pageroute_page_get_uid($this, 'administer users')));
    }
	
    if (user_edit_access($account)) {
      if (!$account->uid) {
        drupal_not_found();
        pageroute_exit_now();
      }
      
      $args['hide_pageroute_buttons'] = FALSE;
      $args['default_target'] = PAGEROUTE_FORWARD;

      $this->options += array(
        'category' => 'account'
      );
           
      $form['description'] = array(
        '#value' => $this->options['description'],
        '#weight' => -100
      );
	  $form['account_category'] = array(
	    '#value' => $this->options['category']
	  );
	  
	  //option to use content profile user categories too
	  if (profile_setup_page_is_content_profile_type($this->options['category'])) {
	    $type = $this->options['category'];
		$node = content_profile_load($type, $account->uid);
        if (!$node) {
          $node = array('uid' => $account->uid, 'name' => (isset($account->name) ? $account->name : ''), 'type' => $type, 'language' => '');
        }
        $form += drupal_retrieve_form($type .'_node_form', $form_state, $node);
		drupal_prepare_form($type .'_node_form', $form, $form_state);
	  }
	  else {
	    $form += drupal_retrieve_form('user_profile_form', $form_state, $account, $this->options['category']); 
        drupal_prepare_form('user_profile_form', $form, $form_state);
	  }
	  
      $this->unsetForm($form);
    }
    else {
      drupal_access_denied();
      pageroute_exit_now();
    }
  }

  public function getAdminForm($page, &$form) {
    $categories = array();
    foreach (_user_categories(false) as $category) {
      $categories[$category['name']] = $category['title'];
    }
    $form['options']['category'] = array(
      '#type' => 'select',
      '#title' => t('Category'),
      '#description' => t('The form of the chosen category will be used for this page.'),
      '#required' => TRUE,
      '#default_value' => isset($page->options['category']) ? $page->options['category'] : '',
      '#weight' => 2,
      '#options' => $categories,
    );
    $form['options']['description'] = array(
	  '#type' => 'textarea',
      '#title' => t('Form description'),
      '#default_value' => $page->options['description'],
      '#description' => t('You can optionally input a description or message that will appear at the top of this form.')
    );
  }

  public static function help() {
    $help[] = t('This page type is provided by the profile_setup module to allow users to edit their profile "edit" categories which can be created using the profile or content profile modules.');
    $help[] = t('<strong>Using Content Profile Module:</strong> If you are using Content Profile you much select <em>Show a secondary tab below the user\'s edit tab</em> under <em>Profile edit tab</em> in the content profile content type tab per content type.');
    $help[] = t('<strong>Using Profile Module:</strong> If you are using core Profile account categories are automatically created as you create profile fields.');
    return implode('<br />', $help);
  }

  public static function info() {
    return array('name' => t('User account editing form'));
  }
  
  public function unsetForm(&$form) {
	if (profile_setup_page_is_content_profile_type($this->options['category'])) {
      unset($form['buttons']['delete'], $form['buttons']['submit'], $form['buttons']['preview']);
	}
	else {
	  unset($form['delete'], $form['submit']);
	}
  }  

  public function formSubmitted(&$form_state) {

  }

  public function setUp() {
    include_once(drupal_get_path('module', 'node') .'/node.pages.inc');
    include_once(drupal_get_path('module', 'user') .'/user.pages.inc');
	include_once(drupal_get_path('module', 'profile_setup') .'/profile_setup.admin.inc');
  }
  
  public static function getDefaultValidateHandler($form) {
	if (profile_setup_page_is_content_profile_type($form['account_category']['#value'])) {
	  return 'node_form_validate';
	}
	else {
	  return 'user_profile_form_validate';
	}
  }
 
  public static function getDefaultSubmitHandler($form) {
	if (profile_setup_page_is_content_profile_type($form['account_category']['#value'])) {
	  return 'node_form_submit';
	}
	else {
	  return 'user_profile_form_submit';
	}
  }    
}