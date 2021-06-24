//
//  RPRawTrackPoint.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPSecure.h"
#import "RPVehicleIndicators.h"
#import "RPPQuantile.h"


@interface RPRawTrackPoint : NSObject {
    
}

@property (nonatomic, strong) NSNumber *number;
@property (nonatomic, strong) NSNumber *latitude;
@property (nonatomic, strong) NSNumber *longitude;
@property (nonatomic, strong) NSNumber *timestamp;
@property (nonatomic, strong) NSNumber *speedKmh;
@property (nonatomic, strong) NSNumber *course;
@property (nonatomic, strong) NSNumber *height;
@property (nonatomic, strong) NSNumber *acceleration;
@property (nonatomic, strong) NSNumber *deceleration;
@property (nonatomic, strong) NSNumber *lateral;
@property (nonatomic, strong) NSNumber *yaw;
@property (nonatomic, strong) NSNumber *totalMeters;
@property (nonatomic, strong) NSNumber *establishedIndexA;
@property (nonatomic, strong) NSNumber *establishedIndexB;
@property (nonatomic, strong) NSNumber *midspeed;
@property (nonatomic, strong) NSNumber *tickTimestamp;
@property (nonatomic, strong) NSNumber *accelerationX;
@property (nonatomic, strong) NSNumber *accelerationY;
@property (nonatomic, strong) NSNumber *accelerationZ;
@property (nonatomic, strong) NSNumber *gyroX;
@property (nonatomic, strong) NSNumber *gyroY;
@property (nonatomic, strong) NSNumber *gyroZ;
@property (nonatomic, strong) NSNumber *accelerationXRaw;
@property (nonatomic, strong) NSNumber *accelerationYRaw;
@property (nonatomic, strong) NSNumber *accelerationZRaw;
@property (nonatomic, strong) NSNumber *gyroXRaw;
@property (nonatomic, strong) NSNumber *gyroYRaw;
@property (nonatomic, strong) NSNumber *gyroZRaw;
@property (nonatomic, strong) NSNumber *horizontalAccuracy;
@property (nonatomic, strong) RPVehicleIndicators *vehicleIndicators;
@property (nonatomic, strong) RPPQuantile *quantile;


@end
