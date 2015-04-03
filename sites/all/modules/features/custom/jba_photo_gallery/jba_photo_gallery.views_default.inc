<?php
/**
 * @file
 * jba_photo_gallery.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jba_photo_gallery_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'photo_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo Gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'gallery_filter_block:isotope_filter';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: gallery Photo */
  $handler->display->display_options['fields']['field_gallery_photo']['id'] = 'field_gallery_photo';
  $handler->display->display_options['fields']['field_gallery_photo']['table'] = 'field_data_field_gallery_photo';
  $handler->display->display_options['fields']['field_gallery_photo']['field'] = 'field_gallery_photo';
  $handler->display->display_options['fields']['field_gallery_photo']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_photo']['settings'] = array(
    'image_style' => 'photo_gallery',
    'image_link' => 'content',
  );
  /* Field: Content: gallery type */
  $handler->display->display_options['fields']['field_gallery_type']['id'] = 'field_gallery_type';
  $handler->display->display_options['fields']['field_gallery_type']['table'] = 'field_data_field_gallery_type';
  $handler->display->display_options['fields']['field_gallery_type']['field'] = 'field_gallery_type';
  $handler->display->display_options['fields']['field_gallery_type']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gallery_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_gallery_type']['delta_offset'] = '0';
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['element_type'] = 'div';
  $handler->display->display_options['fields']['term_node_tid']['element_class'] = 'isotope-filter';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['term_node_tid']['element_wrapper_class'] = 'isotope-filter';
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'photo_galleries' => 'photo_galleries',
    'event_type' => 0,
    'isotope_sort_options' => 0,
    'tags' => 0,
  );
  /* Sort criterion: Content: Published */
  $handler->display->display_options['sorts']['status']['id'] = 'status';
  $handler->display->display_options['sorts']['status']['table'] = 'node';
  $handler->display->display_options['sorts']['status']['field'] = 'status';
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
    'photo' => 'photo',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    5 => '5',
    6 => '6',
    4 => '4',
    7 => '7',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'photo_galleries';

  /* Display: Photo Gallery Clarinet Studio */
  $handler = $view->new_display('block', 'Photo Gallery Clarinet Studio', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'masonry_views';
  $handler->display->display_options['style_options']['masonry_column_width'] = '210';
  $handler->display->display_options['style_options']['masonry_gutter_width'] = '2';
  $handler->display->display_options['style_options']['masonry_resizable'] = TRUE;
  $handler->display->display_options['style_options']['masonry_animated'] = TRUE;
  $handler->display->display_options['style_options']['masonry_fit_width'] = TRUE;
  $handler->display->display_options['style_options']['masonry_rtl'] = FALSE;
  $handler->display->display_options['style_options']['masonry_images_first'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $export['photo_gallery'] = $view;

  return $export;
}
