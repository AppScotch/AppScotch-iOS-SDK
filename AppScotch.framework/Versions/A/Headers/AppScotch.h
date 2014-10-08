#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define DEFERED_FETCH_OPTION_KEY @"deferedFetch"
#define APPSCOTCH_VERSION @"2.0.1"


/**  Delegate protocol for AppScotch
 */
@protocol AppScotchDelegate <NSObject>

@optional

/// This method informs the app that an ad has been received and is available for display.
- (void) onAdAvailable;

/** this method informs the app that an ad has failed to be received
 * @param error occured error
 */
- (void) onAdUnavailable:(NSError *)error;


/// this method informs user that ad will be now displayed with animation.
- (void) onAdStart;


/// this method informs user that ad will be now hided with animation.
- (void) onAdEnd;

/** this method informs user that view was completed
 * @param isCompleted false if ad was interrupted by user, otherwise true.
 */

- (void) onView:(bool)isCompleted;

@end

/**  Main ad serving class
 */
@interface AppScotch : NSObject

/**  This method serves as the entry point to AppScotch.
 * @param key AppId gathered from AppScotch.com
 * @see init:options: for information about initialisation with options
 */
+ (void) init:(NSString*)key;

/**  This method serves as the entry point to AppScotch.
 * @param key AppId gathered from AppScotch.com
 * @param options initialization options, supported options:
 *  DEFERED_FETCH_OPTION_KEY -  time in ms to wait before fetching ad
 *
 */
+ (void) init:(NSString*)key options:(NSDictionary*)options;


/**  This method turns off all sdk activity. No network or CPU usage.
 */
+ (void) turnAdsOff;


/**
 *  Display an ad
 *
 *  This method will display an ad if one is ready for display on the device.
 *
 *
 *  @see init: for details on retrieving an ad.
 *  @see isAdAvailable for details on verifying is an ad is ready to be displayed.
 *  
 *  @return YES/NO to indicate if an ad is ready and will be displayed.
 */
+ (BOOL) playAd:(UIViewController*)vc;



/**
 *  Returns if an ad is currently ready to display
 *
 *  This method will verify if there is an ad is currently available for this
 *  user. If an ad is not available, you may call AppScotch#fetchAd: to load a new ad.
 *
 *  @note If this method returns YES, an ad will be available when you attempt to display an ad
 *
 *  @see playAd for details on displaying the available ad.
 *
 *
 *  @return YES/NO to indicate if an ad is ready to be displayed.
 */
+ (BOOL) isAdAvailable;


+ (void) setDelegate:(id<AppScotchDelegate>)delegate;
@end