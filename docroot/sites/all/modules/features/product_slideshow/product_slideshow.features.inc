<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function product_slideshow_imagecache_default_presets() {
  $items = array(
    'product_page_slideshow' => array(
      'presetname' => 'product_page_slideshow',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '632px',
            'height' => '460px',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function product_slideshow_views_api() {
  return array(
    'api' => '2',
  );
}
