<?php
// $Id: profile_setup.page_username_change.inc,v 1.1.2.1.4.2 2009/10/11 20:11:43 thomjjames Exp $

/**
 * @file
 * Page user edit type
 */

//include_once(drupal_get_path('module', 'pageroute') .'/pageroute.page.inc');

class profilesetupPageusername_change extends PageroutePage {  

  public function getForm(&$form, &$form_state, &$args) {
    
	if (!user_access('change own username')) {
      drupal_access_denied();
      pageroute_exit_now();    
    }

    if ($args && isset($args['uid'])) {
      $account = user_load(array('uid' => $args['uid']));
    }
    else {
      $account = user_load(array('uid' => pageroute_page_get_uid($this, 'administer users')));
    }	
	
    $args['hide_pageroute_buttons'] = FALSE;
    $args['default_target'] = PAGEROUTE_FORWARD;
    
	$edit['name'] = $account->name;
	$user_form = user_edit_form($form_state, $account->uid, $edit); //use default 
	$form['account']['name'] = $user_form['account']['name'];
	
	$form['_account'] = array(//do i need this?
      '#type' => 'value',
      '#value' => $account,
    );
	
    $form['description'] = array(
      '#value' => $this->options['description'],
      '#weight' => -100
    );		
    return;
  }

  public function getAdminForm($page, &$form) {
    $form['options']['description'] = array(
      '#type' => 'textarea',
      '#title' => t('Form description'),
      '#default_value' => $page->options['description'],
      '#description' => t('You can optionally input a description or message for this form to help encourage users to fill it out.')
    );
  }

  public static function help() {
    $help[] = t('This page type is provided by the profile_setup module to allow users to change their username.'); 
    $help[] = t('NOTE: You will need to enable the "change own username" permission to allow users to use this form. !user_admin.', array('!user_admin' => l(t('View current permissions'), 'admin/user/permissions')));
    return implode('<br />', $help);  
  }
  
  public static function info() {
    return array('name' => t('Change username form'));
  }
  
  public function formSubmitted(&$form_state) {
    
  }
  
  public function setUp() {
    include_once(drupal_get_path('module', 'profile_setup') .'/profile_setup.admin.inc');
  }
  
  public static function getDefaultSubmitHandler($form) {
    return 'profile_setup_username_form_submit';
  }
  
  public static function getDefaultValidateHandler($form) { 
    return 'profile_setup_username_form_validate';
  }
}