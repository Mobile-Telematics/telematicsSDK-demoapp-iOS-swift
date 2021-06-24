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

/// Represents info about mileage user scoring.
@interface RPStatisticsMileage : NSObject<RPJSONSerializable> {
    
}

/// Mileage rating range 0..100.
@property (assign, nonatomic) NSInteger mileageRating;

/// Average Mileage for week in km.
@property (assign, nonatomic) double averageMileageForWeek;

/// Average Mileage for month in km.
@property (assign, nonatomic) double averageMileageForMonth;

/// Total mileage in km.
@property (assign, nonatomic) double mileageSummary;

/// Predicted annual mileage in km.
@property (assign, nonatomic) double expectedYearMileage;

/// Diagram data mileage for period km/date.
@property (strong, nonatomic) NSArray<RPStatisticsPoint *> *mileageDiagram;

@end
