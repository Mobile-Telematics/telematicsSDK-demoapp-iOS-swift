//
//  RPVehicle.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 26.11.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPJSONSerializable.h"

NS_ASSUME_NONNULL_BEGIN

@interface RPVehicle : NSObject<RPJSONSerializable> {
}

@property (strong, nonatomic) NSString *company;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *plateNumber;
@property (strong, nonatomic) NSString *vin;
@property (strong, nonatomic) NSString *manufacturer;
@property (strong, nonatomic) NSString *model;
@property (strong, nonatomic) NSString *type;
@property (strong, nonatomic) NSString *carYear;
@property (strong, nonatomic) NSString *specialMarks;
@property (strong, nonatomic) NSString *nvic;
@property (strong, nonatomic) NSString *initialMilage;
@property (strong, nonatomic) NSString *vehicleIdString;
@property (strong, nonatomic) NSString *token;
@property (assign, nonatomic) BOOL isELMRegistered;

@end

NS_ASSUME_NONNULL_END
