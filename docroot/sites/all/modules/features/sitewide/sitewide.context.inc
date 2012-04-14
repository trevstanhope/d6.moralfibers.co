<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function sitewide_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = '';
  $context->tag = 'general';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mf_blocks-3' => array(
          'module' => 'mf_blocks',
          'delta' => 3,
          'region' => 'top_right',
          'weight' => 0,
        ),
        'mf_blocks-5' => array(
          'module' => 'mf_blocks',
          'delta' => 5,
          'region' => 'top_right',
          'weight' => 1,
        ),
        'mf_blocks-4' => array(
          'module' => 'mf_blocks',
          'delta' => 4,
          'region' => 'top_right',
          'weight' => 2,
        ),
        'block-11' => array(
          'module' => 'block',
          'delta' => 11,
          'region' => 'customer_service',
          'weight' => 0,
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => 1,
          'region' => 'newsletter',
          'weight' => 0,
        ),
        'mf_blocks-7' => array(
          'module' => 'mf_blocks',
          'delta' => 7,
          'region' => 'share',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('general');
  $export['sitewide'] = $context;

  return $export;
}
