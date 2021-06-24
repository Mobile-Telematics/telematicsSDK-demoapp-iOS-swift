//
//  RPTrackBase.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPJSONSerializable.h"
#import "RPSecure.h"


@interface RPTrackBase : NSObject<RPJSONSerializable> {
    
}

@property (copy, nonatomic) NSDate *startDate;
@property (copy, nonatomic) NSDate *endDate;

@end
