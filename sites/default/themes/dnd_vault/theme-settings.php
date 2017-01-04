<?php
/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function vrsim_dnd_form_system_theme_settings_alter(&$form, &$form_state) {

  $form['vrsim_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('VRSim DnD Theme'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['vrsim_settings']['color_main'] = array(
    '#type' => 'checkbox',
    '#title' => t('Color'),
    '#default_value' => theme_get_setting('color_main','vrsim_dnd'),
    '#description'   => t("Check this option to color."),
  );

}


