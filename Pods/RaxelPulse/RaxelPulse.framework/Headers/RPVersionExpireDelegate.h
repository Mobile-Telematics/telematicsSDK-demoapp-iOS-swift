//
//  RPVersionExpireDelegate.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 02.12.2020.
//  Copyright © 2020 Raxel Telematics. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol RPVersionExpireDelegate <NSObject>

- (void)onVersionExpire:(NSString *)version;

@end
