<?php
// $Id$

/**
 * @file
 * Help file for the UC_LTO
 *
 * @ingroup uc_lto
 */

$output = "<p>UC Limited Time Offer adds functionality to Ubercart to make a product available for a limited time 
                 in a variety of styles - time of expiration, time remaining, active countdown, and etc.</p>   
		 <p>This page has been created to provide help with using this module.  However, as this help page can
		  only be updated with new releases of the module, the following resources may be of use as sources of
		  additional and/or updated information, as well as use cases and examples on how to use this module:<ul>
		  <li><a href='http://drupal.org/project/uc_lto' target='_blank'> UC Limited Time Offer Project Page on Drupal.org</a></li>
		  <li>A Drupal.org Handbook Page may or may not yet be available.  Please check project page.</li> 
		  <li><a href='http://webnewcastle.com/uc-limited-time-offer' target='_blank'>UC Limited Time Offer Page on WebNewCastle.com</a></li></ul></p> 
		  <h2>How To Use</h2>
                  <p>Little is required to use this module.  There are general settings you can configure pertaining to styles,
                  text for labels, date format, time granularity, etc. - see Limited time offer settings at the bottom of
                  this help page or find it under Store Administration >> Configure >> Limited time offer settings.</p>
                  <p>You can also specify default settings for each product class under applicable (product content types)
                  the content types administration page.  You can specify whether a product class (product content type) will
                  be a Limited Time Offer by default and how it will be displayed.  For products that are made a Limited Time
                  Offer will automatically expire and become unabailable at the time specified.  Your product is not unpublished
                  by this module.  It is still viewable on the site (in regards to what is done by this module).</p>
		  <h2>Customization</h2>
                  <p>Placement of the Limited Time Offer display can be controlled through the Ubercart Product Field settings:
                  Store Administration >> Configuration >> Product Settings >> Product Fields.  If you are printing elements
                  separately in your node template (rather than the content variable), you can add the LTO element separately
                  by adding <code>&lt;?php print \$node->content['uc_lto']['#value']; ?></code>.
                  You can also use CSS to override or further customize the display.  For products displaying time remaining,
                  the div class changes depending on the time remaining.</p>  <p><b>Themeable Output</b>:  The LTO form is also themeable 
                  by adding code to your theme's template.php file.  Look for <code>function theme_uc_lto_status</code> in the
                  uc_lto.module file and replace <code>theme</code> with the name of your active theme along with any customizations.  
                  So, for example, let's say you don't want to display a label with the time of expiration or time remaining - there
                  are at least 4 ways you can do this:<ul>
                  <li>You could simply hide it with CSS.</li>
                  <li>You could put in a space for the label in the LTO settings (blank will cause the default to be substituted).</li>
                  <li>You use the String Overrides module.</li>
                  <li>You could override the themeable output and exclude the label from being printed with the form - see above.</li></ul></p>
		  <h2>Additional Notes</h2>
                  <p>With the release of the module you currently have installed, the expiration of a product makes the add to cart
                  button unavailable.  It does not necessarily prevent a customer from checking out if the product has already been added to
                  the shopping cart.  You can control the amount of time to allow items to be kept in the cart in the Ubercart settings.</p>
		  <h2>Why would I use this module?</h2>
                  <p>You want a simple, easily managed way of marketing products through your Ubercart site by offering 
                  products for a limited period of time.</p>";