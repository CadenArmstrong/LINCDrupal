<?php

/**
 * @file rules integration for the linc module 
 *
 * @addtogroup rules
 * 
 */

/**
 * Implements hook_rules_category_info() on behalf of the linc module 
 */
function rules_linc_category_info() {
  return array(
    'linc' => array(
      'label' => t('linc'),
      'equals group' => t('linc'),
    ),
  );
}


/**
 * Implements hook_rules_action_info() on behalf of the node module.
 */
function linc_rules_action_info() {
	$return['remove_related'] = array(
			'label' => t('Remove all relations'),
			'group' => t('linc'),
			'base' => 'linc_rules_action_remove_related',
			'parameter' => array(
				'node' => array(
					'type' => 'entity',
					'label' => t('Entity'),
					'description' => t('Remove all relations containing this entity.'),
				),
				'relationtype' => array(
					'type' => 'text',
					'label' => t('Relation type'),
					'description' => t('Machine name of relation type to remove entity from.'),
					'options list' => 'relation_type_options',
					'restriction' => 'input',
				),
			),
			'provides' => array(
				'test_message' => array(
					'type' => 'text',
					'label' => t('Test message'),
				),
			),
	);

	return $return;
}

function relation_type_options() {
	$options = array();
	$options['incage'] = t('incage');
	$options['hasparent'] = t('hasparent');
	$options['hasprotocol'] = t('hasprotocol');

	return $options;

}

/**
 * $entity -> The source entity to remove all related of
 * $string -> The type of relation to check for
 *
 */
function linc_rules_action_remove_related($entity,$string) {
// TODO

	$results = relation_query($entity->type(), $entity->getIdentifier())
	  ->entityCondition('bundle', $string)
	  ->range(0,50)
	  ->execute();

	$message = '';

	foreach ( $results as $result_key => $result_value) {
		$message .= (string)$result_value->relation_type;
		if((string)$result_value->relation_type == $string){
			relation_delete($result_key);
		}
	}

	return array(
		'test_message' => $message, 
	);
}

/**
 * @}
 */
