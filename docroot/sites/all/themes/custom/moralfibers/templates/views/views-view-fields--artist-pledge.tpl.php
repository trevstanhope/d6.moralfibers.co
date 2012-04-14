<?php
// $Id: views-view-fields.tpl.php,v 1.6 2008/09/24 22:48:21 merlinofchaos Exp $
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->separator: an optional separator that may appear before a field.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
  <?php
	$raw_cost = $fields['sell_price']->raw;
	$cost = $fields['sell_price']->content;
	$number = $fields['field_tshirt_sold_value']->raw;
	$subtotal = $raw_cost * $number;
	$total = '$' . number_format($subtotal, 2, '.', '')
  ?>
<?php print $fields['field_tshirt_images_fid']->content; ?>

<div class="pledge-top">
    <div><span class="total-raised"><?php print $total; ?></span><span class="raised-text"> Raised</span></div>
    <div><span class="pledge-count"><?php if (empty($number)) { print '0'; } else { print $number; } ?></span><span class="pledge-text"> Pledges</span></div>
</div>
	<?php print $cost ?>
	<?php print $fields['buyitnowbutton']->content; ?>