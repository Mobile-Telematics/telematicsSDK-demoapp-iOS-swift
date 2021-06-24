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

/// Represents info about Driving Time(day or night etc.) user scoring.
@interface RPStatisticsDrivingTime : NSObject<RPJSONSerializable> {
    
}

/// Diving time scoring.
@property (assign, nonatomic) NSInteger ratingTimeOfDay;

/// Average Daily Driving in min.
@property (assign, nonatomic) NSInteger dailyAverageDrivingTimeMin;

/// Total Driving Time in hours.
@property (assign, nonatomic) NSInteger totalDriveTimeHours;

/// Counts hours driving in night.
@property (assign, nonatomic) NSInteger nightHours;

/// Counts rush hours driving.
@property (assign, nonatomic) NSInteger rushHours;

/// Night hours diagram for period in hrs/date.
@property (strong, nonatomic) NSArray<RPStatisticsPoint *> *nightHoursDiagram;

/// Rush hours diagram for period in hrs/time.
@property (strong, nonatomic) NSArray<RPStatisticsPoint *> *rushHoursDiagram;

/// Day hours diagram for period in hrs/time.
@property (strong, nonatomic) NSArray<RPStatisticsPoint *> *dayHoursDiagram;

@end
