//
// Amplitude.h
// Amplitude
//
// The MIT License (MIT)
//
// Copyright (c) 2014 Amplitude
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>


/*!
 @class
 Amplitude API.
 
 @abstract
 The interface for integrating Amplitude with your application.
 
 @discussion
 Use the Amplitude class to track events in your application.
 
 <pre>
 // In every file that uses analytics, import Amplitude.h at the top
 #import "Amplitude.h"
 
 // First, be sure to initialize the API in your didFinishLaunchingWithOptions delegate
 [Amplitude initializeApiKey:@"YOUR_API_KEY_HERE"];
 
 // Track an event anywhere in the app
 [Amplitude logEvent:@"EVENT_IDENTIFIER_HERE"];
 
 // You can attach additional data to any event by passing a NSDictionary object
 NSMutableDictionary *eventProperties = [NSMutableDictionary dictionary];
 [eventProperties setValue:@"VALUE_GOES_HERE" forKey:@"KEY_GOES_HERE"];
 [Amplitude logEvent:@"Compute Hash" withEventProperties:eventProperties];
 </pre>
 
 For me details on the setup and usage, be sure to check out the docs here:
 https://github.com/amplitude/Amplitude-iOS#setup
 */
@interface Amplitude : NSObject

// Step 1: Initialization
// ----------------------

/*!
 @method
 
 @abstract
 Initializes the Amplitude static class with your Amplitude api key.
 
 @param apiKey                 Your Amplitude key obtained from your dashboard at https://amplitude.com/settings
 @param userId                 If your app has its own login system that you want to track users with, you can set the userId.
 
 @discussion
 We recommend you first initialize your class within your "didFinishLaunchingWithOptions" method inside your app delegate.
 
 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 {
 // Initialize your shared Analytics instance.
 [Amplitude initializeApiKey:@"YOUR_API_KEY_HERE"];
 
 // YOUR OTHER APP LAUNCH CODE HERE....
 
 return YES;
 }
 */
+ (void)initializeApiKey:(NSString*) apiKey;
+ (void)initializeApiKey:(NSString*) apiKey userId:(NSString*) userId;

// Step 2: Track an event
// -------------------------------------

/*!
 @method
 
 @abstract
 Tracks an event
 
 @param eventType                The name of the event you wish to track.
 @param eventProperties         You can attach additional data to any event by passing a NSDictionary object.

 @discussion
 Events are saved locally. Uploads are batched to occur every 30 events and every 30 seconds, as well as on app close. 
 After calling logEvent in your app, you will immediately see data appear on the Amplitude Website.
 
 It's important to think about what types of events you care about as a developer. You should aim to track 
 between 10 and 100 types of events within your app. Common event types are different screens within the app,
 actions the user initiates (such as pressing a button), and events you want the user to complete 
 (such as filling out a form, completing a level, or making a payment). 
 Contact us if you want assistance determining what would be best for you to track. (contact@amplitude.com)
 */
+ (void)logEvent:(NSString*) eventType;
+ (void)logEvent:(NSString*) eventType withEventProperties:(NSDictionary*) eventProperties;

/*!
 @method
 
 @abstract
 Tracks revenue.
 
 @param amount                   The amount of revenue to track, e.g. "3.99".
 
 @discussion
 To track revenue from a user, call [Amplitude logRevenue:[NSNumber numberWithDouble:3.99]] each time the user generates revenue. 
 logRevenue: takes in an NSNumber with the dollar amount of the sale as the only argument. This allows us to automatically display 
 data relevant to revenue on the Amplitude website, including average revenue per daily active user (ARPDAU), 7, 30, and 90 day revenue, 
 lifetime value (LTV) estimates, and revenue by advertising campaign cohort and daily/weekly/monthly cohorts.
 */
+ (void)logRevenue:(NSNumber*) amount;


/*!
 @method
 
 @abstract
 Manually forces the class to immediately upload all queued events.
 
 @discussion
 Events are saved locally. Uploads are batched to occur every 30 events and every 30 seconds, as well as on app close.
 Use this method to force the class to immediately upload all queued events.
 */
+ (void)uploadEvents;

// Step 3: Set event properties (optional)
// -------------------------------------

/*!
 @method
 
 @abstract
 Adds properties that are tracked on the user level.
 
 @param userProperties         An NSDictionary containing any additional data to be tracked.
 
 @discussion
 Property keys must be <code>NSString</code> objects and values must be serializable.
 */
+ (void)setUserProperties:(NSDictionary*) userProperties;

/*!
 @method
 
 @abstract
 Sets the userId.
 
 @param userId                   If your app has its own login system that you want to track users with, you can set the userId.
 
 @discussion
 If your app has its own login system that you want to track users with, you can set the userId.
 */
+ (void)setUserId:(NSString*) userId;

// Step 4: Advanced customizations and features (optional)
// -------------------------------------

/*!
 @method
 
 @abstract
 Enables location tracking.
 
 @discussion
 If the user has granted your app location permissions, the SDK will also grab the location of the user. 
 Amplitude will never prompt the user for location permissions itself, this must be done by your app.
 */
+ (void)enableLocationListening;

/*!
 @method
 
 @abstract
 Disables location tracking.
 
 @discussion
 If you want location tracking disabled on startup of the app, call disableLocationListening before you call initializeApiKey.
 */
+ (void)disableLocationListening;

/*!
 @method
 
 @abstract
 Prints the number of events in the queue.
 
 @discussion
 Debugging method to find out how many events are being stored locally on the device.
 */
+ (void)printEventsCount;

@end
