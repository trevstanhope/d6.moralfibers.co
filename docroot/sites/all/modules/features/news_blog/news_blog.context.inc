<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function news_blog_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog';
  $context->description = '';
  $context->tag = 'Nodes';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'blog/*' => 'blog/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news_updates-block_1' => array(
          'module' => 'views',
          'delta' => 'news_updates-block_1',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'mf_blocks-9' => array(
          'module' => 'mf_blocks',
          'delta' => 9,
          'region' => 'sidebar_second',
          'weight' => 1,
        ),
        'mf_blocks-10' => array(
          'module' => 'mf_blocks',
          'delta' => 10,
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
      ),
    ),
    'menu' => 'news-updates',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Nodes');
  $export['blog'] = $context;

  return $export;
}
