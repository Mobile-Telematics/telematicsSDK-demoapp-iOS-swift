//
//  RPHFRQHelper.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 22.10.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "RPPQuantile.h"

NS_ASSUME_NONNULL_BEGIN

@interface RPHFRQHelper : NSObject {
    NSString *logString;
}

+ (id)returnInstance;

- (void)clearEvents;
- (NSMutableArray*)getEvents;
- (NSMutableArray*)getEventsOnAir;
- (NSString*)getLogOnAir;
- (void)clearEvents;
- (RPPQuantile*)getQuantile;

- (void)detectEventForAcceleration:(double)xAcceleration
                                 y:(double)yAcceleration
                                 z:(double)zAcceleration
                             speed:(double)speed
                          accuracy:(double)accuracy
                          latitude:(double)originLatitude
                         longitude:(double)originLongitude
                              time:(double)timestamp
                          location:(CLLocation*)location
                            course:(double)course
                            gyro_x:(double)gyro_x
                            gyro_y:(double)gyro_y
                            gyro_z:(double)gyro_z;

@end

NS_ASSUME_NONNULL_END
