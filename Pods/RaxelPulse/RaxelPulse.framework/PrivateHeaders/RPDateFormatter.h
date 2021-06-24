//
//  RPDateFormatter.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface RPDateFormatter : NSDateFormatter {
    
}

#pragma mark - Root

+ (instancetype)iso8601;
+ (instancetype)iso8601Milliseconds;
+ (instancetype)isoMilliseconds;

@end
