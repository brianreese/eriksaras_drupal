<div class="cartSummary">
  <div id="cartPreviewAjax">
    <span class="loadingMessage">Getting cart contents</span>
    <div id="loading">
      <div class="ui-loading">
        <ul>
          <li></li>
          <li></li>
          <li></li>
        </ul>
      </div>
    </div
  ></div>
</div>
<div id="wrap">

  <div class="l-branding">
    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo">
        <img class="desktop" src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        <img class="mobile" src="<?php print path_to_theme(); ?>/logo-mobile.png"/>
      </a>
    <?php endif; ?>

  <!--
    <?php if ($site_name || $site_slogan): ?>
      <?php if ($site_name): ?>
        <h1 class="site-name">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
        </h1>
      <?php endif; ?>

      <?php if ($site_slogan): ?>
        <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
      <?php endif; ?>
    <?php endif; ?>
  -->
    <?php print render($page['branding']); ?>
  </div>








  <div id="panelsWrap">
    <div id="levelWrap_01">
      <?php print render($page['nav01']); ?>
    </div>
    <div id="rcp_content">
      <div id="levelWrap_02">
        <?php print render($page['nav02']); ?>
      </div>
      <div id="levelWrap_03" class="level3">
        <?php print render($page['nav03']); ?>
      </div>
    </div>
  </div>


<?php if($page['cart']): ?>
  <div id="cartFadeOut"></div>
  <div id="shoppingCart">
    <?php print render($page['cart']); ?>
  </div>
<?php endif; ?>

  <div id="background">
    <div id="bgImg">
      <div class="bgGroup" id="homeSet">
          <!--  <img id="image01" src="/sites/all/themes/rcpanels/images/backgrounds/brooklyn.jpg" alt=""> -->
        </div>
        <div class="bgGroup" id="subSet">
        </div>
     </div>
  </div>
</div>

