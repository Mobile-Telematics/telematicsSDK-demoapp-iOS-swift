//
//  RPTracker.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPTrackerState.h"

@class RPRawTrackPoint;

/// Notifies when <tt>RPTracker</tt> changes its activity state.
FOUNDATION_EXPORT NSString *const RPTrackerDidChangeActivityNotification;

/// Represents all tracking logic.
@interface RPTracker : NSObject {
    
}
/// Current tracker state (on-demand calculation).
@property (readonly, nonatomic) RPTrackerState  *currentTrackerState;

/// Current track point data in raw (on-demand calculation).
@property (readonly, nonatomic) RPRawTrackPoint *rawTrackPoint;

/// Indicates whether the tracking subsystem is active for now.
@property (readonly, nonatomic, getter=isActive) BOOL active;

/// Indicates whether the tracking subsystem is active for now.
@property (readonly, nonatomic, getter=isTracking) BOOL tracking;



#pragma mark - Root

/*!
 Returns shared <tt>RPTracker</tt> class instance.
 @return Shared <tt>RPTracker</tt> class instance.
 */
+ (instancetype)instance;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (NSMutableArray*)getEvents;

#pragma mark - Tracking

/// Starts tracking immediately.
- (void)startTracking;

/// Stops tracking immediately.
- (void)stopTracking;
- (void)startELMTracking;
- (void)startReconectELMTracking;
- (void)stopDisconectELMTracking;

+ (void)updateLastLocations:(NSArray<CLLocation *> *)locations status:(Boolean)status aDirect:(double)aDirect aLateral:(double)aLateral aVertical:(double)aVertical gyroX:(double)gyroX gyroY:(double)gyroY gyroZ:(double)gyroZ callback:(void (^)(BOOL))callback callbackBudge:(void (^)(BOOL))callbackBudge;
+ (void)updateVehicleIndicators:(NSArray<NSDictionary<NSString *,id> *> * _Nonnull)vi;
+ (void)updateHFEvents:(NSArray<NSDictionary<NSString *,id> *> * _Nonnull)hf;

@end
