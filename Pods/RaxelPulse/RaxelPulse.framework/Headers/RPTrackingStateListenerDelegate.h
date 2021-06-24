//
//  RPTrackingStateListenerDelegate.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 02.03.2020.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RPTrackingStateListenerDelegate <NSObject>

- (void)trackingStateChanged:(Boolean)state;

@end

NS_ASSUME_NONNULL_END
