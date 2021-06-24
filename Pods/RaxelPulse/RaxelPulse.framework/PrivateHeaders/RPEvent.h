//
//  RPEvent.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 30.12.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPJSONSerializable.h"
#import "RPEventPoint.h"

NS_ASSUME_NONNULL_BEGIN

@interface RPEvent : NSObject<RPJSONSerializable> {
    
}

@property (copy, nonatomic) NSString* type;
@property (copy, nonatomic) NSArray<RPEventPoint*>* points;

- (void)setAllZero;

@end

NS_ASSUME_NONNULL_END
