//
//  RPAPIEntry.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPSecure.h"
#import "RPTag.h"
#import "RPTagsServerStateDelegate.h"
#import "RPInnerTag.h"

/*!
 * @related RPAPIEntry
 *
 * This is the brief comment.  This is the detailed comment.
 *
 * @param response The server response. Final type depends on the query.
 * @param error The error describing failure.
 */
typedef void(^RPAPIEntryCallback)(id response, NSError *error);
typedef void(^RPAPIVOneEntryCallback)(id response, NSArray *error);
typedef void(^RPAPIVTwoEntryCallback)(id count, NSArray *error);
typedef void(^RPAPIITagCallback)(RPTagStatus status, RPTag *tag, NSInteger timestamp);
typedef void(^RPAPIITagGCallback)(RPTagStatus status, NSArray<RPTag *>* tag, NSInteger timestamp);
typedef void(^RPAPIITagWCallback)(RPTagStatus status, NSInteger timestamp);

@class RPAPIEntry;
@class RPTrack;

/// Represents access to the public API.
@interface RPAPIEntry : NSObject {
    
}

#pragma mark - Utils

- (void)refresh;


#pragma mark - Tracks

/*!
 Requests all tracks with specified offset and limit. Can be filtered by passing non-nil start & end dates.
 @param offset Page offset.
 @param limit Page limit.
 @param startDate Optional value to filter tracks.
 @param endDate Optional value to filter tracks.
 @param callback Completion handler with RPFeed as a response.
 */
- (void)getTracksWithOffset:(NSUInteger)offset
                      limit:(NSUInteger)limit
                  startDate:(NSDate *)startDate
                    endDate:(NSDate *)endDate
                 completion:(RPAPIEntryCallback)callback;

/*!
 Requests all tracks with specified offset and limit. No filter will be used in request.
 @param offset Page offset.
 @param limit Page limit.
 @param callback Completion handler with RPFeed as a response.
 */
- (void)getTracksWithOffset:(NSUInteger)offset
                      limit:(NSUInteger)limit
                 completion:(RPAPIEntryCallback)callback;


/*!
 Requests all tracks with specified offset and limit. Can be filtered by passing non-nil start & end dates.
 @param offset Page offset.
 @param limit Page limit.
 @param startDate Optional value to filter tracks.
 @param endDate Optional value to filter tracks.
 @param callback Completion handler with RPFeed as a response.
 */
- (void)getTracks:(NSUInteger)offset
            limit:(NSUInteger)limit
        startDate:(NSDate *)startDate
          endDate:(NSDate *)endDate
       completion:(RPAPIEntryCallback)callback;

/*!
 Requests all tracks with specified offset and limit. No filter will be used in request.
 @param offset Page offset.
 @param limit Page limit.
 @param callback Completion handler with RPFeed as a response.
 */
- (void)getTracks:(NSUInteger)offset
            limit:(NSUInteger)limit
       completion:(RPAPIEntryCallback)callback;

/*!
 Requests track info with specified track token.
 @param token Track token.
 @param callback Completion handler with RPTrackProcessed as a response.
 */
- (void)getTrackWithTrackToken:(NSString *)token completion:(RPAPIEntryCallback)callback;

/*!
 Requests track info with specified track token.
 @param token Track token.
 @param callback Completion handler with RPTrackProcessed as a response.
 */
- (void)getTrackDetails:(NSString *)token completion:(RPAPIEntryCallback)callback;

/*!
 Requests track origins dictionary.
 @param callback Completion handler with RPTrackOriginDict as a response.
 */
- (void)getTrackOriginsWithCompletion:(RPAPIEntryCallback)callback;

/*!
 Changes track origin code.
 @param originCode Track origin string code.
 @param token Target track token.
 @param callback Completion handler with empty response.
 */
- (void)changeTrackOrigin:(NSString *)originCode
            forTrackToken:(NSString *)token
               completion:(RPAPIEntryCallback)callback;

/*!
 * Share track.
 * @param token Target track token.
 * @param isShared Choose YES if you need to share track, else - NO.
 * @param callback Completion handler with empty response.
 */
- (void)makeTrack:(NSString *)token
           shared:(BOOL)isShared
       completion:(RPAPIEntryCallback)callback;

#pragma mark - Statistics

/*!
 * Get shared track.
 * @param token Track token.
 * @param callback Completion handler with RPTrackProcessed as a response.
 */
- (void)getSharedTrackWith:(NSString *)token completion:(RPAPIEntryCallback)callback;

/*!
 Requests main statistics data for all possible statistic types.
 @param callback Completion handler with RPStatistics as a response.
 */
- (void)getDashboardInfoByTrackTag:(NSString*)tag WithCompletion:(RPAPIEntryCallback)callback;
- (void)getDashboardInfoWithCompletion:(RPAPIEntryCallback)callback;
- (void)getStatisticsMainByTag:(NSString*)tag WithCompletion:(RPAPIEntryCallback)callback;


