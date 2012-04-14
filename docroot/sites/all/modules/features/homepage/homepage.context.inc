<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function homepage_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = '';
  $context->tag = 'Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => 3,
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'mf_blocks-10' => array(
          'module' => 'mf_blocks',
          'delta' => 10,
          'region' => 'sidebar_second',
          'weight' => 1,
        ),
        'mf_blocks-9' => array(
          'module' => 'mf_blocks',
          'delta' => 9,
          'region' => 'sidebar_second',
          'weight' => 2,
        ),
        'mf_blocks-11' => array(
          'module' => 'mf_blocks',
          'delta' => 11,
          'region' => 'sidebar_second',
          'weight' => 3,
        ),
        'mf_blocks-12' => array(
          'module' => 'mf_blocks',
          'delta' => 12,
          'region' => 'sidebar_second',
          'weight' => 4,
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => 5,
          'region' => 'content_top',
          'weight' => 0,
        ),
        'block-14' => array(
          'module' => 'block',
          'delta' => 14,
          'region' => 'header_image',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Pages');
  $export['front'] = $context;

  return $export;
}
