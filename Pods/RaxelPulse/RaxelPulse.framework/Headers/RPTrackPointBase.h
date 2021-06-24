//
//  RPTrackPointBase.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPJSONSerializable.h"


@interface RPTrackPointBase : NSObject<RPJSONSerializable> {
    
}

@property (assign, nonatomic) NSInteger number;
@property (assign, nonatomic) double    totalMeters;
@property (assign, nonatomic) double    speed;
@property (assign, nonatomic) double    midSpeed;
@property (copy, nonatomic)   NSDate    *pointDate;
@property (assign, nonatomic) double    latitude;
@property (assign, nonatomic) double    longitude;
@property (assign, nonatomic) double    height;
@property (assign, nonatomic) double    course;
@property (assign, nonatomic) double    yaw;
@property (assign, nonatomic) double    lateral;

- (id)toJSONDB;

@end
