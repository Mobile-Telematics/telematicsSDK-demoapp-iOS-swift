//
//  RPSchedule.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 25.08.2020.
//  Copyright © 2020 Raxel Telematics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPJSONSerializable.h"
#import "RPStartStop.h"

typedef void(^RPAllowCallback)(BOOL success, NSString * _Nonnull theReason);

NS_ASSUME_NONNULL_BEGIN
@interface RPSchedule : NSObject<RPJSONSerializable> {
    NSMutableDictionary<NSString*, NSMutableArray*> *allowList;
    Boolean armed;
}

@property (readonly, nonatomic) RPStopReason stopReason;

+ (instancetype)instance;

- (Boolean)checkShedule:(NSString*)type time:(NSInteger)timestamp;
- (NSInteger)checkSchedule;
- (void)recalculate:(id)json;
- (void)checkStartShedule:(NSString*)type time:(NSInteger)timestamp reason:(NSString*)theReason callback:(nullable RPAllowCallback)callback;
- (void)armedOffline;

@end

NS_ASSUME_NONNULL_END
