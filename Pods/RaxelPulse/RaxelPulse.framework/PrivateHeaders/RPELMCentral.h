//
//  RPELMCentral.h
//  RaxelPulse
//
//  Created by Pavel on 10/30/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "RPELMBlocks.h"


@class RPELMPeripheral;

@interface RPELMCentral : NSObject

typedef void(^RPEndCallback)(BOOL success);

@property (nonatomic, strong, readonly) NSMutableArray *peripherals;
@property (nonatomic, readonly) CBManagerState state;
@property (nonatomic, strong) dispatch_queue_t queue;
@property (nonatomic, strong) CBCentralManager * manager;
@property (nonatomic, assign) BOOL canWorking;

@property (nonatomic, copy) RPELMPeripheralUpdatedBlock onPeripheralUpdated;
@property (nonatomic, copy) RPELMPeripheralDisConnectionBlock disConnectionBlock;
@property (nonatomic, copy) RPELMCentralStateDidUpdatedBlock centralStateUpdateBlock;
@property (nonatomic, copy) RPELMBoolCallback cancelConnection;
@property (nonatomic, copy) RPEndCallback endConnection;

@property (nonatomic, assign) BOOL scanStarted;
@property (nonatomic, strong) NSMutableArray * connectingPeripherals;
@property (nonatomic, strong) NSMutableArray * connectedPeripherals;
@property (nonatomic, strong) NSDictionary * initializedOptions;
@property (nonatomic, strong) NSMutableDictionary * connectionFinishBlocks;
@property (nonatomic, strong) NSMutableDictionary * disconnectionFinishBlocks;


@property (strong, nonatomic) NSTimer *elmConnectTimer;
@property (nonatomic, strong) NSArray<CBPeripheral *> *restoredPeripheral;


#pragma mark Initial Methods

+ (RPELMCentral *)sharedRPELMCentral;
+ (RPELMCentral *)sharedRPELMCentralWithCallback:(nullable RPEndCallback)connectCallback showAlert:(Boolean)showAlert;
- (instancetype)initWithQueue:(dispatch_queue_t)queue;
- (instancetype)initWithQueue:(dispatch_queue_t)queue options:(NSDictionary *)options;


#pragma mark Scan or StopScan methods

/**
 Scan Peripheral with Services

 *  @param serviceUUIDs scan service uuids
 *  @param options options
 *  @param onUpdateBlock call back
 */
- (void)scanPeripheralWithServices:(NSArray *)serviceUUIDs options:(NSDictionary *)options onUpdated:(RPELMPeripheralUpdatedBlock) onUpdateBlock;
- (void)stopScan;


#pragma mark Establishing or Canceling Connection

- (void)connectPeripheral:(RPELMPeripheral *)peripheral options:(NSDictionary *)options onFinished:(RPELMPeripheralConnectionBlock)finished callback:(nullable RPELMBoolCallback)callback;
- (void)cancelPeripheralConnection:(RPELMPeripheral *)peripheral onFinished:(RPELMPeripheralConnectionBlock) ondisconnected;


#pragma mark Retrieving Lists of Peripherals

- (NSArray *)retrieveConnectedPeripheralsWithServices:(NSArray *)serviceUUIDs NS_AVAILABLE(NA, 7_0);
- (NSArray *)retrievePeriphearlsWithIdentifiers:(NSArray *)identifiers NS_AVAILABLE(NA, 7_0);


#pragma mark VIN Helpers

+ (NSString *)stringASCIIFromHex:(NSString *)str;

- (void)disconectPeripheral:(RPELMPeripheral *)peripheral;
@end
