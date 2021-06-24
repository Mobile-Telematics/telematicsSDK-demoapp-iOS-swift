//
//  RPBackgroundTask.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface RPBackgroundTask : NSObject {
    
}

@property (readonly, nonatomic) UIBackgroundTaskIdentifier taskId;
@property (readonly, nonatomic) NSUInteger taskRetainCount;


#pragma mark - Root

+ (instancetype)instance;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;


#pragma mark - Common

+ (void)beginBackgroundTask;
+ (void)endBackgroundTask;

@end
