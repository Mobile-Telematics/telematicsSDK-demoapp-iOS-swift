//
//  RPLocator.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreMotion/CoreMotion.h>
#import "RPLocationRequest.h"
#import "RPSecure.h"
#import "RPWrappedLocation.h"
#import "RPELMTimeIntervals.h"
#import "RPVehicleIndicators.h"
#import "RPPQuantile.h"
#import <CoreBluetooth/CoreBluetooth.h>

@class RPRealTimeLocatorSettings;

#ifdef RPSECURE

#define RPLocator acl7sh3bj
#define previousLocation nasdjn237
#define lastAcceleration bkasdkjba712b
#define lastRotation ajnas712b
#define lastMotionActivity asjshb234
#define region asn877dg1n
#define regionHuge ajsndjj37
#define lastHeading jnlasdfn34
#define startMonitoringSignificantChanges alknbasd7b
#define startMonitoringRegion askdjn127
#define stopMonitoringRegion asdkbau3
#define resetMonitoringRegionWithNewLocation ahbsb37

#endif

typedef void(^SpeedCallbackOrig)(NSNumber *speed);

NS_ASSUME_NONNULL_BEGIN

/// Notifies when location was updated by GPS or Wi-Fi/Cellular networks positioning.
FOUNDATION_EXPORT NSString *const RPLocatorDidUpdateLocationsNotification;

/// Notifies when device leaves last anchored location.
FOUNDATION_EXPORT NSString *const RPLocatorDidChangeMotionActivityNotification;

/// Notifies when device leaves last anchored location.
FOUNDATION_EXPORT NSString *const RPLocatorDidExitRegionNotification;

/// Notifies when device enters last anchored location.
FOUNDATION_EXPORT NSString *const RPLocatorDidEnterRegionNotification;


@interface RPLocator : NSObject <CBCentralManagerDelegate> {
    double       prev;
}

/// HF indicator.
@property (assign, nonatomic) BOOL rtlState;


/// HF indicator.
@property (assign, nonatomic) BOOL hfState;

/// Indicates whether the locator is active.
@property (assign, nonatomic, getter=isActive) BOOL active;

/// Last speed from GPS (meters per second).
@property (readonly, nonatomic) double lastSpeedFromGPSMps;

/// Last driving indicator.
@property (readonly, nonatomic) BOOL lastDrivingState;

/// Indicates whether hardware monitoring should be enabled.
@property (readonly, nonatomic) BOOL useHardwareMonitoring;

/// Indicates exceeding the maximum speed
@property (readonly, nonatomic) BOOL speedExceeding;
@property (assign, nonatomic) BOOL firstLaunch;
@property (assign, nonatomic) BOOL firstBlockLaunch;
@property (assign, nonatomic) NSTimeInterval firstBlockFail;
@property (assign, nonatomic) double RPAccelerometerUpdateInterval;

@property (strong, nonatomic) RPELMTimeIntervals *elmTimeIntervals;

@property (strong, nonatomic) RPVehicleIndicators * _Nullable lastVehicleIndicators;
@property (readonly, copy, nonatomic) RPWrappedLocation * _Nullable   previousLocation;
@property (readonly, nonatomic) RPWrappedLocation * _Nullable         lastLocation;
@property (readonly, copy, nonatomic) CMAccelerometerData * _Nullable lastAcceleration;
@property (readonly, copy, nonatomic) CMGyroData * _Nullable          lastRotation;
@property (readonly, copy, nonatomic) CLRegion * _Nullable            region;
@property (readonly, copy, nonatomic) CLRegion * _Nullable            regionHuge;
@property (readonly, copy, nonatomic) CLHeading * _Nullable           lastHeading;
@property (readonly, nonatomic) RPRealTimeLocatorSettings *           realTimeLocatorSettings;
@property (strong, nonatomic) NSTimer *elmCMDTimer;

@property (assign, nonatomic) double aproximatedSpeed;

#pragma mark - Root

+ (void)initializeWithRequestPermissions:(BOOL)requestPermissions;
+ (instancetype)instance;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (void)pauseUpdating;
- (void)restoreUpdating;

- (NSMutableArray*)getEvents;
- (NSMutableArray*)getEventsOnAir;
- (NSString*)getLogOnAir;

#pragma mark - Significant Location Changes

- (void)startMonitoringSignificantChanges;


#pragma mark - Regions Monitoring

- (void)startMonitoringRegion;
- (void)stopMonitoringRegion;
- (void)resetMonitoringRegionWithNewLocation:(CLLocation *)location;
- (void)calculateX:(double)x y:(double)y z:(double)z speed:(double)speed accuracy:(double)accuracy latitude:(double)originLatitude longitude:(double)originLongitude time:(double)timestamp location:(CLLocation*)location course:(double)course;
- (void)setAccelerometerUpdateInterval:(NSInteger)interval;
- (void)currentSpeed:(void (^)(NSNumber *))speedCallback;
- (RPPQuantile*)getQuantile;

#pragma mark - Background Monitoring

+ (void)setBackgroundTime;
+ (Boolean)isBackground;
+ (void)setForegroundTime;
+ (BOOL)isEnabledHF;
- (void)requestData;

+ (void)enableHF:(BOOL)enable;
- (void)wrongAccuracyAuthorization;
- (Boolean)isWrongAccuracy;


- (void)setAggressiveHeartbeats:(BOOL)value;
- (BOOL)aggressiveHeartbeat;
- (void)checkELM;

@end

NS_ASSUME_NONNULL_END
