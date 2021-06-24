//
//  RPCPermissionsWizard.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 15.10.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RPCPermissionsWizard : NSObject {
    
}

+ (id)returnInstance;
- (void)launchWithFinish:(void (^)(BOOL))completed;
- (Boolean)status;
- (Boolean)iOSpermission;
- (void)setupBluetoothEnabled;
- (void)setupHandlersWithUserNotificationResponce:(void (^)(BOOL, NSError *))completedNotification
                            motionManagerResponce:(void (^)(BOOL, NSError *))completedMotion
                          locationManagerResponce:(void (^)(CLAuthorizationStatus))completedLocation;

@end

NS_ASSUME_NONNULL_END
