<?php

/**
* Example usage: http://moralfibers.co/iphone/new_qr.php?qr=1345959&author=emilysowe
**/

chdir("/var/www/www.moralfibers.co/docroot");
require_once("includes/bootstrap.inc");
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// Create variables from get values for use below.
$qr = check_plain($_GET['qr']);
$author = check_plain($_GET['author']);

// Load the user based on the author value.
$user = user_load(array('name' => $author));      
$uid = $user->uid;

// Create the new node class and construct the array.
if (!empty($uid) && !empty($qr)) {
  $node = new stdClass();
  $node->title = $qr;
  $node->uid = $uid;
  $node->type = 'qr';
}
else {
  print t("Either the uid or qr code was empty. The node was not saved.");
}

// Validate and save the node. Don't submit unless valid.
$node = node_submit($node);
if ($node->validated) {
  node_save($node);
}

?>
