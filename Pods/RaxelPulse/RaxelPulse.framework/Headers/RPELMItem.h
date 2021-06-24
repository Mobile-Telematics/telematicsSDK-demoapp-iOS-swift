//
//  RPELMItem.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 22.11.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RPELMItem : NSObject {
    
}

// name
@property (strong, nonatomic) NSString *name;

// theId
@property (strong, nonatomic) NSString *uuid;

@end

NS_ASSUME_NONNULL_END
