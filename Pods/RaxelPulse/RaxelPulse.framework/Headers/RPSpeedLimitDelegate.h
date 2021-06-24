//
//  RPSpeedLimitDelegate.h
//  RaxelPulse
//
//  Created by Igor Nabokov on 10/07/2018.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RPSpeedLimitDelegate <NSObject>

/// Overspeed threshold period in seconds.
@property(nonatomic, readonly) NSTimeInterval timeThreshold;

/// Max allowed speed in km/h.
@property(readonly) double speedLimit;

/// Callback for overspeeding.
- (void)speedLimitNotification:(double)speedLimit
                         speed:(double)speed
                      latitude:(double)latitude
                     longitude:(double)longitude
                          date:(NSDate *)date;

@end
