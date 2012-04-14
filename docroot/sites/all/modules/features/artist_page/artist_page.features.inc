<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function artist_page_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function artist_page_imagecache_default_presets() {
  $items = array(
    'artist_art_design' => array(
      'presetname' => 'artist_art_design',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '68',
            'height' => '80',
          ),
        ),
      ),
    ),
    'artist_featured' => array(
      'presetname' => 'artist_featured',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '630',
            'height' => '272',
          ),
        ),
      ),
    ),
    'artist_page_thumbnail' => array(
      'presetname' => 'artist_page_thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '140',
            'height' => '140',
          ),
        ),
      ),
    ),
    'artist_photos' => array(
      'presetname' => 'artist_photos',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '153',
            'height' => '111',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function artist_page_node_info() {
  $items = array(
    'artist' => array(
      'name' => t('Artist'),
      'module' => 'features',
      'description' => t('An artist to be featured on Moral Fibers'),
      'has_title' => '1',
      'title_label' => t('Artist Name'),
      'has_body' => '1',
      'body_label' => t('Artist Bio'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function artist_page_views_api() {
  return array(
    'api' => '2',
  );
}
