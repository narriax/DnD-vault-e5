<?php

function chars_config_worlds_form ($form, &$form_state) {
	
	drupal_add_library('system', 'drupal.collapse');

	module_load_include('class', 'chars', 'api/CharWorld');
	$worlds = CharWorld::getWorlds();
	$universes = CharWorld::getUniverses();
	
	$form = array();
	
	// =======================================
	$form['new_universe'] = array (
		'#type' => 'fieldset',
		'#title' => 'World Universes',
		'#collapsible' => TRUE,
		'#collapsed' => TRUE, 
	);
	$form['new_universe']['new_universe_list'] = array (
		'#markup' => '<ol><li>'.implode ('</li><li>', $universes).'</li></ol>',
	);
	$form['new_universe']['new_universe_name'] = array (
		'#type' => 'textfield',
		'#title' => 'Add universe',
		'#attributes' => array (
			'placeholder' => 'New Universe Name',
		),
	);
	$form['new_universe']['btn_add_universe'] = array (
		'#type' => 'submit',
		'#value' => 'Add',
		'#name' => 'add_universe',
	);		
	
	if (count($universes) > 0) {
		$form['new_world'] = array (
			'#type' => 'fieldset',
			'#title' => 'Add New World',
			'#collapsible' => TRUE,
			'#collapsed' => TRUE, 			
		);	
		$form['new_world']['new_world_name'] = array (
			'#type' => 'textfield',
			'#title' => 'Name',
			'#attributes' => array (
				'placeholder' => 'New World Name',
			),
		);
		$form['new_world']['new_world_universe'] = array (
			'#type' => 'select',
			'#title' => 'Name',
			'#options' => $universes,
		);
		$form['new_world']['new_world_private'] = array (
			'#type' => 'checkbox',
			'#title' => 'Private',
		);		
		$form['new_world']['btn_add_world'] = array (
			'#type' => 'submit',
			'#value' => 'Add',
			'#name' => 'add_world',
		);
	}
	
	// =======================================
	$form['world_list'] = array (
		'#type' => 'fieldset',
		'#title' => 'Worlds',
	);
	if (count($worlds)<1) {
		$form['world_list']['msg'] = array (
			'#markup' => '<i>- no worlds found -</i>',
		);
	
	} else foreach ($worlds as $wid => $world) {
		$form['world_list'][$wid] = array (
			'#type' => 'fieldset',
			'#title' => $universes[$world->universe_id] .': '.$world->name,
			'#collapsible' => TRUE,
			'#collapsed' => TRUE, 	
		);
		$form['world_list'][$wid][$wid.'_name'] = array (
			'#type' => 'textfield',
			'#title' => 'Name',
			'#default_value' => $world->name,
		);
		$form['world_list'][$wid][$wid.'_universe'] = array (
			'#type' => 'select',
			'#title' => 'Universe',
			'#options' => $universes,
			'#default_value' => $world->universe_id,
		);		
		$form['world_list'][$wid][$wid.'_private'] = array (
			'#type' => 'checkbox',
			'#title' => 'Private',
			'#default_value' => $world->privte,
		);
		if ($world->privte) $form['world_list'][$wid][$wid.'_private']['#attributes']['checked'] = 'checked';
		$form['world_list'][$wid]['btn_'.$wid.'_save'] = array (
			'#type' => 'submit',
			'#value' => 'Save changes',
			'#name' => $wid.'_save',
		);
	}
	
	return $form;
}


function chars_config_worlds_form_validate ($form, &$form_state) {
	$btn = strtolower($form_state['triggering_element']['#name']);
	
	switch ($btn) {
		case 'add_universe':
			$name = $form_state['values']['new_universe_name'];
			if ($name === '') {
				form_set_error('new_universe_name', 'Name cannot be empty.');
				return false;
			}
			module_load_include('class', 'chars', 'api/CharWorld');
			if (CharWorld::universeExists($name)) {
				form_set_error('new_universe_name', 'A universe with that name already exists.');
				return false;				
			}
			break;
		
		case 'add_world': 
			$name = $form_state['values']['new_world_name'];
			if ($name === '') {
				form_set_error('new_world_name', 'Name cannot be empty.');
				return false;
			}
			module_load_include('class', 'chars', 'api/CharWorld');
			if (CharWorld::worldExists($name)) {
				form_set_error('new_world_name', 'A world with that name already exists.');
				return false;				
			}
			break;
	}
	
}

function chars_config_worlds_form_submit ($form, &$form_state) {
	$btn = strtolower($form_state['triggering_element']['#name']);
	switch ($btn) {
		case 'add_universe': 
			$name = $form_state['values']['new_universe_name'];
			module_load_include('class', 'chars', 'api/CharWorld');
			CharWorld::addUniverse($name);
			break;
		case 'add_world': 
			$name = $form_state['values']['new_world_name'];
			$universe_id = $form_state['values']['new_world_universe'];
			$private = $form_state['values']['new_world_private'];
			module_load_include('class', 'chars', 'api/CharWorld');
			CharWorld::addWorld($name, $universe_id, $private);
			break;
	}	
}
