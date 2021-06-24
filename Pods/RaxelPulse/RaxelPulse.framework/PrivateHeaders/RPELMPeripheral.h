//
//  RPELMPeripheral.h
//  RaxelPulse
//
//  Created by Pavel on 10/30/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "RPELMBlocks.h"

@interface RPELMPeripheral : NSObject

@property (nonatomic, strong, readonly) CBPeripheral * peripheral;
@property (nonatomic) NSArray * services;
@property (nonatomic, strong) NSUUID *identifier;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSNumber *RSSI; //should use readRSSIOnFinish replace it.
@property (readonly) CBPeripheralState state;
@property (nonatomic, copy) RPELMServicesUpdated onServiceModified;
@property (nonatomic, copy) RPELMObjectChagedBlock onNameUpdated;
@property (nonatomic, copy) RPELMCharacteristicChangeBlock notificationStateChanged;
@property (nonatomic, copy) RPELMPeripheralConnectionBlock onConnectionFinished;
@property (nonatomic, copy) RPELMPeripheralConnectionBlock onDisconnected;


#pragma mark Initial Methods

- (instancetype)initWithPeripheral:(CBPeripheral *) peripheral;


#pragma mark Discovery services

- (void)discoverServices:(NSArray *)serviceUUIDs onFinish:(RPELMObjectChagedBlock)discoverFinished;
- (void)discoverIncludedServices:(NSArray *)includedServiceUUIDs forService:(CBService *)service onFinish:(RPELMSpecifiedServiceUpdatedBlock) finished;


#pragma mark Discovering Characteristics and Characteristic Descriptors

- (void)discoverCharacteristics:(NSArray *)characteristicUUIDs forService:(CBService *)service onFinish:(RPELMSpecifiedServiceUpdatedBlock) onfinish;
- (void)discoverDescriptorsForCharacteristic:(CBCharacteristic *)characteristic onFinish:(RPELMCharacteristicChangeBlock) onfinish;


#pragma mark Reading Characteristic and Characteristic Descriptor Values

- (void)readValueForCharacteristic:(CBCharacteristic *)characteristic onFinish:(RPELMCharacteristicChangeBlock) onUpdate;
- (void)readValueForDescriptor:(CBDescriptor *)descriptor onFinish:(RPELMDescriptorChangedBlock) onUpdate;


#pragma mark Writing Characteristic and Characteristic Descriptor Values

- (void)writeValue:(NSData *)data forCharacteristic:(CBCharacteristic *)characteristic type:(CBCharacteristicWriteType)type onFinish:(RPELMCharacteristicChangeBlock) onfinish;
- (void)writeValue:(NSData *)data forDescriptor:(CBDescriptor *)descriptor onFinish:(RPELMDescriptorChangedBlock) onfinish;


#pragma mark Setting Notifications for a Characteristic’s Value

- (void)setNotifyValue:(BOOL)enabled forCharacteristic:(CBCharacteristic *)characteristic onUpdated:(RPELMCharacteristicChangeBlock) onUpdated;
- (void)removeNotify:(CBCharacteristic *)characteristic;


#pragma mark ReadRSSI

- (void)readRSSIOnFinish:(RPELMPeripheralUpdateRSSIBlock)onUpdated;


#pragma mark Cleanup

- (void)cleanup;

@end
