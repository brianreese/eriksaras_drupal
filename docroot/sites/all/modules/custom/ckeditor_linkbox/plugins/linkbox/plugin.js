/**
 *
 * Created out of the CKEditor Widget SDK:
 * http://docs.ckeditor.com/#!/guide/widget_sdk_tutorial_2
 *
 * Helpful Documentation
 * - [plugin documentation, the CKEDitor plugin system](http://docs.ckeditor.com/#!/api/CKEDITOR.plugins)
 * - [widget documentation, another plugin system under the CKEDitor plugin system](http://docs.ckeditor.com/#!/api/CKEDITOR.plugins.widget)
 * - [element documentation, the class of the DOM elements being passed around](http://docs.ckeditor.com/#!/api/CKEDITOR.dom.element)
 * - [Advanced Content Filter's Allowed Content Rules. Important when doing editor.widgets.add(), you define an `allowedContent` property in the object you pass into the second parameter](http://docs.ckeditor.com/#!/guide/dev_allowed_content_rules)
 */

CKEDITOR.plugins.add('linkbox', {
  requires: 'widget',
  icons: 'linkbox',
  init: function(editor) {
    CKEDITOR.dialog.add( 'linkbox', this.path +'dialogs/linkbox.js' );
    editor.widgets.add( 'linkbox', {
      allowedContent: 'span a [*]{*}(*)',
      requiredContent: 'span(linkbox)',
      template:
        '<span class="linkbox"><a class="linkbox-title btn"></a></span>',
      button: 'Create a Link Box',
      dialog: 'linkbox',
      // When CKEditor is fed content, let it know what content is controlled by this Widget
      upcast: function(element) {
        return element.name == 'span' && element.hasClass('linkbox');
      },
      init: function() {
        // Pull data out of the existing markup and save in memory onto `this.data`.
        var parent = this.element.getParent(0);
        parent.setStyle('display','inline-block')
        var anchor = this.element.getChild(0);
        var target = anchor.getAttribute('target')
          ? (anchor.getAttribute('target')).substr(1, (anchor.getAttribute('target')).length)
          : 'self';
        var classes = anchor.getAttribute('class');
        var match = ((/btn-(.*) /).exec(classes));
        if (!match) match = ((/btn-(.*)/).exec(classes));
        var type = (match) ? (match[0]).substr(4, match[0].length) : 'blue';
        this.setData('linkbox_type', type);
        this.setData('linkbox_link', anchor.getAttribute('href'));
        this.setData('linkbox_target', target);
        this.setData('linkbox_text', anchor.getText());
      },
      data: function() {
        // Given the data we have in memory, manipulate the markup of a new or existing linkbox
        var anchor = this.element.getChild(0);
        anchor.setAttribute('href', this.data.linkbox_link);
        anchor.setAttribute('target', '_' + this.data.linkbox_target);
        anchor.setText(this.data.linkbox_text);
        var classes = anchor.getAttribute('class');
        var match = ((/btn-(.*) /).exec(classes));
        if (!match) match = ((/btn-(.*)/).exec(classes));
        var type = (match) ? (match[0]).substr(4, match[0].length) : null;
        if (type) anchor.removeClass('btn-' + type);
        if (this.data.linkbox_type) {
          anchor.addClass('btn-' + this.data.linkbox_type);
        }
      }
    });
  }
});
