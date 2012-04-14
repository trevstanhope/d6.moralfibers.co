<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function artist_page_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'artist';
  $context->description = '';
  $context->tag = 'Nodes';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'artist' => 'artist',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-designs_by_artist-block_1' => array(
          'module' => 'views',
          'delta' => 'designs_by_artist-block_1',
          'region' => 'content_bottom',
          'weight' => 0,
        ),
        'views-random_listing-block_1' => array(
          'module' => 'views',
          'delta' => 'random_listing-block_1',
          'region' => 'content_bottom',
          'weight' => 1,
        ),
        'views-artist_art_design-block_1' => array(
          'module' => 'views',
          'delta' => 'artist_art_design-block_1',
          'region' => 'artist_art_design',
          'weight' => 0,
        ),
        'views-photo_gallery-block_1' => array(
          'module' => 'views',
          'delta' => 'photo_gallery-block_1',
          'region' => 'artist_photo_gallery',
          'weight' => 0,
        ),
        'block-13' => array(
          'module' => 'block',
          'delta' => 13,
          'region' => 'artist_video',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Nodes');
  $export['artist'] = $context;

  return $export;
}
