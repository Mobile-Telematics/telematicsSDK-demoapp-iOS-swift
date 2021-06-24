//
//  RPTrackPointForUpload.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPTrackPointBase.h"
#import "RPSecure.h"
#import "RPVehicleIndicators.h"
#import "RPPQuantile.h"

@class RPRawTrackPoint;

#ifdef RPSECURE

#define fromRawPoint nnns7102bs

#endif


@interface RPTrackPointForUpload : RPTrackPointBase<RPJSONSerializable> {
    
}

@property (copy, nonatomic) NSNumber *acceleration;
@property (copy, nonatomic) NSNumber *deceleration;
@property (copy, nonatomic) NSNumber *establishedIndexA;
@property (copy, nonatomic) NSNumber *establishedIndexB;
@property (copy, nonatomic) NSNumber *tickTimestamp;
@property (copy, nonatomic) NSNumber *accelerationX;
@property (copy, nonatomic) NSNumber *accelerationY;
@property (copy, nonatomic) NSNumber *accelerationZ;
@property (copy, nonatomic) NSNumber *gyroX;
@property (copy, nonatomic) NSNumber *gyroY;
@property (copy, nonatomic) NSNumber *gyroZ;
@property (copy, nonatomic) NSNumber *accelerationXOriginal;
@property (copy, nonatomic) NSNumber *accelerationYOriginal;
@property (copy, nonatomic) NSNumber *accelerationZOriginal;
@property (copy, nonatomic) NSNumber *gyroXOriginal;
@property (copy, nonatomic) NSNumber *gyroYOriginal;
@property (copy, nonatomic) NSNumber *gyroZOriginal;
@property (copy, nonatomic) NSNumber *horizontalAccuracy;
@property (copy, nonatomic) RPVehicleIndicators *vehicleIndicators;
@property (copy, nonatomic) RPPQuantile *quantile;


#pragma mark - Utils

+ (instancetype)fromRawPoint:(RPRawTrackPoint *)point;
- (id)toJSONDB;

@end
