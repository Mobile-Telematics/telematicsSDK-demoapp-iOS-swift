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

/// Represents info about Driving user scoring.
@interface RPStatisticsDriving : NSObject<RPJSONSerializable> {
    
}

/// Common Driving rating.
@property (assign, nonatomic) NSInteger drivingRating;

/// Frequency of harsh braking per 100km.
@property (assign, nonatomic) NSInteger heavyBrakingFrequencyFor100Km;

/// Frequency of rapid accelerations per 100km.
@property (assign, nonatomic) NSInteger activeAccelerationFrequencyFor100Km;

/// Harsh Braking during this period.
@property (assign, nonatomic) NSInteger heavyBrakingCountForPeriod;

/// Rapid Accelerations for period.
@property (assign, nonatomic) NSInteger activeAccelerationCountForPeriod;

/// Harsh Braking diagram data for period.
@property (strong, nonatomic) NSArray<RPStatisticsPoint *> *heavyBrakingDiagram;

/// Rapid Accelerations diagram data for period count/date.
@property (strong, nonatomic) NSArray<RPStatisticsPoint *> *activeAccelerationDiagram;

@end
