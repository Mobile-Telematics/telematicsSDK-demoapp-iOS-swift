//
//  RPStatistics.h
//  RaxelPulse
//
//  Created by AlWork on 02/11/2017.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPJSONSerializable.h"
#import "RPStatisticsDriving.h"
#import "RPStatisticsDrivingTime.h"
#import "RPStatisticsMileage.h"
#import "RPStatisticsSpeed.h"
#import "RPStatisticsPhone.h"

/// Represents a common info about user scoring.
@interface RPStatistics : NSObject<RPJSONSerializable> {
    
}

/// The user rating points.
@property (assign, nonatomic) NSInteger rating;

/// The user discount points in percentage.
@property (assign, nonatomic) NSInteger discount;

/// The common driving level.
@property (assign, nonatomic) NSInteger drivingLevel;

/// The common speed level.
@property (assign, nonatomic) NSInteger speedLevel;

/// The common mileage level.
@property (assign, nonatomic) NSInteger mileageLevel;

/// The phone usage level.
@property (assign, nonatomic) NSInteger phoneLevel;

/// The time of days level.
@property (assign, nonatomic) NSInteger timeOfDayScore;

@end
