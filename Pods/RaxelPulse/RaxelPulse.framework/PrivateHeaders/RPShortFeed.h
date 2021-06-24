//
//  RPShortFeed.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 23/08/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPJSONSerializable.h"

/// Struct containing tracks feed.
@interface RPShortFeed : NSObject<RPJSONSerializable> {
    
}

/// Array of RPTrackProcessed
@property (strong, nonatomic) id json;

@end
