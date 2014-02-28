## Titanium Amplitude

### Compiled Module
* [iOS](https://github.com/adampax/titanium-amplitude/tree/master/ios/dist)

### About

This is a wrapper for the [Amplitude iOS SDK](https://github.com/amplitude/Amplitude-iOS). Get more info in the [Amplitude Docs](https://amplitude.com/docs).

###

```javascript

var amplitude = require('com.polancomedia.amplitude');

ampitude.initialize('MY_API_KEY');

amplitude.logEvent('my_custom_event');

```

See full example in the `example` folder. 

### Methods

#### initialize(string)
* String containing your Amplitude API Key
* Must be called before any other methods

#### logEvent(string, obj)
* String containing your event name
* Optional object with name/value pairs

#### setUserId(string)
* Use this if you want to associate your event data with a logged in user

## About
* Me: [Adam Paxton](http://adampaxton.com) 
* Twitter: [@adampax](http://twitter.com/adampax)
* Work: [Polanco Media, LLC](http://polancomedia.com)

## License
MIT License
Copyright (c) 2014 Polanco Media, LLC
