<?php

chdir("/var/www/www.moralfibers.co/docroot");
require_once("includes/bootstrap.inc");
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

if (!isset($_GET['update'])) {
  if ($node->type == 'qr') {
    echo json_encode($node);
  } else {
    print t('The node you attempted to load is not a QR code');
  }
} elseif (isset($_GET['update'])) { 
  $author = $_GET['author'];
  $title = $_GET['qr'];

  // Get the uid of the new author to get passed into the node_save.
  $user = user_load(array('name' => check_plain($author)));
  $uid = $user->uid;
  // Get the node id based upon the title that's passed as a get value.
  $nid = db_result(db_query('SELECT nid FROM {node} WHERE title = %d', $title));

  $node = node_load($nid);
  $node->uid = $uid;
  if (isset($_GET['active'])) {
    $node->field_qr_active[0]['value'] = check_plain($_GET['active']);
  }  
  // Ensure the node is validated before saving it.
  $node = node_submit($node);
  if ($node->validated) {
    node_save($node);
  }

// If the update get variable isn't set, just say the node can't be loaded.
} else {
  print t('No available node can be loaded');
}

?>
