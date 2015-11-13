<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * Reese Creative Panels theme.
 */


function rc_panels_preprocess_html(&$variables) {
    drupal_add_css('http://fonts.googleapis.com/css?family=Open+Sans:400italic,400,300,700');
}

function rc_panels_preprocess_node(&$variables) {
  if ($variables['type'] == 'musical_score'){
    if(!$variables['field_sellable'][0]['value']){
      $variables['classes_array'][] = 'cart-disabled';
    }
  }
}

function rcpanels_uc_cart_block_content($variables) {
  $help_text = $variables['help_text'];
  $items = $variables['items'];
  $item_count = $variables['item_count'];
  $item_text = $variables['item_text'];
  $total = $variables['total'];
  $summary_links = $variables['summary_links'];
  $collapsed = $variables['collapsed'];

  $output = '';

  // Add the help text if enabled.
  if ($help_text) {
    $output .= '<span class="cart-help-text">' . $help_text . '</span>';
  }

  // Add a table of items in the cart or the empty message.
  $output .= theme('uc_cart_block_items', array('items' => $items, 'collapsed' => $collapsed));

  // Add the summary section beneath the items table.
  $output .= theme('uc_cart_block_summary', array('item_count' => $item_count, 'item_text' => $item_text, 'total' => $total, 'summary_links' => $summary_links));

  return $output;
}

function rcpanels_uc_cart_alter(&$items){
	// dd('**** New Item ****');
  // dd($items);
}
function rcpanels_uc_cart_item_update($entity){
   dd('**** New Item ****');
	dd($entity);
  foreach ($entity as $item) {
   
    dd($item->qty);
  }
}
function rcpanels_uc_cart_block_summary($variables) {
  $item_count = $variables['item_count'];
  $item_text = $variables['item_text'];
  $total = $variables['total'];
  $summary_links = $variables['summary_links'];
  $cart_status = ($item_count >= 1 ? 'cart_full' : 'cart_empty');
  $cart_details = uc_cart_get_contents();
  // kpr($cart_details);
  // Build the basic table with the number of items in the cart and total.
  $output = '<table class="cart-block-summary"><tbody><tr>'
           . '<td class="cart-block-summary-items">' . $item_text . '</td>'
           . '<td class="cart-block-summary-total"><label>' . t('Total:')
           . '</label> ' . theme('uc_price', array('price' => $total)) . '</td></tr>';

  // If there are products in the cart...
  if ($item_count > 0) {
    
    $_SESSION['cart_item_count'] = $item_count;
    // kpr($_SESSION);
    $output .= '<tr class="cart-block-summary-links"><td colspan="2">'
             . theme('links', array('links' => $summary_links)) . '</td></tr>';
  }

  $output .= '</tbody></table>';


  //create cart button
  $output = '<a href="/cart" id="cartPanelLink" class="basket-button-link"><span class="basket-button-count '. $cart_status .'">';

  $output .= '<span class="cartCount">' . $item_count . '</span>';

  $output .= '</span></a>';

  //create cart summary placeholder
  // $output .= '<div class="cartSummary"><div id="cartPreviewAjax">Getting cart contents</div></div>';

  return $output;
}

/**
 * Themes the uc_cart_view_form().
 *
 * Outputs a hidden copy of the update cart button first, so pressing Enter
 * updates the cart instead of removing an item.
 *
 * @param $variables
 *   An associative array containing:
 *   - form: A render element representing the form.
 *
 * @see uc_cart_view_form()
 * @ingroup themeable
 */
function rcpanels_uc_cart_view_form($variables) {
  $form = &$variables['form'];
  // kpr($form);
  $output = '<div class="uc-default-submit">';
  $output .= drupal_render($form['actions']['update']);
  $output .= '</div>';
  $form['actions']['update']['#printed'] = FALSE;

  $output .= drupal_render_children($form);

  return $output;
}

/**
 * Themes the cart checkout button(s).
 *
 * @param $variables
 *   An associative array containing:
 *   - buttons: A render element representing the form buttons.
 *
 * @see uc_cart_view_form()
 * @ingroup themeable
 */
function rcpanels_uc_cart_checkout_buttons($variables) {
  $output = '';

  if ($buttons = element_children($variables['buttons'])) {
    // Render the first button.
    $button = array_shift($buttons);
    $output = drupal_render($variables['buttons'][$button]);
    // Render any remaining buttons inside a separate container.
    if ($buttons) {
      $output .= '<div class="uc-cart-checkout-button-container clearfix">';

      // Render the second button.
      $output .= '<div class="uc-cart-checkout-button">';
      $output .= '<div class="uc-cart-checkout-button-separator">' . t('- or -') . '</div>';
      $button = array_shift($buttons);
      $output .= drupal_render($variables['buttons'][$button]);
      $output .= '</div>';

      // Render any remaining buttons.
      foreach ($buttons as $button) {
        $output .= '<div class="uc-cart-checkout-button">';
        $output .= drupal_render($variables['buttons'][$button]);
        $output .= '</div>';
      }

      $output .= '</div>';
    }
  }

  return $output;
}


/* change uc price to remove .00 */
function rcpanels_uc_price($variables) {
  $output = '<span class="uc-price">' . str_replace(".00","",uc_currency_format($variables['price'])) . '</span>';
  if (!empty($variables['suffixes'])) {
    $output .= '<span class="price-suffixes">' . implode(' ', $variables['suffixes']) . '</span>';
  }
  return $output;
}

/**
 * Returns the text displayed for an empty shopping cart.
 *
 * @ingroup themeable
 */
function rcpanels_uc_empty_cart() {
  $_continue_shopping = '<form class="uc-cart-view-form" action="/"><input type="submit" id="edit-continue-shopping" name="op" value="Continue shopping" class="form-submit"></form>';
  return '<div class="cart-empty-wrap"><p class="uc-cart-empty">' . t('There are no products in your shopping cart.') . '</p>' . $_continue_shopping . '</div>';









}