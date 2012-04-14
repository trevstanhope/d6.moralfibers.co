<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function splash_pages_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'splash';
  $context->description = '';
  $context->tag = 'Splash';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'splash/*' => 'splash/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-15' => array(
          'module' => 'block',
          'delta' => 15,
          'region' => 'content_top',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Splash');
  $export['splash'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'splash_artists';
  $context->description = '';
  $context->tag = 'Splash';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'splash/artists' => 'splash/artists',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mf_blocks-22' => array(
          'module' => 'mf_blocks',
          'delta' => 22,
          'region' => 'content_top',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Splash');
  $export['splash_artists'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'splash_ethical';
  $context->description = '';
  $context->tag = 'Splash';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'splash/ethical' => 'splash/ethical',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mf_blocks-23' => array(
          'module' => 'mf_blocks',
          'delta' => 23,
          'region' => 'content_top',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Splash');
  $export['splash_ethical'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'splash_fashion';
  $context->description = '';
  $context->tag = 'Splash';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'splash/fashion' => 'splash/fashion',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mf_blocks-24' => array(
          'module' => 'mf_blocks',
          'delta' => 24,
          'region' => 'content_top',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Splash');
  $export['splash_fashion'] = $context;

  return $export;
}
