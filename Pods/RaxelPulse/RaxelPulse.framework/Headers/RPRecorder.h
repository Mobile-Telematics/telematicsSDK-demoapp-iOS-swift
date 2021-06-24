//
//  RPRecorder.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPTrackerState.h"

@class RPTrackForUpload;
@class RPTrackPointForUpload;
@class RPRawHardwareInfo;

/// Notifies when <tt>RPRecorder</tt> class instance adds one more sample to the internal storage.
FOUNDATION_EXPORT NSString *const RPRecorderDidRecordSampleNotification;

/// Represents tracking activity recording logic.
@interface RPRecorder : NSObject {
    BOOL             _active;
    NSMutableArray   *_trackerStates;
    RPTrackForUpload *_currentTrack;
    NSMutableArray<RPTrackPointForUpload *> *_currentPoints;
}

@property (readonly, nonatomic) RPTrackForUpload *currentTrack;
@property (readonly, nonatomic) NSArray<RPRawHardwareInfo *> *hardwareSamples;

/// Indicates whether the recording process is active.
@property (readonly, nonatomic, getter=isActive) BOOL active;

/// Assigns sampling time interval. You can set your own time interval if necessary. Forced min value is 0.5 seconds.
@property (assign, nonatomic) NSTimeInterval samplingTimeInterval;
/// Current track start reason.
@property (assign, nonatomic) BOOL isEnded;
@property (assign, nonatomic) NSNumber *cycleNumber;

/// Contains list of current tracking process states.
@property (readonly, nonatomic) NSArray<RPTrackerState *> *trackerStates;

/// Current track stop reason.
@property (readonly, nonatomic) NSString *stopReason;
/// Current track start reason.
@property (readonly, nonatomic) NSString *startReason;


#pragma mark - Root

/*!
 Returns shared <tt>RPRecorder</tt> class instance.
 @return Shared <tt>RPRecorder</tt> class instance.
 */
+ (instancetype)instance;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end
