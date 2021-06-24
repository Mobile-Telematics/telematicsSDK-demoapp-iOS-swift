//
//  RPELMTimeIntervals.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 27.11.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPJSONSerializable.h"

NS_ASSUME_NONNULL_BEGIN

@interface RPELMTimeIntervals : NSObject<RPJSONSerializable> {
}

@property (assign, nonatomic) NSInteger engineLoad;
@property (assign, nonatomic) NSInteger rpm;
@property (assign, nonatomic) NSInteger intakeAirTemperature;
@property (assign, nonatomic) NSInteger vehicleSpeed;
@property (assign, nonatomic) NSInteger acceleratorPedalPosition;
@property (assign, nonatomic) NSInteger engineCoolantTemperature;
@property (assign, nonatomic) NSInteger fuelLevel;
@property (assign, nonatomic) NSInteger fuelType;
@property (assign, nonatomic) NSInteger fuelConsumption;
@property (assign, nonatomic) NSInteger readTroubleCodes;
@property (assign, nonatomic) NSInteger vin;
@property (assign, nonatomic) NSInteger workProtocol;
@property (assign, nonatomic) NSInteger vehicleVoltage;
@property (assign, nonatomic) NSInteger vehicleMileage;
@property (assign, nonatomic) NSInteger pids;

- (void)setAllZero;

@end

NS_ASSUME_NONNULL_END
