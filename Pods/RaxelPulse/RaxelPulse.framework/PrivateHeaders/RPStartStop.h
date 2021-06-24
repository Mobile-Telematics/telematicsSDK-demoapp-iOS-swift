//
//  RPStartStop.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 24.08.2020.
//  Copyright © 2020 Raxel Telematics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPTracker+Private.h"

NS_ASSUME_NONNULL_BEGIN

@interface RPStartStop : NSObject

typedef NS_ENUM(NSUInteger, RPStartReason) {
    RPNoneStartState,
    RPRestartByMemoryDetected,
    RPLaunchDetected,
    RPMotionDetected,
    RPRestartByElmDeviceDisconnected,
    RPElmDeviceConnected,
    RPManualStart,
    RPRestartByTimeChange
};

typedef NS_ENUM(NSUInteger, RPStopReason) {
    RPNoneStopState,
    RPStopTrackingDueToServerInstruction,
    RPStopTrackingManually,
    RPHighSpeedTimeout,
    RPLowSpeedTimeout,
    RPStopByAutomaticStop,
    RPStopByMemoryWarningReceived,
    RPStopByApplicationWillTerminate,
    RPStopByTimeChange
};

+ (instancetype)instance;
+ (BOOL)isSDKEnabled;
+ (BOOL)isUploadEnabled;
/// Current track stop reason.
@property (readonly, nonatomic) RPStopReason stopReason;
/// Current track start reason.
@property (readonly, nonatomic) RPStartReason startReason;

- (void)startWithReason:(NSString*)reason;
- (void)stopWithReason:(NSString*)reason;
- (void)checkShedule:(NSInteger)timestamp;
- (NSString*)startScheduleNameByType:(RPStartReason)reason;
- (void)refreshSchedulerConfigIfNeed;

@end

NS_ASSUME_NONNULL_END
