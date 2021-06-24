//
//  RPELMBlocks.h
//  RaxelPulse
//
//  Created by Pavel on 10/30/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#ifndef RPELM_iOS_RPELMBlocks_h
#define RPELM_iOS_RPELMBlocks_h
#endif

@import CoreBluetooth;

@class RPELMPeripheral;


//Central
typedef void (^RPELMCharacteristicChangeBlock)(CBCharacteristic *characteristic,NSError *error);
typedef void (^RPELMDescriptorChangedBlock)(CBDescriptor * descriptor, NSError * error);
typedef void (^RPELMSpecifiedServiceUpdatedBlock)(CBService *service, NSError *error);
typedef void (^RPELMObjectChagedBlock)(NSError *error);
typedef void (^RPELMServicesUpdated)(NSArray *service);
typedef void (^RPELMPeripheralUpdatedBlock)(RPELMPeripheral *peripheral,NSDictionary *advertizeData);
typedef void (^RPELMPeripheralConnectionBlock)(RPELMPeripheral *peripheral, NSError*error);
typedef void (^RPELMPeripheralDisConnectionBlock)(RPELMPeripheral *peripheral, NSError*error);
typedef void (^RPELMPeripheralUpdateRSSIBlock)(NSError *error, NSNumber *RSSI);
typedef void (^RPELMCentralStateDidUpdatedBlock)(CBCentralManager *central);
typedef void (^RPELMBoolCallback)(BOOL success);


//Peripheral
typedef void (^RPELMPeripheralManagerStatedChangedBlock)(NSDictionary *state);
typedef void (^RPELMCentralSubscriptionBlock)(CBCentral *central, CBCharacteristic *characteristic);
typedef void (^RPELMCentralReadRequestBlock)(CBATTRequest *readRequest);
typedef void (^RPELMCentralWriteRequestBlock)(NSArray *writeRequests);
