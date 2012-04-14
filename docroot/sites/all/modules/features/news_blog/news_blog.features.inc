<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function news_blog_ctools_plugin_api() {
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
function news_blog_imagecache_default_presets() {
  $items = array(
    'news_blogs' => array(
      'presetname' => 'news_blogs',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '640px',
            'height' => '153px',
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
function news_blog_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog'),
      'module' => 'features',
      'description' => t('Add a blog post to the Moral Fibers blog'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Post'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function news_blog_views_api() {
  return array(
    'api' => '2',
  );
}
