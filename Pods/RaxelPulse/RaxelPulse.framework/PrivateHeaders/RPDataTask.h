//
//  RPDataTask.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPTrackProcessed.h"
#import "RPInnerTag.h"

@class RPDataTask;
@class RPRealTimeLocationModel;

FOUNDATION_EXPORT NSString *const RPDataTaskIdentifierHeartbeat;
FOUNDATION_EXPORT NSString *const RPDataTaskIdentifierGetMultipleTracks;
FOUNDATION_EXPORT NSString *const RPDataTaskIdentifierGetSingleTrack;
FOUNDATION_EXPORT NSString *const RPDataTaskIdentifierGetTrackOriginDict;
FOUNDATION_EXPORT NSString *const RPDataTaskIdentifierChangeTrackOrigin;
FOUNDATION_EXPORT NSString *const RPDataTaskIdentifierShareTrack;

FOUNDATION_EXPORT NSString *const RPDataTaskIdentifierStatisticsMain;

typedef void(^RPDataTaskCompletionBlock)(RPDataTask *);


@interface RPDataTask : NSObject {
    
}
// incoming params
@property (readonly, nonatomic) NSString     *identifier;
@property (readonly, nonatomic) NSURLRequest *request;
@property (readonly, nonatomic) Class        responseClass;
@property (copy, nonatomic)     RPDataTaskCompletionBlock onComplete;
// response
@property (readonly, nonatomic) id            data;
@property (readonly, nonatomic) NSURLResponse *response;
@property (readonly, nonatomic) NSError       *error;
@property (readonly, nonatomic) id            responseObject;
// status
@property (readonly, nonatomic, getter=isCompleted) BOOL completed;
@property (readonly, nonatomic, getter=isCancelled) BOOL cancelled;


#pragma mark - Root

- (instancetype)initWithRequest:(NSURLRequest *)request identifier:(NSString *)identifier;
- (instancetype)initWithRequest:(NSURLRequest *)request
                     identifier:(NSString *)identifier
                  responseClass:(Class)responseClass;
- (instancetype)initWithRequest:(NSURLRequest *)request
                     identifier:(NSString *)identifier
                  responseClass:(Class)responseClass
                        session:(NSURLSession *)session;
- (instancetype)init NS_UNAVAILABLE;


#pragma mark - Common

- (void)resume;
- (void)cancel;


#pragma mark - Tracks

+ (RPDataTask *)getTracksByIds:(NSArray<NSString *>*) idsList;
+ (RPDataTask *)getTracksShortListWithOffset:(NSUInteger)offset limit:(NSUInteger)limit startDate:(NSDate *)startDate endDate:(NSDate *)endDate;
+ (RPDataTask *)getTracksWithOffset:(NSUInteger)offset
                              limit:(NSUInteger)limit
                          startDate:(NSDate *)startDate
                            endDate:(NSDate *)endDate;
+ (RPDataTask *)getTrackWithTrackToken:(NSString *)token;

+ (RPDataTask *)getSharedTrackWithTrackToken:(NSString *)token;

+ (RPDataTask *)shareTrackWithToken:(NSString *)token shareType:(NSString *)shareType;

#pragma mark - Track Origin

+ (RPDataTask *)getTrackOriginDict;
+ (RPDataTask *)changeTrackOrigin:(NSString *)originCode forTrackToken:(NSString *)token;


#pragma mark - Ping

typedef void(^RPDataTaskCallback)(Boolean success);

+ (void)heartbeat: (NSString *)reason callback:(nullable RPDataTaskCallback)callback;
+ (void)heartbeat: (NSString *)reason rtlData:(nullable NSMutableDictionary*)rtlData callback:(nullable RPDataTaskCallback)callback;
//+ (RPDataTask *)heartbeat:(NSString *)reason;
//+ (RPDataTask *)heartbeat: (NSString *)reason rtlData:(nullable NSMutableDictionary*)rtlData;

#pragma mark - Realtime

+ (RPDataTask *)sendLocation:(RPRealTimeLocationModel *)model;

#pragma mark - RTL

+ (RPDataTask *)rtlData:(nullable NSMutableDictionary*)rtlData;

#pragma mark - ScheduleConfig

+ (RPDataTask *)getSchedule;

#pragma mark - Configs

+ (RPDataTask *)getRTDsettings;

#pragma mark - Statistics

+ (RPDataTask *)getMainStatistics:(NSString*)tag;
+ (RPDataTask *)getDrivingStatisticsForPeriod:(NSString *)period tag:(NSString*)tag;
+ (RPDataTask *)getDrivingTimeStatisticsForPeriod:(NSString *)period tag:(NSString*)tag;
+ (RPDataTask *)getMileageStatisticsForPeriod:(NSString *)period tag:(NSString*)tag;
+ (RPDataTask *)getSpeedStatisticsForPeriod:(NSString *)period tag:(NSString*)tag;
+ (RPDataTask *)getPhoneStatisticsForPeriod:(NSString *)period tag:(NSString*)tag;

#pragma mark - ELM

+ (RPDataTask *)postElmUUID:(NSString*)uuid Name:(NSString*)name Manufacturer:(NSString*)manufacturer Model:(NSString*)model SoftwareVersion:(NSString*)softwareVersion;
+ (RPDataTask *)getElmByUserCars:(NSString*)vehicleToken;
+ (RPDataTask *)getElmByUserCars;

#pragma mark - Vehicles

+ (RPDataTask *)getVehicles;

#pragma mark - Masks

+ (RPDataTask *)getMasks;

#pragma mark - VehicleIndicators

+ (RPDataTask *)getVehicleIndicators;

#pragma mark - LinkCar

+ (RPDataTask *)postLinkCarByElmId:(NSUInteger)elmId withCarToken:(NSString*)carToken andDeviceToken:(NSString*)deviceToken;

#pragma mark - DevicesByCarToken

+ (RPDataTask *)getDevicesByCarToken:(NSString*)carToken;

#pragma mark - RitchTags

+ (RPDataTask *)getTags:(NSString *)trackToken;
+ (RPDataTask *)removeTags:(NSArray<RPTag *>*)tags from:(NSString *)trackToken;
+ (RPDataTask *)addTags:(NSArray<RPTag *>*)tags to:(NSString *)trackToken;

+ (RPDataTask *)getFutureTag:(NSInteger)timestamp;
+ (RPDataTask *)removeFutureTag:(RPTag *)tag;
+ (RPDataTask *)addFutureTag:(RPTag *)tag;
+ (RPDataTask *)removeAllFutureTag;
+ (RPDataTask *)addFutureiTag:(RPInnerTag *)itag;
+ (RPDataTask *)removeFutureiTag:(RPInnerTag *)itag;


+ (RPDataTask *)sendEvent:(NSDictionary *)params;

@end
