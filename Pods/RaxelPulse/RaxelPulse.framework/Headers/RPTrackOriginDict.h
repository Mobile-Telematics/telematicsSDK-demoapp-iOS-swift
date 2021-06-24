//
//  RPTrackOriginDict.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPJSONSerializable.h"
#import "RPTrackOrigin.h"

/// Contains tracks origins.
@interface RPTrackOriginDict : NSObject<RPJSONSerializable> {
    
}

@property (strong, nonatomic) NSArray<RPTrackOrigin *> *trackOrigins;

@end
