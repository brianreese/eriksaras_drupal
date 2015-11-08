<?php
/**
 * @file
 * shepherd_audio.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function shepherd_audio_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'media_audio_';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Media (audio)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'audio-recordings recordings';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_recording_venue',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Recording Venue/Label */
  $handler->display->display_options['fields']['field_recording_venue']['id'] = 'field_recording_venue';
  $handler->display->display_options['fields']['field_recording_venue']['table'] = 'field_data_field_recording_venue';
  $handler->display->display_options['fields']['field_recording_venue']['field'] = 'field_recording_venue';
  $handler->display->display_options['fields']['field_recording_venue']['label'] = '';
  $handler->display->display_options['fields']['field_recording_venue']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_recording_venue']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_recording_venue']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: media upload */
  $handler->display->display_options['fields']['field_media_upload']['id'] = 'field_media_upload';
  $handler->display->display_options['fields']['field_media_upload']['table'] = 'field_data_field_media_upload';
  $handler->display->display_options['fields']['field_media_upload']['field'] = 'field_media_upload';
  $handler->display->display_options['fields']['field_media_upload']['label'] = '';
  $handler->display->display_options['fields']['field_media_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_media_upload']['type'] = 'soundmanager2_inline_player';
  $handler->display->display_options['fields']['field_media_upload']['settings'] = array(
    'pause' => 'pause',
    'text' => 'title',
  );
  /* Field: Content: Recording Date */
  $handler->display->display_options['fields']['field_recording_date']['id'] = 'field_recording_date';
  $handler->display->display_options['fields']['field_recording_date']['table'] = 'field_data_field_recording_date';
  $handler->display->display_options['fields']['field_recording_date']['field'] = 'field_recording_date';
  $handler->display->display_options['fields']['field_recording_date']['label'] = '';
  $handler->display->display_options['fields']['field_recording_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_recording_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_recording_date']['alter']['text'] = '[field_recording_date] - [field_recording_venue]';
  $handler->display->display_options['fields']['field_recording_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_recording_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Track order (weight) (field_track_order) */
  $handler->display->display_options['sorts']['field_track_order_value']['id'] = 'field_track_order_value';
  $handler->display->display_options['sorts']['field_track_order_value']['table'] = 'field_data_field_track_order';
  $handler->display->display_options['sorts']['field_track_order_value']['field'] = 'field_track_order_value';
  /* Sort criterion: Content: Recording Date (field_recording_date) */
  $handler->display->display_options['sorts']['field_recording_date_value']['id'] = 'field_recording_date_value';
  $handler->display->display_options['sorts']['field_recording_date_value']['table'] = 'field_data_field_recording_date';
  $handler->display->display_options['sorts']['field_recording_date_value']['field'] = 'field_recording_date_value';
  $handler->display->display_options['sorts']['field_recording_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'audio_recording' => 'audio_recording',
  );

  /* Display: audio recordings */
  $handler = $view->new_display('block', 'audio recordings', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Audio Recordings';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['media_audio_'] = $view;

  return $export;
}
