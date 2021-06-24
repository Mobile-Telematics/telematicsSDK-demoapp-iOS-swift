//
//  RPLocationDelegate.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 12.11.2020.
//  Copyright © 2020 Raxel Telematics. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol RPLocationDelegate <NSObject>

- (void)onLocationChanged:(CLLocation*)location;
- (void)onNewEvents:(NSMutableArray*)events;

@end
