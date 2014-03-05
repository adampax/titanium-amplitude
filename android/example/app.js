var win = Ti.UI.createWindow({
	backgroundColor:'white'
});
var label = Ti.UI.createLabel();
win.add(label);
win.open();

// TODO: write your module tests here
var amplitude = require('com.polancomedia.amplitude');


//must be called first
//amplitude.initialize('YOUR_API_KEY');

amplitude.setUserId('androidUser');

amplitude.logEvent('android_event');

amplitude.logEvent('event_with_properties', {hello: 'android'});
