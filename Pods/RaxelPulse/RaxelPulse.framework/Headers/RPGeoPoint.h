//
//  RPGeoPoint.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 22.01.2020.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPJSONSerializable.h"

NS_ASSUME_NONNULL_BEGIN

@interface RPGeoPoint : NSObject<RPJSONSerializable>

@property (copy, nonatomic) NSNumber* latitude;
@property (copy, nonatomic) NSNumber* longitude;

@end

NS_ASSUME_NONNULL_END
