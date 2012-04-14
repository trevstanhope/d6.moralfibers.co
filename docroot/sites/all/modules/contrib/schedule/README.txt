********************************************************************
                     D R U P A L    M O D U L E
********************************************************************
Name: Schedule Module
Author: Robert Castelo
Drupal: 6.x
********************************************************************
DESCRIPTION:

Handles data, logic, and UI of schedule(s).

The schedule can be used for most purposes, and includes following
information:

Type: Type of service being scheduled - ties schedule to the module
using schedule.module.

Publication ID: The ID of the publication/event being scheduled

First: Time of first publication/event

Start: If content is to be included from before first publication/event,
when should content start being included.

Next: Time of next publication/event.

Last: Time of last publication/event.

Every: Schedule interval - month/day/hour/manual

Frequency: Unit value of interval, e.g. 1 (day)



This module provides an API, don't install it unless required by another module.



********************************************************************
INSTALLATION:

Note: It is assumed that you have Drupal up and running.  Be sure to
check the Drupal web site if you need assistance.  If you run into
problems, you should always read the INSTALL.txt that comes with the
Drupal package and read the online documentation.

1. Place the entire publication directory into your Drupal modules/
   directory.

2. Enable the publication module by navigating to:

     administer > build > modules
     
  Click the 'Save configuration' button at the bottom to commit your
  changes.


********************************************************************
AUTHOR CONTACT

- Report Bugs/Request Features:
   http://drupal.org/project/schedule
   
- Comission New Features:
   http://www.codepositive.com/contact
   
- Want To Say Thank You:
   http://www.amazon.com/gp/registry/O6JKRQEQ774F




********************************************************************
ACKNOWLEDGEMENT

Developed by Robert Castelo for Code Positive <http://www.codepositive.com>







