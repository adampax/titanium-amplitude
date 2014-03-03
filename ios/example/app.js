// This is a test harness for your module
// You should do something interesting in this harness
// to test out the module and to provide instructions
// to users on how to use it by example.

// open a single window
var win = Ti.UI.createWindow({
	backgroundColor : 'white'
});
var label = Ti.UI.createLabel({
	text : 'Check your Amplitude Dashboard'
});
win.add(label);
win.open();


//Enabling location services in the app will automatically enable 
//location tracking in Amplitude
if (Ti.Geolocation.locationServicesEnabled) {
	Titanium.Geolocation.purpose = 'Get Current Location';
	Titanium.Geolocation.getCurrentPosition(function(e) {
		if (e.error) {
			Ti.API.error('Error: ' + e.error);
		} else {
			Ti.API.info(e.coords);
		}
	});
}

var amplitude = require('com.polancomedia.amplitude');

//must be called first
amplitude.initialize('YOUR_API_KEY');


amplitude.setUserId('user123');

//set properties associated with the user
amplitude.setUserProperties({
	membership:'premium',
	shirtColor: 'red'
});


//events can be logged with or without additional data
//note that Amplitude already tracks app version, phone model, operating system version, and carrier information
amplitude.logEvent('test_event');
amplitude.logEvent('event_with_properties', {myEvent : 'hello'});

