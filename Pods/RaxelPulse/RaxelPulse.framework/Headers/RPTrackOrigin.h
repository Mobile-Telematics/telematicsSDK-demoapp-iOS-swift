//
//  RPTrackOrigin.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPJSONSerializable.h"

/// Contains track origin info.
@interface RPTrackOrigin : NSObject<RPJSONSerializable> {
    
}

@property (copy, nonatomic)   NSString *displayName;
@property (copy, nonatomic)   NSString *trackOriginCode;
@property (assign, nonatomic) BOOL     canBeSelected;

@end
