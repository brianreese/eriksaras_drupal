<div id="background">
  <div id="bgImg">
    <div class="bgGroup" id="homeSet">
         <!-- <img id="image01" src="/sites/all/themes/rcpanels/images/backgrounds/brooklyn.jpg" alt=""> -->
      </div>
      <div class="bgGroup" id="subSet">
      </div>
   </div>
</div>
<div id="wrap">

  <div class="l-branding">
    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo">
        <img class="desktop" src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        <!-- <img class="mobile" src="/<?php print path_to_theme(); ?>/logo-mobile.png"/> -->
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



    <div class="l-main pageContentWrap">
      <div class="l-content" role="main">

        <div id="mainContentWrap" class="contentRegion"> <a id="main-page-content" ></a>
          <div id="searchTitleWrap" class="titleWrapper"> <?php print render($title_prefix); ?>
            <?php if ($title): ?>
            <h1 id="mainPageTitle" tabindex="0"><?php print $title; ?></h1>
            <?php endif; ?>
            <?php print render($title_suffix); ?> </div>
          <div id="searchTabWrap" class="tabWrapper"> <?php print render($tabs); ?> </div>
          <?php print $messages; ?> 
          
          <!--<?php print render($page['help']); ?>-->
          <?php if ($action_links): ?>
          <ul class="action-links">
            <?php print render($action_links); ?>
          </ul>
          <?php endif; ?>
          <?php print render($page['content']); ?> 
          <div id="skip-link-3">
            <a href="#mainPageTitle" class="element-invisible element-focusable"><?php print t('Skip to top of page'); ?></a>
          </div>
          </div>
      
      </div>
    </div>




 





  
</div>