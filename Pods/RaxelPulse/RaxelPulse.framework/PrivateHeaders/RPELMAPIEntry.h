//
//  RPELMAPIEntry.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 26.11.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @related RPELMAPIEntry
 *
 * This is the brief comment.  This is the detailed comment.
 *
 * @param response The server response. Final type depends on the query.
 * @param errors The array with errors describing failure.
 */
typedef void(^RPELMAPIEntryCallback)(id _Nullable response, NSArray * _Nullable errors);
typedef void(^RPELMAPIEntryConnectCallback)(BOOL response, NSArray * _Nullable errors);

@interface RPELMAPIEntry : NSObject

+ (instancetype)instance;

#pragma mark - Tracks

/*!
 Requests all masks.
 @param callback Callback.
 */
- (void)getMasksWithCompletion:(RPELMAPIEntryCallback)callback;
- (void)getVehiclesWithCompletion:(RPELMAPIEntryCallback)callback;
- (void)getElmByUserCarsWithCompletion:(RPELMAPIEntryCallback)callback;
- (void)getVehicleIndicatorsWithCompletion:(RPELMAPIEntryCallback)callback;
- (void)postLinkCarWithCompletion:(RPELMAPIEntryCallback)callback ByElmId:(NSUInteger)elmId withCarToken:(NSString*)carToken andDeviceToken:(NSString*)deviceToken;
- (void)getDevicesWithCompletion:(RPELMAPIEntryCallback)callback ByCarToken:(NSString*)carToken;
- (void)processCars:(NSMutableArray*)cars processed:(NSMutableArray*)elmDevices errors:(NSMutableArray*)errors andCallBack:(RPELMAPIEntryCallback)callback;
- (void)postELMWithCompletion:(RPELMAPIEntryCallback)callback ElmUUID:(NSString*)uuid Name:(NSString*)name Manufacturer:(NSString*)manufacturer Model:(NSString*)model SoftwareVersion:(NSString*)softwareVersion;
- (void)checkCars:(NSMutableArray*)cars processed:(NSMutableArray*)processedCars errors:(NSMutableArray*)errors andCallBack:(RPELMAPIEntryCallback)callback;

@end

NS_ASSUME_NONNULL_END
