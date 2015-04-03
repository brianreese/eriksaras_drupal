<?php
/**
 * @file
 * shepherd_audio.features.inc
 */

/**
 * Implements hook_views_api().
 */
function shepherd_audio_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function shepherd_audio_node_info() {
  $items = array(
    'audio_recording' => array(
      'name' => t('Audio Recording'),
      'base' => 'node_content',
      'description' => t('Use this content type to add new Audio Recordings to the Media page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
