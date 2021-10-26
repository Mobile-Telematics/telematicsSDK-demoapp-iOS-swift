//
//  RPEventPoint.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 21.01.2020.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPJSONSerializable.h"
#import "RPGeoPoint.h"
#import "RPRangeDirect.h"
#import "RPRangeLateral.h"
#import "RPRangeVertical.h"
#import "RPAccuracy.h"
#import "RPSpeed.h"

NS_ASSUME_NONNULL_BEGIN

@interface RPEventPoint : NSObject<RPJSONSerializable>

@property (copy, nonatomic) NSString* type;
@property (copy, nonatomic) NSNumber* timeStart;
@property (copy, nonatomic) NSNumber* duration;
@property (copy, nonatomic) NSNumber* pureDuration;
@property (copy, nonatomic) NSNumber* reliability;
@property (copy, nonatomic) NSNumber* speedStart;
@property (copy, nonatomic) NSNumber* speedStop;
@property (copy, nonatomic) NSNumber* speedMedian;
@property (copy, nonatomic) NSNumber* prevEventSpeed;
@property (copy, nonatomic) NSNumber* accelerationDirect;
@property (copy, nonatomic) NSNumber* accelerationLateral;
@property (copy, nonatomic) NSNumber* accelerationVertical;
@property (copy, nonatomic) NSNumber* accelerationDirectEnd;
@property (copy, nonatomic) NSNumber* accelerationLateralEnd;
@property (copy, nonatomic) NSNumber* accelerationVerticalEnd;
@property (copy, nonatomic) RPGeoPoint *startPoint;
@property (copy, nonatomic) RPGeoPoint *endPoint;
@property (copy, nonatomic) RPRangeDirect *rangeDirect;
@property (copy, nonatomic) RPRangeLateral *rangeLateral;
@property (copy, nonatomic) RPRangeVertical *rangeVertical;
@property (copy, nonatomic) RPAccuracy *accuracy;
@property (copy, nonatomic) RPSpeed *speed;
@property (copy, nonatomic) NSString* accidentTrigger;
@property (copy, nonatomic) NSString* theId;

@end

NS_ASSUME_NONNULL_END
