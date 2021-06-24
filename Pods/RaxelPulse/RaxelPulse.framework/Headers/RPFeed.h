//
//  RPFeed.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPTrackProcessed.h"

/// Struct containing tracks feed.
@interface RPFeed : NSObject<RPJSONSerializable> {
    
}

/// Array of RPTrackProcessed
@property (strong, nonatomic) NSArray<RPTrackProcessed *> *tracks;

@end
