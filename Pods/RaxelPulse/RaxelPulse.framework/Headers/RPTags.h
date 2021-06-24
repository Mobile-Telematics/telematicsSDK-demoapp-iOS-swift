//
//  RPTags.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 13.03.2020.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPInnerTag.h"

/// Struct containing tracks feed.
@interface RPTags : NSObject<RPJSONSerializable> {
    
}

/// Array of RPTrackProcessed
@property (strong, nonatomic) NSArray<RPInnerTag *> *tags;

@end
