//
//  RPTrackerState.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "RPJSONSerializable.h"

/// Struct containing current <tt>RPTracker</tt> class instance state.
@interface RPTrackerState : NSObject<NSCoding, RPJSONSerializable> {
    
}
/// Time driven from the current tracking activation (seconds).
@property (assign, nonatomic) NSTimeInterval timeDrivenSeconds;

/// Distance driven from the current tracking activation (meters).
@property (assign, nonatomic) CLLocationDistance distanceDrivenMeters;

/// Last speed received from hardware GPS sensor.
@property (assign, nonatomic) CLLocationSpeed lastSpeedFromGPSMps;

/// Indicates whether the last known tracking state is active.
@property (assign, nonatomic) BOOL lastTrackingState;

/// Indicates whether the last known driving state is automotive.
@property (assign, nonatomic) BOOL lastDrivingState;

/// Indicates whether the automatic deactivation timer is active at now.
@property (assign, nonatomic) BOOL isDeactivationEnabled;

@end
