# LINCDrupal
Learning in Neural Circuits - A Drupal lab mouse management module

The purpose of this module is to extend the functionality of the Drupal 7 [Rules module](https://www.drupal.org/project/rules) for the purpose of building a lab mice management system.
The module acts as a plugin to the Rules module creating actions for tasks that are not implemented, but required for the purposed of the LINC project.

## Requirements
- [Rules module](https://www.drupal.org/project/rules)
- [Relations module](https://www.drupal.org/project/relation)
- Drupal 7

## Installation
Copy the `linc/` folder to `/drupal/path/sites/all/modules/`
Enable in drupal


## TODO
- Store cage history of mice

Possible history solutions
- Relations for past relations, such as `wasIncage`, or `hadProtocol`

## Functionality
- destroy all relations of a type, containing a specified entity
Used for removing an entity from other relations so that ex. a mouse isn't in multiple cages.
