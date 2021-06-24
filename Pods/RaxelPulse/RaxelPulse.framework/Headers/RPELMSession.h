//
//  RPELMSession.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 18.12.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RPELMSession : NSObject {
    
}

// Date
@property (strong, nonatomic) NSDate* _Nullable lastConnect;

// Connected
@property (assign, nonatomic) BOOL isConnect;

@end

NS_ASSUME_NONNULL_END
