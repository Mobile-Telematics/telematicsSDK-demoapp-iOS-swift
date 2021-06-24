//
//  RPELMRequests.h
//  RaxelPulse
//
//  Created by Pavel on 10/30/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

@import Foundation;
@import CoreBluetooth;
#import "RPELMPeripheral.h"
#import "RPELMParser.h"


NS_ASSUME_NONNULL_BEGIN

extern NSString *const cmdEngineLoadELM;
extern NSString *const cmdRPMELM;
extern NSString *const cmdIntakeAirTemperatureELM;
extern NSString *const cmdVehicleSpeedELM;
extern NSString *const cmdAcceleratorPedalPositionELM;
extern NSString *const cmdEngineCoolantTemperatureELM;
extern NSString *const cmdfuelConsumptionELM;
extern NSString *const cmdOLOBELM;
extern NSString *const cmdOLLOELM;
extern NSString *const cmdFuelLevelELM;
extern NSString *const cmdFuelTypeELM;
extern NSString *const cmdReadTroubleCodesELM;
extern NSString *const cmdVinELM;
extern NSString *const cmdWorkProtocolELM;
extern NSString *const cmdVehicleVoltageELM;
extern NSString *const cmdVehicleMileageELM;

extern NSString *const cmdPIDsELM;
extern NSString *const cmdResetELM;
extern NSString *const cmdOnEchoELM;
extern NSString *const cmdOffHeadersELM;
extern NSString *const cmdOnAutoProtocolELM;
//extern NSString *const cmdRPMELM;
//extern NSString *const cmdVehicleMileageELM;
//extern NSString *const cmdVehicleSpeedELM;
//extern NSString *const cmdVinELM;
//extern NSString *const clearAllDataRegisterNewUserELM;

extern NSString *const cmdPID0100;
extern NSString *const cmdPID0120;
extern NSString *const cmdPID0140;
extern NSString *const cmdPID0160;
extern NSString *const cmdPID0180;
extern NSString *const cmdPID01A0;
extern NSString *const cmdPID01C0;
extern NSString *const cmdPID01E0;

extern NSString *const cmdPID0900;
extern NSString *const cmdPID0920;
extern NSString *const cmdPID0940;
extern NSString *const cmdPID0960;
extern NSString *const cmdPID0980;
extern NSString *const cmdPID09A0;
extern NSString *const cmdPID09C0;
extern NSString *const cmdPID09E0;

@interface RPELMRequests : NSObject

+ (id)sharedInstance;

+ (void)getMainRequestToELM:(NSArray<CBCharacteristic*> *)characteristic peripheral:(RPELMPeripheral*)connectedPeripheral command:(NSString*)commandString completion:(void (^)(NSString *commandResult, BOOL success))completionCommandResult;

- (void)askForPIDs:(NSArray<CBCharacteristic*> *)characteristic peripheral:(RPELMPeripheral*)connectedPeripheral completion:(void (^)(NSString *commandResult))completionCommandResult;

@end

NS_ASSUME_NONNULL_END
