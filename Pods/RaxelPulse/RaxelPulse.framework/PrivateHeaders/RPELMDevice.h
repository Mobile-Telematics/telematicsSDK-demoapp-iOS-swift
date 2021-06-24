//
//  RPELMDevice.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 28.11.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPJSONSerializable.h"

NS_ASSUME_NONNULL_BEGIN

@interface RPELMDevice : NSObject<RPJSONSerializable> {
}

@property (strong, nonatomic) NSString *Id;
@property (strong, nonatomic) NSString *uuid;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *companyId;
@property (strong, nonatomic) NSString *manufacturer;
@property (strong, nonatomic) NSString *model;
@property (strong, nonatomic) NSString *softwareVersion;
@property (strong, nonatomic) NSString *mac;
@property (strong, nonatomic) NSString* vehicleToken;

- (instancetype)initWithCD:(id)json;

@end

NS_ASSUME_NONNULL_END
