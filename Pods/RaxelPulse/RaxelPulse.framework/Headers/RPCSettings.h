//
//  RPCSettings.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 21.10.2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RPCPageTexts.h"

NS_ASSUME_NONNULL_BEGIN

@interface RPCSettings : NSObject {
}

+ (id)returnInstance;
- (NSString*)appName;
- (void)setAppName:(NSString*)appName;
- (UIColor*)wizardBgColor;
- (void)setWizardBgColor:(UIColor*)wizardBgColor;
- (UIColor*)wizardMaintextColor;
- (void)setWizardMaintextColor:(UIColor*)wizardMaintextColor;
- (UIColor*)wizardAlertBackgroundColor;
- (void)setWizardAlertBackgroundColor:(UIColor*)wizardAlertBackgroundColor;
- (UIColor*)wizardAlertTextColor;
- (void)setWizardAlertTextColor:(UIColor*)wizardAlertTextColor;
- (UIColor*)wizardAlertButtonTextColor;
- (void)setWizardAlertButtonTextColor:(UIColor*)wizardAlertButtonTextColor;
- (UIColor*)wizardAlertActiveButtonTextColor;
- (void)setWizardAlertActiveButtonTextColor:(UIColor*)wizardAlertActiveButtonTextColor;
- (CGFloat)wizardAlertCorners;
- (void)setWizardAlertCorners:(CGFloat)wizardAlertCorners;
- (UIColor*)wizardNextButtonBgColor;
- (void)setWizardNextButtonBgColor:(UIColor*)wizardNextButtonBgColor;
- (UIColor*)wizardNextButtonTextColor;
- (void)setWizardNextButtonTextColor:(UIColor*)wizardNextButtonTextColor;
- (NSArray<RPCPageTexts *> * _Nonnull)wizardPages;
- (void)setWizardPages:(NSArray<RPCPageTexts *> * _Nonnull)wizardPages;

@end

NS_ASSUME_NONNULL_END
