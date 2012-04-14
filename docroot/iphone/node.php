<?php

chdir("/var/www/www.moralfibers.co/docroot/");
require_once("./includes/bootstrap.inc");
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// Check to ensure that the get value is set
if (isset($_GET['nid'])) {
  $return = node_load($_GET['nid']);
  echo json_encode($return);
} elseif (isset($_GET['title'])) {
  $title = $_GET['title'];
  $nid = db_result(db_query('SELECT nid FROM {node} WHERE title = %d', $title));
  
  $return = node_load($nid);
  echo json_encode($return);
}

?>
