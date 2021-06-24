//
//  RPTagsServerStateDelegate.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03.02.2021.
//  Copyright © 2021 Raxel Telematics. All rights reserved.
//




#import <Foundation/Foundation.h>
#import "RPTag.h"

@protocol RPTagsServerStateDelegate <NSObject>


typedef NS_ENUM(NSUInteger, RPTagStatus) {
    SUCCESS,
    OFFLINE,
    ERROR_WRONG_TIME,
    ERROR_TAG_OPERATION,
    ERROR_INVALIND_TAG_SPECIFIED
};

- (void)addTag:(RPTagStatus)status tag:(RPTag*)tag timestamp:(NSInteger)timestamp;
- (void)removeAll:(RPTagStatus)status timestamp:(NSInteger)timestamp;
- (void)deleteTag:(RPTagStatus)status tag:(RPTag*)tag timestamp:(NSInteger)timestamp;
- (void)getTags:(RPTagStatus)status tags:(id)tags timestamp:(NSInteger)timestamp;

@end
