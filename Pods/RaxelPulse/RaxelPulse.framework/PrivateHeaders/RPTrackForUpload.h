//
//  RPTrackForUpload.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPTrackBase.h"
#import "RPTrackPointForUpload.h"
#import <RaxelPulse/RaxelPulse-Swift.h>
#import "RPSecure.h"
#import "RPEvent.h"

#ifdef RPSECURE

#define points kjbadfkh2

#endif


@interface RPTrackForUpload : RPTrackBase {
    
}

@property (strong, nonatomic) NSMutableArray<RPTrackPointForUpload *> *points;

@property (strong, nonatomic) NSMutableArray<RPEvent *> *events;

@property (strong, nonatomic) NSMutableArray<RPLKPoint *> *lkpPoints;
/// Current track stop reason.
@property (strong, nonatomic) NSString *stopReason;
/// Current track start reason.
@property (strong, nonatomic) NSString *startReason;

@end
