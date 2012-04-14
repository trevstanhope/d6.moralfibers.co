<?php

/**
* Implementation of HOOK_preprocess_node().
*/
function moralfibers_preprocess_node(&$vars) {
  $vars['artist_art_design'] = theme('blocks', 'artist_art_design');
  $vars['artist_photo_gallery'] = theme('blocks', 'artist_photo_gallery');
  $vars['artist_video'] = theme('blocks', 'artist_video');
  $vars['tshirt_photos'] = theme('blocks', 'tshirt_photos');
}

/**
 * Implementation of HOOK_theme().
 */
function moralfibers_theme(&$existing, $type, $theme, $path) {
  $hooks = zen_theme($existing, $type, $theme, $path);
  
    return $hooks;
}
