<?php
// $Id$

/**
 * @file
 * Contains callbacks for administering UC Limited Time Offer. Only those with the
 * 'access store' permission can access these pages.
 *
 * @ingroup uc_lto
 */

/**
 * Show the administration form. drupal_get_form() callback.
 */
function uc_lto_settings_form() {

  return system_settings_form(array(
      'uc_lto_date_display_fieldset' => array(
        '#type' => 'fieldset', 
        '#title' => t('Date and Time Display Settings'),
        '#weight' => -15,
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        'uc_lto_time_gran' => array(
          '#type' => 'select',
          '#title' => t('Time interval granularity'),
          '#options' => array(
            '1' => '1',
            '2' => '2',
            '3' => '3',
            '4' => '4',
            '5' => '5',
            '6' => '6',
          ),
          '#description' => t('How specific should the time intervals be? The N largest units of time will be displayed. For example, if an interval of five days, four hours, three minutes and two seconds is to be represented, selecting &ldquo;1&rdquo; will cause &ldquo;5 days&rdquo; to be shown, whereas selecting &ldquo;3&rdquo; will cause &ldquo;5 days 4 hours 3 mins&rdquo; to be shown.'),
          '#default_value' => variable_get('uc_lto_time_gran', '2'),
          '#weight' => -12,
        ),
        'uc_lto_time_format' => array(
          '#type' => 'textfield',
          '#title' => t('Date format for LTO products displaying the time of expiration'),
          '#description' => t('Specify the <a href="http://us.php.net/manual/en/function.date.php" target="_blank">PHP date format</a> for LTO products displaying the time of expiration (vs. time remaining).  If left blank, the default will be used (example: May 14, 2010 at 9:05 am).'),
          '#default_value' => variable_get('uc_lto_time_format', 'M d, Y \a\t g:i a'),
          '#weight' => -10,
        ),
      ),
      'uc_lto_js_fieldset' => array(
        '#type' => 'fieldset', 
        '#title' => t('Active Timer Javascript Settings'),
        '#weight' => -9,
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        '#description' => t('These settings pertain to products being displayed with an active countdown.  It is not necessary to make any changes here in order to use the active countdown functionality.  However, the settings are available to help faciliate customization of the active countdown.  For example, the default active countdown uses words for hours, minutes, and seconds.  If you wanted to display with colons (00:00:00), you could customize the JS file and place it in your theme without having to alter module files.'),
        'uc_lto_js_style' => array(
          '#type' => 'select',
          '#title' => t('JS Style'),
          '#options' => array(
            '1' => 'Default',
            '2' => 'Custom',
          ),
          '#description' => t('This a select box in order to allow for potential additional default styles in the future.  This setting pertains to the way the timer is displayed on products with an active countdown.  If you choose custom, specify the JS file in your theme in the field below.  <b>Recommended for customization</b>: copy the uc_lto.js file to your theme and then customize the display from that file.'),
          '#default_value' => variable_get('uc_lto_js_style', '1'),
          '#weight' => -8,
        ),
        'uc_lto_js_custom_path' => array(
          '#type' => 'textfield',
          '#title' => t('JS Style'),
          '#description' => t('Path to the custom JS file inside your active theme - <b>only put the path and filename within your theme</b>, not the path to your theme.  For example, if your customized JS file is called mycustom.js and you have it in the main folder of your theme you would simply put mycustom.js in the textfield.  If you place it in a JS folder in your theme, you would enter js/mycustom.js.  The field here pertains to the functionality in the uc_lto.js file.  There is also a timer js file, but this is not likely the one you would want to customize in most cases.'),
          '#default_value' => variable_get('uc_lto_js_custom_path', 'js/uc_lto.js'),
          '#weight' => -6,
        ),
      ),
      'uc_lto_text_labels_fieldset' => array(
        '#type' => 'fieldset', 
        '#title' => t('Display Labels Settings'),
        '#weight' => -5,
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        '#description' => t('These settings pertain to products being displayed with an active countdown.  It is not necessary to make any changes here in order to use the active countdown functionality.  However, the settings are available to help faciliate customization of the active countdown.  For example, the default active countdown uses words for hours, minutes, and seconds.  If you wanted to display with colons (00:00:00), you could customize the JS file and place it in your theme without having to alter module files.'),
        'uc_lto_expires_on_text' => array(
          '#type' => 'textfield',
          '#title' => t('Expires on label'),
         '#description' => t('Label for LTO products displaying time of expiration, such as "Expires on" - include a colon if you wish to have that displayed.'),
          '#default_value' => variable_get('uc_lto_expires_on_text', 'Expires on:'),
          '#weight' => -4,
        ),
        'uc_lto_expires_in_text' => array(
          '#type' => 'textfield',
          '#title' => t('Time left label'),
          '#description' => t('Label for LTO products displaying time remaining (i.e. expiration minus current time), such as "Expires in" or "Time left" - include a colon if you wish to have that displayed.'),
          '#default_value' => variable_get('uc_lto_expires_in_text', 'Expires in:'),
          '#weight' => -2,
        ),
      ),




  ));
}