//
//  RPCPageTexts.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 21.10.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RPCPageTexts : NSObject {
    
}

+ (id)returnInstance;
+ (id)initWithPageText:(NSMutableAttributedString*)pageText alertText:(NSMutableAttributedString*)alertText buttonsText: (NSMutableArray*)buttonsList selected:(NSInteger) selected;
+ (id)initWithTitleText:(NSMutableAttributedString * _Nonnull)titleText pageText:(NSMutableAttributedString*)pageText alertText:(NSMutableAttributedString*)alertText buttonsText:(NSMutableArray*)buttonsList selected:(NSInteger) selected controlButtonText:cbuttonText;

@end

NS_ASSUME_NONNULL_END
