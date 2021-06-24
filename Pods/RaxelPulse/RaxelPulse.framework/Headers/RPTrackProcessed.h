//
//  RPTrackProcessed.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPTrackBase.h"
#import "RPTrackPointProcessed.h"
#import "RPAddressParts.h"
#import "RPInnerTag.h"

/// Contains track info processed by server.
@interface RPTrackProcessed : RPTrackBase {
    
}

/// The start address.
@property (copy, nonatomic)   NSString  *addressStart;

/// The end address.
@property (copy, nonatomic)   NSString  *addressEnd;

/// The count of sharp acceleration.
@property (assign, nonatomic) NSInteger accelerationCount;

/// The count of sharp braking.
@property (assign, nonatomic) NSInteger decelerationCount;

/// The trip rating.
@property (assign, nonatomic) double    rating;

/// The trip rating.
@property (assign, nonatomic) double    rating100;

/// The trip сornering rating.
@property (copy, nonatomic) NSNumber    *ratingCornering;

/// The trip сornering rating.
@property (copy, nonatomic) NSNumber    *ratingCornering100;

/// The trip acceleration rating.
@property (copy, nonatomic) NSNumber    *ratingAcceleration;

/// The trip acceleration rating.
@property (copy, nonatomic) NSNumber    *ratingAcceleration100;

/// The trip braking rating.
@property (copy, nonatomic) NSNumber    *ratingBraking;

/// The trip braking rating.
@property (copy, nonatomic) NSNumber    *ratingBraking100;

/// The trip speeding rating.
@property (copy, nonatomic) NSNumber    *ratingSpeeding;

/// The trip speeding rating.
@property (copy, nonatomic) NSNumber    *ratingSpeeding100;

/// The trip phone usage rating.
@property (copy, nonatomic) NSNumber    *ratingPhoneUsage;

/// The trip phone usage rating.
@property (copy, nonatomic) NSNumber    *ratingPhoneUsage100;

/// The trip time of day rating.
@property (copy, nonatomic) NSNumber    *ratingTimeOfDay;

/// The trip reason rating.
@property (copy, nonatomic) NSString  *ratingReason;

/// The trip reason rating.
@property (strong, nonatomic) RPAddressParts  *addressStartParts;

/// The trip reason rating.
@property (strong, nonatomic) RPAddressParts  *addressFinishParts;


@property (strong, nonatomic) NSArray<RPInnerTag *> *tags;

/// The trip phone usage minutes.
@property (assign, nonatomic) double    phoneUsage;

/// The distance trip in km.
@property (assign, nonatomic) double    distance;

/// The duration trip in horse.
@property (assign, nonatomic) double    duration;

/// Total distance travelled(in km) while exceeding speed limit over for 20 km/h or more.
@property (assign, nonatomic) double    highOverSpeedMileage;

/// Total distance travelled(in km) while exceeding speed limit over for 10 to 20 km/h.
@property (assign, nonatomic) double    midOverSpeedMileage;

/// The trip type has changed.
@property (assign, nonatomic) BOOL      originChanged;

/// The trip type.
@property (copy, nonatomic)   NSString  *trackOriginCode;

/// Track token.
@property (copy, nonatomic)   NSString *trackToken;

/// Sharing type (ex: Shared).
@property (copy, nonatomic)   NSString *shareType;

/// Start point city name.
@property (copy, nonatomic)   NSString *cityStart;

/// End point city name.
@property (copy, nonatomic)   NSString *cityFinish;

/// Array of track points
@property (strong, nonatomic) NSArray<RPTrackPointProcessed *> *points;

@property (copy, nonatomic) NSNumber *dateUpdated;

@end
