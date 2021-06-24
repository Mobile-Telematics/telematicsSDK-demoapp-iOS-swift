//
//  RPRawTrack.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPRawTrackPoint.h"


@interface RPRawTrack : NSObject {
    
}

@property (copy, nonatomic)   NSDate *startDate;
@property (copy, nonatomic)   NSDate *endDate;
@property (strong, nonatomic) NSArray<RPRawTrackPoint *> *points;

@end
