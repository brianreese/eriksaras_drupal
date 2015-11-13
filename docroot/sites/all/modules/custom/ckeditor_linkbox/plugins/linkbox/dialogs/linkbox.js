/**
 *
 * Created out of the CKEditor Widget SDK:
 * http://docs.ckeditor.com/#!/guide/widget_sdk_tutorial_2
 */

CKEDITOR.dialog.add( 'linkbox', function( editor ) {
  return {
    title: 'Edit Link Box',
    minWidth: 200,
    minHeight: 100,
    contents: [
      {
        id: 'info',
        elements: [
          {
            id: 'linkbox_type',
            type: 'select',
            label: 'Box Type',
            items: [
              [ 'pink', 'pink' ],
              [ 'pink (open)', 'pink-open' ],
              [ 'green', 'green'],
              [ 'green (open)', 'green-open'],
              [ 'dark-red', 'dark-red' ],
              [ 'dark-red (open)', 'dark-red-open' ],
              [ 'blue', 'blue' ],
              [ 'blue (open)', 'blue-open' ],
              [ 'dark-blue', 'dark-blue' ],
              [ 'dark-blue (open)', 'dark-blue-open' ],
              [ 'white', 'white' ],
              [ 'orange', 'orange'],
              [ 'dark-gray', 'dark-gray'],
              [ 'light-gray', 'light-gray']
            ],
            setup: function( widget ) {
              // Take the data from memory and set the form value
              this.setValue( widget.data.linkbox_type );
            },
            commit: function( widget ) {
              // Take the data from the form and set it on `widget.data`.
              // Using a setter causes the widget.data function from the plugin
              // to be called which then results in modified markup.
              widget.setData( 'linkbox_type', this.getValue() );
            }
          },
          {
            id: 'linkbox_target',
            type: 'select',
            label: 'Link target',
            items: [
              [ 'blank', 'blank' ],
              [ 'self', 'self' ]
            ],
            setup: function( widget ) {
              // Take the data from memory and set the form value
              this.setValue( widget.data.linkbox_target  );
            },
            commit: function( widget ) {
              // Take the data from the form and set it on `widget.data`.
              // Using a setter causes the widget.data function from the plugin
              // to be called which then results in modified markup.
              widget.setData( 'linkbox_target', this.getValue() );
            }
          },
          {
            id: 'linkbox_link',
            type: 'text',
            label: 'Box Link',
            width: '350px',
            setup: function( widget ) {
              this.setValue( widget.data.linkbox_link );
            },
            commit: function( widget ) {
              widget.setData( 'linkbox_link', this.getValue() );
            }
          },
          {
            id: 'linkbox_text',
            type: 'text',
            label: 'Box Text',
            width: '350px',
            setup: function( widget ) {
              this.setValue( widget.data.linkbox_text );
            },
            commit: function( widget ) {
              widget.setData( 'linkbox_text', this.getValue() );
            }
          }
        ]
      }
    ]
  };
} );
