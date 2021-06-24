//
//  RPSystem.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPSecure.h"
@class RPRealTimeLocatorSettings;

#ifdef RPSECURE

#define RPSystemUpdatedNotification akjnasdb3
#define sendLocalNotificationWithMessage ajsdna7h

#endif

FOUNDATION_EXPORT NSString *const RPSystemUpdatedNotification;


@interface RPSystem : NSObject {
    
}

@property (readonly, nonatomic) BOOL isTrackingAllowed;
@property (readonly, nonatomic) BOOL isTrackingAllowedByServer;
@property (readonly, nonatomic) BOOL isTrackingAllowedByUser;

@property (nonatomic)   BOOL     serverDisableLogs;
@property (nonatomic)   BOOL     serverDisableTracking;
@property (nonatomic)   BOOL     userDisableTracking;
@property (copy, nonatomic) RPRealTimeLocatorSettings *realTimeLocatorSettings;
@property (strong, nonatomic)   NSString *virtualDeviceToken;
@property (readonly, nonatomic) BOOL     isVirtualDeviceTokenValid;
@property (readonly, nonatomic) NSDictionary<NSString *, NSString *> *systemStatus;
@property (nonatomic)  NSInteger startTrackingCount;

#pragma mark - Root

+ (instancetype)instance;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (void)incrementStartTrackingCount;


#pragma mark Static methods

+ (BOOL)isVirtualDeviceTokenValid:(NSString *)token;

#pragma mark - Local Notifications

+ (void)sendLocalNotificationWithMessage:(NSString *)message;

@end
