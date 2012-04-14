<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function featured_artists_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'artists';
  $context->description = '';
  $context->tag = 'Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'artists' => 'artists',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mf_blocks-15' => array(
          'module' => 'mf_blocks',
          'delta' => 15,
          'region' => 'content_top',
          'weight' => 0,
        ),
        'views-artist_random_listing-block_1' => array(
          'module' => 'views',
          'delta' => 'artist_random_listing-block_1',
          'region' => 'content_bottom',
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
  t('Pages');
  $export['artists'] = $context;

  return $export;
}
