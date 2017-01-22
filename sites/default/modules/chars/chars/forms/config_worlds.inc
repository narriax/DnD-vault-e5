<?php

function chars_config_worlds_form ($form, &$form_state) {
	
	module_load_include('class', 'chars', 'api/CharWorld');
	$worlds = CharWorld::getWorlds();
	
	$form = array();
	
	// =======================================
	$form['new_world'] = array (
		'#type' => 'fieldset',
		'#title' => 'Add New World',
	);	
	$form['new_world']['new_world_name'] = array (
		'#type' => 'textfield',
		'#title' => 'Name',
		'#attributes' => array (
			'placeholder' => 'New World Name',
		),
	);
	$form['new_world']['btn_add_world'] = array (
		'#type' => 'submit',
		'#value' => 'Add',
		'#name' => 'add_world',
	);
	
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
			'#title' => $world -> name,
		);
	}
	
	return $form;
}


function chars_config_worlds_form_validate ($form, &$form_state) {
	$btn = strtolower($form_state['triggering_element']['#name']);
	
	switch ($btn) {
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
	}
	
}

function chars_config_worlds_form_submit ($form, &$form_state) {
	$btn = strtolower($form_state['triggering_element']['#name']);
	switch ($btn) {
		case 'add_world': 
			$name = $form_state['values']['new_world_name'];
			module_load_include('class', 'chars', 'api/CharWorld');
			CharWorld::addWorld($name);
	}	
}
