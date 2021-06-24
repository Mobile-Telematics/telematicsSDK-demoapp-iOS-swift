//
//  RPELMDelegate.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 05.12.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol RPELMDelegate <NSObject>

/// Callback for elm.
- (void)elmNotification:(NSString*) message;

@end
