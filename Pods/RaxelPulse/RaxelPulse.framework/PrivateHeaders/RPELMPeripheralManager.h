//
//  RPELMPeripheralManager.h
//  RaxelPulse
//
//  Created by Pavel on 10/30/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

@import Foundation;
#import "RPELMBlocks.h"

@interface RPELMPeripheralManager : NSObject

@property (nonatomic, readonly) BOOL isAdvertizing;
@property (nonatomic, readonly) CBManagerState state;
@property (nonatomic, copy) RPELMObjectChagedBlock onStateUpdated;
@property (nonatomic, copy) RPELMPeripheralManagerStatedChangedBlock onWillRestoreState;
@property (nonatomic, copy) RPELMCentralSubscriptionBlock onSubscribedBlock;
@property (nonatomic, copy) RPELMCentralSubscriptionBlock onUnsubscribedBlock;
@property (nonatomic, copy) RPELMCentralReadRequestBlock onReceivedReadRequest;
@property (nonatomic, copy) RPELMCentralWriteRequestBlock onReceiveWriteRequest;
@property (nonatomic, copy) RPELMObjectChagedBlock onReadToUpdateSubscribers;

@property (nonatomic, strong) NSArray *services;
@property (nonatomic, strong) NSMutableArray *addedServices;
@property (nonatomic, strong) CBPeripheralManager * peripheralManager;


#pragma mark Init Methods

+ (RPELMPeripheralManager *)sharedRPELMPeripheralManager;


- (instancetype)initWithQueue:(dispatch_queue_t)queue;
- (instancetype)initWithQueue:(dispatch_queue_t)queue options:(NSDictionary *)options NS_AVAILABLE(NA, 7_0);


#pragma mark Adding and Removing Services

- (void)addService:(CBMutableService *)service onFinish:(RPELMSpecifiedServiceUpdatedBlock) onfinish;
- (void)removeService:(CBMutableService *)service;
- (void)removeAllServices;


#pragma mark Managing Advertising

- (void)startAdvertising:(NSDictionary *)advertisementData onStarted:(RPELMObjectChagedBlock) onstarted;
- (void)stopAdvertising;


#pragma mark Sending Updates of a Characteristic’s Value

- (BOOL)updateValue:(NSData *)value forCharacteristic:(CBMutableCharacteristic *)characteristic onSubscribedCentrals:(NSArray *)centrals;


#pragma mark Responding to Read and Write Requests

- (void)respondToRequest:(CBATTRequest *)request withResult:(CBATTError)result;


#pragma mark Setting Connection Latency

- (void)setDesiredConnectionLatency:(CBPeripheralManagerConnectionLatency)latency forCentral:(CBCentral *)central;


@end
