//
//  RPStatistics.h
//  RaxelPulse
//
//  Created by AlWork on 02/11/2017.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPJSONSerializable.h"
#import "RPStatisticsPoint.h"

/// Represents info about speed detail user scoring.
@interface RPStatisticsSpeed : NSObject<RPJSONSerializable> {
    
}

/// Speeding score Range 0...100.
@property (assign, nonatomic) NSInteger speedRating;

/// Above speed limit per 100 km in km.
@property (assign, nonatomic) double drivingOverSpeedLimitFor100Km;

/// Above speed limit more than 20km/h per 100 km in km.
@property (assign, nonatomic) double drivingOverSpeedLimitMore20KmFor100Km;

/// Max Speed in km/h.
@property (assign, nonatomic) NSInteger maximumSpeed;

/// Average Speed in km/h.
@property (assign, nonatomic) NSInteger averageSpeed;

/// Speeding in km/h.
@property (strong, nonatomic) NSArray<RPStatisticsPoint *> *drivingOverSpeedLimitDiagram;

/// Speeding over 20km/h in km/h.
@property (strong, nonatomic) NSArray<RPStatisticsPoint *> *drivingOverSpeedLimitMore20KmDiagram;

@end
