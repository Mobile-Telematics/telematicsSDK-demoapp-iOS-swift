//
//  RPRTDLDelegate.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 01.05.2020.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol RPRTDLDelegate <NSObject>

- (void)heartbeatSended:(Boolean)state success:(Boolean)success;
- (void)rtldColecctedData:(Boolean)state;

@end
