//
//  RPTrackPointProcessed.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPTrackPointBase.h"

typedef NS_ENUM(NSInteger, RPSpeedType) {
    RPSpeedTypeNormal,
    RPSpeedTypeMedium,
    RPSpeedTypeHigh
};

typedef NS_ENUM(NSInteger, RPAlertType) {
    RPAlertTypeNone,
    RPAlertTypeAcceleration,
    RPAlertTypeDeceleration
};


@interface RPTrackPointProcessed : RPTrackPointBase {
    
}

@property (assign, nonatomic) RPAlertType alertType;
@property (assign, nonatomic) double      alertValue;
@property (assign, nonatomic) RPSpeedType speedType;
@property (assign, nonatomic) double      speedLimit;
@property (assign, nonatomic) double      phoneUsage;
@property (assign, nonatomic) BOOL        cornering;



#pragma mark - Utils

+ (RPSpeedType)speedTypeFromString:(NSString *)string;
+ (RPAlertType)alertTypeFromString:(NSString *)string;

@end
