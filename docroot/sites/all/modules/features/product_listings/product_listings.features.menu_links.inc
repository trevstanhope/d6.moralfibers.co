<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function product_listings_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: primary-links:mens-shirts
  $menu_links['primary-links:mens-shirts'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'mens-shirts',
    'router_path' => 'mens-shirts',
    'link_title' => 'Men\'s',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: primary-links:womens-shirts
  $menu_links['primary-links:womens-shirts'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'womens-shirts',
    'router_path' => 'womens-shirts',
    'link_title' => 'Women\'s',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Men\'s');
  t('Women\'s');


  return $menu_links;
}
