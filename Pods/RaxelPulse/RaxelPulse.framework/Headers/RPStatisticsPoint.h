//
//  RPTrackPointBase.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPJSONSerializable.h"


@interface RPStatisticsPoint : NSObject<RPJSONSerializable> {
    
}

@property (copy, nonatomic)   NSDate    *pointDate;
@property (assign, nonatomic) NSInteger value;

@end
