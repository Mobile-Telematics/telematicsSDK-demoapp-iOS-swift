//
//  RPELMManager.h
//  RaxelPulse
//
//  Created by Pavel on 10/30/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

@import Foundation;
@import CoreBluetooth;

@interface RPELMManager : NSObject

@property (nonatomic, strong) CBPeripheral *connectPeripheral; //current Connected device

+ (RPELMManager *)sharedRPELMManager;

@end
