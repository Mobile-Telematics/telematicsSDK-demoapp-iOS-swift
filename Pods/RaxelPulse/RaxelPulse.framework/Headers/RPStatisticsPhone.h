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

/// Represents info about Phone Usage detail user scoring.
@interface RPStatisticsPhone : NSObject<RPJSONSerializable> {
    
}

/// Phone Usage while driving scoring.
@property (assign, nonatomic) NSInteger phoneRating;

/// Phone Usage while driving in min.
@property (assign, nonatomic) NSInteger usingPhoneWhileDriving;

/// Phone Usage while driving with speed > 20km/h in min.
@property (assign, nonatomic) NSInteger usingPhoneWhileDrivingOverSpeedLimit;

/// Phone Usage while driving diagram min/date.
@property (strong, nonatomic) NSArray<RPStatisticsPoint *> *usingPhoneWhileDrivingDiagram;

/// Phone Usage while driving with speed > 20km/h diagram min/date.
@property (strong, nonatomic) NSArray<RPStatisticsPoint *> *usingPhoneWhileDrivingOverSpeedLimitDiagram;

@end
