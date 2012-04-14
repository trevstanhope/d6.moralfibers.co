
Module: Google Analytics eCommerce
Author: Nacho Montoya <http://drupal.org/user/64182>


Description
===========
Adds Google Analytics ecommerce tracking system to your website.

Requirements
============

* Google Analytics user account
* Google Analytics module <http://drupal.org/project/google_analytics>

Installation
============

* Copy the 'google_analytics_ecommerce' module directory in to your Drupal
sites/all/modules directory as usual.

Usage
=====

Configure Google analytics ecommerce tracking for any content type. 
Go to the content type settings page, and a fieldset named Google 
Analytics eCommerce will allow you to enable ecommerce tracking for
those node types.

By default, tracking is done in node creation (inserts) but you can 
also configure tracking for node updates.

This module is integrated with cck and taxonomy modules, so you can use
them to fill dinamically most of the arguments of the transaction.
