//
//  RPEntry.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RPAPIEntry.h"
#import "RPRecorder.h"
#import "RPTracker.h"
#import "RPLogDelegate.h"
#import "RPApiLanguage.h"
#import "RPSpeedLimitDelegate.h"
#import "RPTrackingStateListenerDelegate.h"
#import "RPAccuracyAuthorizationDelegate.h"
#import "RPLowPowerModeDelegate.h"
#import "RPRTDLDelegate.h"
#import "RPLocationDelegate.h"
#import "RPTagsServerStateDelegate.h"

@class UIApplication;
@class RPEntry;
@class RPRealTimeLocatorSettings;

#define RPSDK_HARDWARE_LOGGING 0

NS_ASSUME_NONNULL_BEGIN

/// Entry point class for RaxelPulse SDK. Start your work with this class instance initialization.
@interface RPEntry : NSObject

/// Current SDK Version
@property (readonly, nonatomic) NSString *version;

/// API entry point.
@property (readonly, nonatomic) RPAPIEntry *api;

/// Virtual device token.
@property (weak, nonatomic) NSString * _Nullable virtualDeviceToken;

/// wrongAccuracyAuthorization
@property (assign, nonatomic) BOOL wrongAccuracyState;

/// Disables tracking while leaving some SDK functions on.
@property (assign, nonatomic) BOOL disableTracking;

/// Force API language.
@property (nonatomic) RPApiLanguage apiLanguage;

/// Advertising identifier. It can be send with heartbeat.
@property (strong, nonatomic) NSUUID *advertisingIdentifier;

/// Delegate for event logging.
@property (weak, nonatomic) id<RPLogDelegate> logDelegate;

/// Delegate for speeding events.
@property (weak, nonatomic) id<RPSpeedLimitDelegate> speedLimitDelegate;

/// Delegate for event logging.
@property (weak, nonatomic) id<RPTrackingStateListenerDelegate> trackingStateDelegate;

/// Delegate for event logging.
@property (weak, nonatomic) id<RPAccuracyAuthorizationDelegate> accuracyAuthorizationDelegate;

/// Delegate for event logging.
@property (weak, nonatomic) id<RPLowPowerModeDelegate> lowPowerModeDelegate;

/// Delegate for event logging.
@property (weak, nonatomic) id<RPRTDLDelegate> rtldDelegate;

/// Delegate for event logging.
@property (weak, nonatomic) id<RPLocationDelegate> locationDelegate;

/// Delegate for event logging.
@property (weak, nonatomic) id<RPTagsServerStateDelegate> tagStateDelegate;

#pragma mark - Root

/**
 Initializes new <tt>RPEntry</tt> class instance with specified device ID. Must be the first method calling from RaxelPulse SDK.
 @param useHardware Indicates whether the SDK should enable hardware monitoring in addition to GPS location updates.
 */
+ (void)initializeWithHardwareMonitoring:(BOOL)useHardware __attribute__ ((deprecated("use [RPEntry initializeWithRequestingPermissions:] method")));

/**
 Initializes new <tt>RPEntry</tt> class instance with specified device ID. Must be the first method calling from RaxelPulse SDK.
 @param requestPermissions Indicates whether the SDK should request system permissions.
 */
+ (void)initializeWithRequestingPermissions:(BOOL)requestPermissions;

/*
 Returns shared <tt>RPEntry</tt> class instance. This method can be called only after <tt>initializeWithDeviceToken:useHardwareMonitoring:</tt> method execution.
 @return Shared <tt>RPEntry</tt> class instance.
 */
+ (instancetype)instance;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;


#pragma mark - Utils

/// Remove virtual device token. Use this method instead of setting empty token.
- (void)removeVirtualDeviceToken;

- (NSInteger)filesCount;
- (NSInteger)getUnsentTraksCount;
#pragma mark - App Delegate

// You must call these methods from your app delegate's methods with the same signatures.

+ (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
+ (void)application:(UIApplication *)application handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)(void))completionHandler;
+ (void)applicationDidBecomeActive:(UIApplication *)application;
+ (void)applicationDidEnterBackground:(UIApplication *)application;
+ (void)applicationDidReceiveMemoryWarning:(UIApplication *)application;
+ (void)applicationWillTerminate:(UIApplication *)application;
+ (void)application:(UIApplication *)application performFetchWithCompletionHandler:(void (^)(void))completionHandler;
//+ (void)getTracks:(UIViewController*)controller completeon:(void (^ __nullable)(void))completion;
//+ (void)cleanLogs;
//+ (void)destroyAllFiles;
//- (NSMutableArray*)getEventsOnAir;
//- (NSString*)getLogOnAir;
//+ (NSMutableArray<NSURL*>*)getTracksList;
//- (void)calculateX:(double)x y:(double)y z:(double)z speed:(double)speed accuracy:(double)accuracy latitude:(double)originLatitude longitude:(double)originLongitude time:(double)timestamp location:(CLLocation*)location course:(double)course;
//- (void)setAccelerometerUpdateInterval:(NSInteger)interval;
- (NSString*)getReason;
- (void)currentSpeed:(void (^)(NSNumber *))speedCallback;
+ (BOOL)isAllRequiredPermissionsGranted;
+ (void)enableHF:(BOOL)enable;
+ (void)enableELM:(BOOL)enable;

+ (void)getRTLData:(void (^)(NSString *))callback;
//+ (void)setIMEI:(NSString*)value;
+ (BOOL)isEnabledELM;

+ (void)setConfig:(id)json;
+ (id)getConfig;

+ (void)setDataInterval:(UInt32)period_trip period_stop:(UInt32)period_stop;
+ (void)setDataRadius:(UInt32)radius_trip radius_stop:(UInt32)radius_stop;
+ (void)setProtocol:(UInt32)protocol;
+ (void)setServer:(NSString*)adr port:(NSString*)port;
+ (void)setSendVolumePack:(UInt32)size_trip size_stop:(UInt32)size_stop;
+ (void)setOdometer:(double)km;
+ (double)getOdometer;
+ (void)enableRTLD:(BOOL)enable;
+ (BOOL)isRTDEnabled;

- (BOOL)isTrackingEnabled;
- (void)wrongAccuracyAuthorization:(Boolean)state;
- (void)onLocationChanged:(CLLocation*)location;
- (void)addTag:(BOOL)status tag:(RPTag*)tag timestamp:(NSInteger)timestamp;
- (void)removeAll:(BOOL)status timestamp:(NSInteger)timestamp;
- (void)deleteTag:(BOOL)status tag:(RPTag*)tag timestamp:(NSInteger)timestamp;
- (void)getTags:(BOOL)status tags:(id)tags timestamp:(NSInteger)timestamp;

- (void)setAggressiveHeartbeats:(BOOL)value;
- (BOOL)aggressiveHeartbeat;
- (void)setEnableSdk:(BOOL)value;
- (void)setDisableWithUpload;
+ (BOOL)isSDKEnabled;
+ (void)enableAccidents:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
