//
//  RPELMStoredPeripherals.h
//  RaxelPulse
//
//  Created by Pavel on 10/30/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

@import Foundation;
@import CoreBluetooth;

@interface RPELMStoredPeripherals : NSObject

+ (void)initializeStorage;

+ (NSArray *)genIdentifiers;

+ (void)saveUUID:(NSUUID *)UUID;

+ (void)deleteUUID:(NSUUID *)UUID;

@end
