//
//  RPAccuracyAuthorizationDelegate.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 16.10.2020.
//  Copyright © 2020 Raxel Telematics. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol RPAccuracyAuthorizationDelegate <NSObject>

- (void)wrongAccuracyAuthorization;

@end
