//
//  RPJsonHelper.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 19.02.2020.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RPJsonHelper : NSObject {
    
}

+ (double)getDoubleValue:(id)json withName:(NSString*)name;

+ (NSInteger)getIntValue:(id)json withName:(NSString*)name ;
    
+ (BOOL)getBOOLValue:(id)json withName:(NSString*)name;
    
+ (NSString*)getStringValue:(id)json withName:(NSString*)name;

@end

NS_ASSUME_NONNULL_END