typedef NS_ENUM(NSUInteger, RPStatisticsPeriod) {
    RPStatisticsPeriodDay,
    RPStatisticsPeriodWeek,
    RPStatisticsPeriodAllTime
};

typedef NS_ENUM(NSUInteger, RPStatisticsType) {
    RPStatisticsTypeDriving,
    RPStatisticsTypeDrivingTime,
    RPStatisticsTypeMileage,
    RPStatisticsTypeSpeed,
    RPStatisticsTypePhone
};

/*!
 Requests main statistics data for all possible statistic types.
 @param type Type of statistics you want to request.
 @param period Time interval for last period of statistics.
 @param callback Completion handler with statistics respone. Final type depends on type. It could be RPStatisticsDriving,
   RPStatisticsDrivingTime, RPStatisticsMileage, RPStatisticsPhone or RPStatisticsSpeed
 */
- (void)getStatisticsDetailForType:(RPStatisticsType)type
                            period:(RPStatisticsPeriod)period
                        completion:(RPAPIEntryCallback)callback;

- (void)getDrivingTimeStatistics:(RPStatisticsPeriod)period
                         trackTag:(NSString*)tag
                      completion:(RPAPIEntryCallback)callback;

- (void)getDrivingTimeStatistics:(RPStatisticsPeriod)period
                      completion:(RPAPIEntryCallback)callback;

- (void)getDrivingDetailsStatistics:(RPStatisticsPeriod)period
                            trackTag:(NSString*)tag
                         completion:(RPAPIEntryCallback)callback;

- (void)getDrivingDetailsStatistics:(RPStatisticsPeriod)period
                         completion:(RPAPIEntryCallback)callback;

- (void)getSpeedDetailStatistics:(RPStatisticsPeriod)period
                         trackTag:(NSString*)tag
                      completion:(RPAPIEntryCallback)callback;

- (void)getSpeedDetailStatistics:(RPStatisticsPeriod)period
                      completion:(RPAPIEntryCallback)callback;

- (void)getMileageDetailsStatistics:(RPStatisticsPeriod)period
                            trackTag:(NSString*)tag
                         completion:(RPAPIEntryCallback)callback;

- (void)getMileageDetailsStatistics:(RPStatisticsPeriod)period
                         completion:(RPAPIEntryCallback)callback;

- (void)getPhoneDetailStatistics:(RPStatisticsPeriod)period
                         trackTag:(NSString*)tag
                      completion:(RPAPIEntryCallback)callback;

- (void)getPhoneDetailStatistics:(RPStatisticsPeriod)period
                      completion:(RPAPIEntryCallback)callback;

- (NSArray <RPTrack *>*)getOutcomingTracks;

- (NSArray <RPTrack *>*)getUnsentTracks;

- (void)getTrackTags:(NSString *)trackToken completion:(RPAPIVOneEntryCallback)callback;
- (void)removeTrackTags:(NSArray<RPTag *>*)tags from:(NSString *)trackToken completion:(RPAPIVOneEntryCallback)callback;
- (void)addTrackTags:(NSArray<RPTag *>*)tags to:(NSString *)trackToken completion:(RPAPIVOneEntryCallback)callback;

- (void)addFutureTrackTag:(RPTag *)tag completion:(RPAPIITagCallback)callback;
- (void)removeFutureTrackTag:(RPTag *)tag completion:(RPAPIITagCallback)callback;
- (void)getFutureTrackTag:(NSInteger)timestamp completion:(RPAPIITagGCallback)callback;
- (void)removeAllFutureTrackTagsWithСompletion:(RPAPIITagWCallback)callback;

- (void)removeWithoutOfflineFutureTrackTag:(RPInnerTag *)tag completion:(RPAPIVOneEntryCallback)callback;
- (void)addWithoutOfflineFutureTrackTag:(RPInnerTag *)tag completion:(RPAPIVOneEntryCallback)callback;
- (void)removeAllWithoutOfflineFutureTrackTagsWithСompletion:(RPAPIVOneEntryCallback)callback;

- (void)sendHeartbeatWithReason:(NSString *)reason andRTL:(nullable NSMutableDictionary*)retlData callback:(void(^)(bool))handler;

- (void)sendRTL:(NSArray<id>* _Nonnull )retlData callback:(void(^_Nonnull)(bool))handler;
- (void)sendHeartbeatLogout;
- (void)sendHeartbeatLogin;
- (void)sendHeartbeatDisabledSDKbyusers;
- (void)sendHeartbeatEnabledSDKbyusers;
- (void)sendHeartbeatDisabledSDKwithuploadbyusers;
- (void)sendHeartbeat;
- (void)sendHeartbeatPeripheralBluetoothOff;
- (void)sendHeartbeatPeripheralBluetoothOn;

@end
