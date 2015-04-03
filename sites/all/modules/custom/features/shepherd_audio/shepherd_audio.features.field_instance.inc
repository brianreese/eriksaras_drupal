<?php
/**
 * @file
 * shepherd_audio.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function shepherd_audio_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-audio_recording-field_media_upload'
  $field_instances['node-audio_recording-field_media_upload'] = array(
    'bundle' => 'audio_recording',
    'deleted' => 0,
    'description' => 'Upload an audio file',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'soundmanager2',
        'settings' => array(
          'audio_type' => 'default',
          'pause' => 'pause',
          'stream' => FALSE,
          'text' => 'filename',
        ),
        'type' => 'soundmanager2_page_player',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_media_upload',
    'label' => 'media upload',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'mp3 mp4 mpg aac ac3 wma wav ogg mp2',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
        'allowed_types' => array(
          0 => 'image',
        ),
        'progress_indicator' => 'bar',
      ),
      'type' => 'media_generic',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-audio_recording-field_recording_date'
  $field_instances['node-audio_recording-field_recording_date'] = array(
    'bundle' => 'audio_recording',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_recording_date',
    'label' => 'Recording Date',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'Y-m-d H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-audio_recording-field_recording_venue'
  $field_instances['node-audio_recording-field_recording_venue'] = array(
    'bundle' => 'audio_recording',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Used to group and sort recordings for display.  Value can be a venue, a date, or any other label.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_recording_venue',
    'label' => 'Recording Venue/Label',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-audio_recording-field_track_order'
  $field_instances['node-audio_recording-field_track_order'] = array(
    'bundle' => 'audio_recording',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optionally, specify the order for uploaded tracks to display.  (lower numbers will appear first)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_track_order',
    'label' => 'Track order (weight)',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 35,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Optionally, specify the order for uploaded tracks to display.  (lower numbers will appear first)');
  t('Recording Date');
  t('Recording Venue/Label');
  t('Track order (weight)');
  t('Upload an audio file');
  t('Used to group and sort recordings for display.  Value can be a venue, a date, or any other label.');
  t('media upload');

  return $field_instances;
}
