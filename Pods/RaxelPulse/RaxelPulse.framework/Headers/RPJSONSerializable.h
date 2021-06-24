//
//  RPJSONSerializable.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol RPJSONSerializable <NSObject>
@required
- (nullable instancetype)initWithJSON:(nonnull id)json;
- (nonnull id)toJSON;

@end
