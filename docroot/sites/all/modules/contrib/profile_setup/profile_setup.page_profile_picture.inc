<?php
// $Id: profile_setup.page_profile_picture.inc,v 1.1.2.1.4.2 2009/10/11 20:11:43 thomjjames Exp $

/**
 * @file
 * Page user picture upload type
 */

class profilesetupPageprofile_picture extends PageroutePage {  

  public function getForm(&$form, &$form_state, &$args) {
    if (!variable_get('user_pictures', 0)) {
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
	$form['picture'] = $user_form['picture'];
	$form['#attributes'] = array('enctype' => 'multipart/form-data');
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
    if (!variable_get('user_pictures', 0)) {
	  $message = t('User picture uploading is not enable in the <a href="@user-settings">User settings</a>.<br />Go to Admin > User management > <a href="@user-settings">User settings</a> to change this.', array('@user-settings' => url('admin/user/settings')));
	  drupal_set_message($message, 'error');
	}
	
	$form['options']['description'] = array(
     '#type' => 'textarea',
     '#title' => t('Form description'),
     '#default_value' => $page->options['description'],
     '#description' => t('You can optionally input a description or message for this form to help encourage users to fill it out.')
    );
  }

  public static function help() {
    $help[] = t('This page type is provided by the profile_setup module to allow you to create a profile setup workflow page where users can upload a profile picture.'); 
    $help[] = t('NOTE: Creating this page type will overide your picture support settings on the !user_admin page.', array('!user_admin' => l(t('user settings'), 'admin/user/settings')));
    return implode('<br />', $help);  
  }
  
  public static function info() {
    return array('name' => t('User profile picture upload form'));
  }
  
  public static function form_submitted(&$form_state) {

  }
  
  public function setUp() {
    include_once(drupal_get_path('module', 'profile_setup') .'/profile_setup.admin.inc');
  }
  
  public static function getDefaultSubmitHandler($form) { 
    return 'profile_setup_picture_form_submit';
  }
}