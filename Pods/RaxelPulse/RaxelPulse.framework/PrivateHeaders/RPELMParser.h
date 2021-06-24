//
//  RPELMParser.h
//  RaxelPulse
//
//  Created by Pavel on 10/30/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

@import Foundation;
@import CoreBluetooth;

NS_ASSUME_NONNULL_BEGIN

@interface RPELMParser : NSObject


+ (void)parsePROTOCOLResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;

#pragma mark ELM Reset

+ (void)parseResetDeviceResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;


#pragma mark ELM EchoOn

+ (void)parseOnEchoResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;


#pragma mark ELM HeadersOff

+ (void)parseOffHeadersResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;


#pragma mark ELM ProtocolOn

+ (void)parseOnAutoProtocolResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;


#pragma mark ELM RPM

+ (void)parseCarRPMResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;


#pragma mark ELM Distance

+ (void)parseCarAllDistanceResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;


#pragma mark ELM Speed

+ (void)parseCarSpeedResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;


#pragma mark ELM VIN

+ (void)parseVINResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;


#pragma mark ELM PIDs

+ (void)parsePIDsResponce:(CBCharacteristic*)characteristic response:(NSString*)value pidNumber:(NSString*)pid completion:(void (^)(NSString*convertedValue))completionHandler;


+ (void)parseTroubleCodesResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;

+ (void)parseCarVoltageResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;

+ (void)parseCarEngineLoadResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;

+ (void)parseFuelLevelResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;

+ (void)parseIntakeAirTemperatureResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;

+ (void)parseFuelTypeResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;

+ (void)parseOLOBResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;

+ (void)parseOLLOResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;

+ (void)parseOLOFResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;

+ (void)parseFuelConsumptionResponce:(CBCharacteristic*)characteristic response:(NSString*)value completion:(void (^)(NSString*convertedValue))completionHandler;

+ (NSString*)decToBinary:(NSUInteger)decInt;

+ (NSString*)calcLINHByMaf:(NSString*)maf andSpeed:(NSString*)speed;

+ (NSString*)calcLINHByMafInt:(int)maf andSpeed:(NSString*)speed;
    
@end

NS_ASSUME_NONNULL_END
