<?php
/**
 * @file
 * Provides infrequently used functions for jquery_countdown_block.
 */

/**
 * Form builder for the countdown block deletion form.
 */
function jquery_countdown_block_delete(&$form_state, $delta = 0) {
  $title = variable_get("jquery_countdown_block_{$delta}_admin_title", 'Countdown Block ' . $delta);
  $form['block_title'] = array('#type' => 'value', '#value' => $title);
  $form['delta'] = array('#type' => 'value', '#value' => $delta);

  return confirm_form($form, t('Are you sure you want to delete the "%name" block?', array('%name' => $title)), 'admin/build/block', NULL, t('Delete'), t('Cancel'));
}

/**
 * Form submission handler for jquery_countdown_block_delete().
 */
function jquery_countdown_block_delete_submit($form, &$form_state) {
  // Remove the menu block configuration variables.
  $delta = $form_state['values']['delta'];
  $block_ids = variable_get('jquery_countdown_block_ids', array());
  
  unset($block_ids[array_search($delta, $block_ids)]);
  sort($block_ids);
  
  variable_set('jquery_countdown_block_ids', $block_ids);
  variable_del("jquery_countdown_block_{$delta}_admin_title");
  variable_del("jquery_countdown_block_{$delta}_date");
  variable_del("jquery_countdown_block_{$delta}_format");
  variable_del("jquery_countdown_block_{$delta}_until");
  variable_del("jquery_countdown_block_{$delta}_caption");
  variable_del("jquery_countdown_block_{$delta}_serversync");

  db_query("DELETE FROM {blocks} WHERE module = 'jquery_countdown_block' AND delta = %d", $delta);
  db_query("DELETE FROM {blocks_roles} WHERE module = 'jquery_countdown_block' AND delta = %d", $delta);
  
  drupal_set_message(t('The "%name" block has been deleted.', array('%name' => $form_state['values']['block_title'])));
  cache_clear_all();
  $form_state['redirect'] = 'admin/build/block';
  return;
}

/**
 * Returns the 'list' $op info for hook_block().
 */
function _jquery_countdown_block_block_list() {
  $blocks = array();
  foreach (variable_get('jquery_countdown_block_ids', array()) as $delta) {
    $title = variable_get("jquery_countdown_block_{$delta}_admin_title", 'Countdown Block ' . $delta);
    $blocks[$delta]['info'] = $title;
    $blocks[$delta]['cache'] = BLOCK_CACHE_GLOBAL;
  }
  return $blocks;
}

/**
 * Returns the 'configure' $op info for hook_block().
 */
function _jquery_countdown_block_block_configure($delta) {
  $form['admin_title'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get("jquery_countdown_block_{$delta}_admin_title", NULL),
    '#title' => t('Administrative title'),
    '#description' => t('This title will be used administratively to identify this block. If blank, a default title will be used.'),
  );

  $datetype = module_exists('date_popup') ? 'date_popup' : 'date_select';
  $form['date'] = array(
    '#type' => $datetype,
    '#title' => t('Countdown date'),
    '#required' => TRUE,
    '#default_value' => variable_get("jquery_countdown_block_{$delta}_date", NULL),
    '#date_format' => 'Y-m-d g:i a',
  );
  
  $form['until'] = array(
    '#type' => 'radios',
    '#title' => t('Counter type'),
    '#required' => TRUE,
    '#options' => array(
      'until' => 'Count down to date',
      'since' => 'Count up since date',
    ),
    '#default_value' => variable_get("jquery_countdown_block_{$delta}_until", NULL),
    '#description' => t('Whether the counter should count down to a date in the future or up from a date in the past.'),
  );
  
  $form['serversync'] = array(
    '#type' => 'checkbox',
    '#title' => t('use servertime'),
    '#description' => t('if checked the countdown uses the servertime instead of the client time as base time'),
    '#default_value' => variable_get("jquery_countdown_block_{$delta}_serversync", FALSE),
  );
  
  $form['format'] = array(
    '#type' => 'select',
    '#title' => t('Granularity'),
    '#required' => TRUE,
    '#multiple' => TRUE,
    '#options' => array('Y' => 'Years', 'O' => 'Months', 'W' => 'Weeks', 'D' => 'Days', 'H' => 'Hours', 'M' => 'Minutes', 'S' => 'Seconds'),
    '#default_value' => variable_get("jquery_countdown_block_{$delta}_format", array('D', 'H', 'M', 'S')),
    '#description' => t('Which elements of the time to show. Default value is Days, Hours, Minutes, and Seconds.'),
  );
  $form['caption'] = array(
    '#type' => 'textarea',
    '#title' => t('Counter description'),
    '#default_value' => variable_get("jquery_countdown_block_{$delta}_caption", NULL),
    '#description' => t('This text is shown beneath the counter.'),
  );
  return $form;
}

/**
 * Returns the 'save' $op info for hook_block().
 */
function _jquery_countdown_block_block_save($delta, $edit) {
  if ($edit['admin_title']) {
    variable_set("jquery_countdown_block_{$delta}_admin_title", $edit['admin_title']);
  }
  else {
    variable_del("jquery_countdown_block_{$delta}_admin_title");
  }
  variable_set("jquery_countdown_block_{$delta}_caption", $edit['caption']);
  variable_set("jquery_countdown_block_{$delta}_date", $edit['date']);
  variable_set("jquery_countdown_block_{$delta}_until", $edit['until']);
  variable_set("jquery_countdown_block_{$delta}_format", $edit['format']);
  variable_set("jquery_countdown_block_{$delta}_serversync", $edit['serversync']);

}

