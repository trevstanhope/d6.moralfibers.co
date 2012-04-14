<?php
// $Id: qr_codes.admin.inc,v 1.1.2.3 2010/07/11 10:48:55 claudiucristea Exp $

/**
 * Settings callback for 'admin/settings/qr_codes' path.
 */
function qr_codes_settings() {
  $form = array();
  $options = module_invoke_all('qr_codes', 'list');

  if (count($options)) {
    $engine = variable_get('qr_codes_engine', 'qr_codes_google_chart:google_chart');

    $form['#submit'][] = '_qr_codes_submit';

    $form['qr_codes_engine'] = array(
      '#type' => 'select',
      '#title' => t('Select the QR encoding engine'),
      '#description' => '<p>'. t('Select which engine/API is used to generate QR Code images. The following options are available as enabled modules:') .'</p>'. theme('item_list', module_invoke_all('qr_codes', 'description')) .'<p>'. t('If your option is not in the list, you should enable the appropriate sub-module. Additionaly you can plug other engines/APIs by implementing <code>hook_qr_codes()</code> in your module.') .'</p>',
      '#options' => $options,
      '#default_value' => $engine,
    );

    $count = count(file_scan_directory(file_directory_path() .'/qr_codes', '\.png$'));
    $form['qr_codes_clear_cache'] = array(
      '#type' => 'fieldset',
      '#title' => $count ? t('Cache: @count files cached', array('@count' => $count)) : t('Cache: There are no files in cache'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
      '#description' => t('Once a QR Codes image is created, it\'s saved locally. Next time when the same QR Code is requested it will be served from the local directory. This will increase the performance. You can configure a cache lifetime or manually clear the cache by pressing button bellow.'),
    );

    $form['qr_codes_clear_cache']['qr_codes_cache_lifetime'] = array(
      '#type' => 'textfield',
      '#title' => t('Cache lifetime (in days)'),
      '#size' => 4,
      '#description' => t('Configure how long local files will remain cached. 0, or an empty value, means the cahce will never be cleared.'),
      '#element_validate' => array('_qr_codes_settings_validate'),
      '#default_value' => variable_get('qr_codes_cache_lifetime', 0),
    );
    $form['qr_codes_clear_cache']['clear'] = array(
      '#type' => 'submit',
      '#value' => t('Clear cache now!'),
      '#submit' => array('qr_codes_clear_cache'),
      '#disabled' => !$count,
    );

    return system_settings_form($form);
  }
  else {
    $form['warning'] = array(
      '#type' => 'markup',
      '#value' => '<p>'. t('No QR Codes encoder is enabled! You should enable at least one engine module. Those modules are placed under <code>sites/all/modules/qr_codes/engines</code> directory.') .'</p><p>'. t('Visit the <a href="!url">Modules</a> page to enable one or more engine modules. Alternatively you can implement additional engines in other modules using <code>hook_qr_codes()</code>.', array('!url' => '/admin/build/modules')) .'</p>',
    );
    return $form;
  }
}

/**
 * Page callback for 'admin/settings/qr_codes/<engine-id>' path.
 *
 * @param $form_state
 *   Associative FAPI array.
 * @param $module
 *   String containing the module name.
 * @param $engine_id
 *   String containing the engine ID.
 *
 * @return
 *  FAPI Array.
 */
function qr_codes_engine_settings($form_state, $module, $engine_id) {
  return system_settings_form(module_invoke($module, 'qr_codes', 'config', $engine_id));
}

/**
 * Clear local files cache.
 */
function qr_codes_clear_cache() {
  $count = count(file_scan_directory(file_directory_path() .'/qr_codes', '\.png$', array('.', '..', 'CVS', '.svn'), 'file_delete'));
  if ($count) {
    drupal_set_message(t('QR Codes local cache cleared. @count files have been deleted.', array('@count' => $count)));
  }
}

/**
 * Implement an additional submit callback to the settings form.
 */
function _qr_codes_submit($form, $form_state) {
  // Clear the cache when changing engines.
  if (variable_get('qr_codes_engine', 'qr_codes_google_chart:google_chart') != $form_state['values']['qr_codes_engine']) {
    qr_codes_clear_cache();
  }
}

/**
 * Implement an additional validation callback to the settings form.
 */
function _qr_codes_settings_validate($element, &$form_state) {
  if (!empty($element['#value'])) {
    $valid = TRUE;

    // Ensure the cache lifetime is a positive integer.
    if (ctype_digit($element['#value']) && $element['#value'] > 0) {
      if ((int) $element['#value'] != $element['#value']) {
        $valid = FALSE;
      }
    }
    else {
      $valid = FALSE;
    }

    if (!$valid) {
      form_set_error($element['#name'], t('The cache lifetime must be a positive integer.'));
    }
  }
}
