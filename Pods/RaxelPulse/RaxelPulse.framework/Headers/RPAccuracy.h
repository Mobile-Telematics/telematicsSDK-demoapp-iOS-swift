//
//  RPAccuracy.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 30.03.2020.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPJSONSerializable.h"

NS_ASSUME_NONNULL_BEGIN

@interface RPAccuracy : NSObject<RPJSONSerializable>

@property (copy, nonatomic) NSNumber* max;
@property (copy, nonatomic) NSNumber* min;
@property (copy, nonatomic) NSNumber* quantile_95;
@property (copy, nonatomic) NSNumber* median;
@property (copy, nonatomic) NSNumber* quantile_05;

@end

NS_ASSUME_NONNULL_END
