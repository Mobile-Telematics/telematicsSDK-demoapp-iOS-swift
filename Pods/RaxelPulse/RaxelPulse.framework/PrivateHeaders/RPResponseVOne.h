//
//  RPResponseVOne.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 26.11.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPJSONSerializable.h"

NS_ASSUME_NONNULL_BEGIN

@interface RPResponseVOne : NSObject<RPJSONSerializable> {
}

@property (copy, nonatomic) id _Nullable result;
@property (assign, nonatomic) NSInteger status;
@property (strong, nonatomic) NSString *title;
@property (copy, nonatomic) NSArray *errors;

@end

NS_ASSUME_NONNULL_END
