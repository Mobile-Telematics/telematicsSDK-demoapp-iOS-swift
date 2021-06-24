//
//  RPLogDelegate.h
//  RaxelPulse
//
//  Created by Igor Nabokov on 18/09/2018.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RPLogDelegate <NSObject>

- (void)logEvent:(NSString *)event;
- (void)logWarning:(NSString *)warning;

@end

NS_ASSUME_NONNULL_END
