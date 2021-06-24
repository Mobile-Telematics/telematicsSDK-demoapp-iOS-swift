//
//  RPELMEntry.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 21.11.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPELMItem.h"
#import "RPELMDelegate.h"
#import "RPELMSession.h"

/*!
 * @related RPAPIEntry
 *
 * This is the brief comment.  This is the detailed comment.
 *
 * @param response The server response. Final type depends on the query.
 * @param errors The error describing failure.
 */
typedef void(^RPELMEntryCallback)(id _Nullable response, NSArray * _Nullable errors);
typedef void(^RPELMAPIEntryConnectCallback)(BOOL response, NSArray * _Nullable errors);

typedef void (^EndBlock)(NSString* _Nullable rpm, NSString* _Nullable distance, NSString* _Nullable speed, NSString* _Nullable vin);
typedef void(^RPELMAPIEntryCallback)(id _Nullable response, NSArray * _Nullable errors);
typedef void(^RPELMCMDCallback)(id _Nullable response, NSArray * _Nullable errors);
typedef void (^CMDEndBlock)(BOOL success, NSArray * _Nullable errors);
typedef void(^RPELMListCallback)(BOOL success);

NS_ASSUME_NONNULL_BEGIN

@interface RPELMEntry : NSObject {
    NSMutableArray *connectedDeviceArray;
    NSMutableArray *findDeviceArray;
    NSMutableArray *masks;
}

@property (weak, nonatomic) id<RPELMDelegate> elmDelegate;
/// Array of ELMItem
@property (strong, nonatomic) NSArray<RPELMItem *> *items;
@property (strong, nonatomic) NSTimer *elmCMDRTimer;
@property (strong, nonatomic) NSTimer *elmConnectTimer;
@property (strong, nonatomic) NSTimer *elmInnerConnectTimer;
@property (strong, nonatomic) NSString *uuid;
@property (strong, nonatomic) NSString *vtoken;
@property (assign, nonatomic) Boolean blocked;
@property (assign, nonatomic) BOOL innerScanExecuted;
@property (copy, nonatomic) RPELMListCallback innercallback;
@property (copy, nonatomic) RPELMListCallback innerdisconnectCallback;

+ (instancetype)instance;

/*!
 @param callback Completion handler with ELMItem as a response.
 */
- (void)getELMDevicesWithCompletion:(RPELMEntryCallback)callback;

- (void)getVehicles:(RPELMEntryCallback)callback;
//- (void)requestCarConnectionParametersPeripheral:(EndBlock)completionParametersBlock;
- (void)connectDevice:(NSString*)uuid vehicleToken:(NSString*)carToken withCompletion:(RPELMAPIEntryConnectCallback)callback;
//- (void)postLinkCar:(RPELMEntryCallback)callback ByElmId:(NSUInteger)elmId withCarToken:(NSString*)carToken andDeviceToken:(NSString*)deviceToken;
- (BOOL)isNeedELMCMD;
- (void)getConnectedELM:(RPELMListCallback)callback;
- (void)makeCMDList:(NSMutableArray*)cmdList;
- (id)getVI;
- (Boolean)getCMDCount;
- (void)pushScan:(RPELMListCallback)callback disconnectCallback:(nullable RPELMListCallback)disconnectCallback showAlert:(Boolean)showAlert;
- (void)pushScan:(RPELMListCallback)callback;
- (RPELMSession*)getLastSession;
- (void)clearELM;
- (void)stopScan;
- (void)clearELMStates;

@end

NS_ASSUME_NONNULL_END
