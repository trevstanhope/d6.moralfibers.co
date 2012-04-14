$Id$

-- SUMMARY --

UC Limited Time Offer adds functionality to Ubercart to make a product available for a limited time in a variety of styles - time of expiration, time remaining, active countdown, and etc.


-- REQUIREMENTS --

Ubercart and Date Pop-up contributed modules.


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.


-- CONFIGURATION --

* Configure user permissions in Administer >> User management >> Permissions >>

  uc_lto module:

  - administer uc limited time offer

    Users in roles with the "administer uc limited time offer" permission will see the node template settings fieldset on node and content type forms.


* (Optional) Configure module settings under Store Administration >> Configure >> Limited time offer settings.

* (Optional) Configure Ubercart Product Field settings under Store Administration >> Configuration >> Product Settings >> Product Fields.

* (Optional) Set product class (product content type) defaults under the Content Type Administration pages.


-- HELP --

The modules comes with Help page content.  If you have activated the core Help module, you will find additional information in the Online Help section - /admin/help.  However, as the module help page can only be updated with new releases of the module, the following resources may be of use as sources of additional and/or updated information, as well as use cases and examples on how to use this module:

- UC Limited Time Offer Project Page on Drupal.org - http://drupal.org/project/uc_lto

- A Drupal.org Handbook Page may or may not yet be available.  Please check project page. 

- UC Limited Time Offer Page on WebNewCastle.com - http://webnewcastle.com/uc-limited-time-offer


-- FAQ --


Q: How do I use this module?

A: Little is required to use this module.  Additional settings will appear when you create a product that allows you to make it a "timed product".  That is, by checking the box under the Limited Time Offer settings fieldset and choosing a date, your product will automatically expire and become unavailable at the time you specified.  Your product is not unpublished.  It is still viewable.


Q: Why would I use this module?

A: You want a simple, easily managed way of marketing products through your Ubercart site by offering products for a limited period of time.


Q: How do I use this module?

A: Little is required to use this module. There are general settings you can configure pertaining to styles, text for labels, date format, time granularity, etc. - see Limited time offer settings at the bottom of this help page or find it under Store Administration >> Configure >> Limited time offer settings.

You can also specify default settings for each product class under applicable (product content types) the content types administration page. You can specify whether a product class (product content type) will be a Limited Time Offer by default and how it will be displayed. For products that are made a Limited Time Offer will automatically expire and become unabailable at the time specified. Your product is not unpublished by this module. It is still viewable on the site (in regards to what is done by this module).


Q: How can I customize this module?

A: Placement of the Limited Time Offer display can be controlled through the Ubercart Product Field settings: Store Administration >> Configuration >> Product Settings >> Product Fields. If you are printing elements separately in your node template (rather than the content variable), you can add the LTO element separately by printing (PHP): print ['uc_lto']['#value'];, enclosed in PHP tags. You can also use CSS to override or further customize the display. For products displaying time remaining, the div class changes depending on the time remaining. Themeable Output: The LTO form is also themeable by adding code to your theme's template.php file. Look for function theme_uc_lto_status in the uc_lto.module file and replace theme with the name of your active theme along with any customizations. So, for example, let's say you don't want to display a label with the time of expiration or time remaining - there are at least 4 ways you can do this:

    * You could simply hide it with CSS.
    * You could put in a space for the label in the LOT settings (blank will cause the default to be substituted).
    * You use the String Overrides module.
    * You could override the themeable output and exclude the label from being printed with the form - see above.


-- ADDITIONAL NOTES --

With the release of the module you currently have installed, the expiration of a product makes the add to cart button unavailable. It does not prevent a customer from checking out if the product has already been added to the shopping cart. Additional functionality and settings for this will likely be added in the next release as time permits.
Why would I use this module?

You want a simple, easily managed way of marketing products through your Ubercart site by offering products for a limited period of time.


-- CREDIT --

The initial code and development of this module was based on the excellent work in the UC Auction contributed module.  The javascript files, for example, are mostly similar to those provided in Ubercart Auction.  The approach of allowing content type default settings was based on previous development in the Custom Node Template module.


-- CONTACT --

Current maintainers:
* Matthew Winters (WebNewCastle) - http://drupal.org/user/449192


This project is sponsored/maintained by:
* WebNewCastle
  As "Builders of Your Next Home on the Web", WebNewCastle provides various Drupal 
  services including custom theme development, training, consulting, and site 
  development for projects ranging from simple business sites, to eCommerce, to 
  online community, and more.  Visit http://www.webnewcastle.com for more information.



