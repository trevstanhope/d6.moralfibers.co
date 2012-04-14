<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function featured_artists_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Implementation of hook_views_api().
 */
function featured_artists_views_api() {
  return array(
    'api' => '2',
  );
}
