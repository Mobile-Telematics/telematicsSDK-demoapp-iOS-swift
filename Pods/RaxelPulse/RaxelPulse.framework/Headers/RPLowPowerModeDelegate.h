//
//  RPLowPowerModeDelegate.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 20.10.2020.
//  Copyright © 2020 Raxel Telematics. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol RPLowPowerModeDelegate <NSObject>

- (void)lowPowerMode:(Boolean)state;

@end
