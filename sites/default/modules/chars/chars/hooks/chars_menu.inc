<?php

function chars_menu() {
  $items = array();
  
  $items['chars'] = array (
    'title' => t('Characters'),
	'page callback' => 'chars_pages_content',
	'page arguments' => array('char_list'),
	'access callback' => true,
	'menu_name' => 'main-menu',
    'type' => MENU_NORMAL_ITEM,
	// 'weight' => 10,
  );
  $items['chars/add_new'] = array (
    'title' => t('Add New Character'),
	'page callback' => 'chars_pages_content',
	'page arguments' => array('char_add_new'),
	'access callback' => true,
	'menu_name' => 'main-menu',
    'type' => MENU_NORMAL_ITEM,
	// 'weight' => 10,  
  );
  
  
 
  // administration settings pages & forms
  $items['admin/config/chars'] = array(
    'title' => 'Chars',
    'description' => 'Set variables for Chars modules',
    
    'position' => 'left',
    'weight' => -100,
    'page callback' => 'system_admin_menu_block_page',
    'access arguments' => array('administer site configuration'),
    'file' => 'system.admin.inc',
    'file path' => drupal_get_path('module', 'system'),
  );
  $items['admin/config/chars/worlds'] = array(
    'title' => 'Worlds',
    'description' => 'Create and filter Char Worlds',
    'page callback' => 'chars_pages_content',
	'page arguments' => array ('config_worlds'),
    'access arguments' => array('administer site configuration'),
    'type' => MENU_NORMAL_ITEM,
    'weight' => 0,
  );
  return $items;
  
}


function chars_pages_content ($page = '') {
	switch ($page) {
	  case 'config_worlds':
	    module_load_include ('inc', 'chars', 'forms/config_worlds'); 
		$form = drupal_get_form('chars_config_worlds_form');
		return drupal_render($form);
		
	  case 'char_list':
		module_load_include ('inc', 'chars', 'pages/char_list'); 
		return chars_pages__char_list();
	  case 'char_add_new':
		module_load_include ('inc', 'chars', 'pages/char_add_new'); 
		return chars_pages__char_add_new();
	
	  default:
	    return 'unknown page';
	}
}