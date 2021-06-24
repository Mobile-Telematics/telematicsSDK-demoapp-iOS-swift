//
//  RPBackgroundUploader.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

FOUNDATION_EXPORT NSString *const RPBackgroundUploaderSID;


@interface RPBackgroundUploader : NSObject {
    
}

@property (readonly, nonatomic) NSURLSession *backgroundSession;
//@property (assign, nonatomic) Boolean isWorked;


#pragma mark - Root

+ (instancetype)instance;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;


#pragma mark - Handling

- (void)application:(UIApplication *)application handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)(void))completionHandler;


#pragma mark - Uploading

- (void)uploadFileFromPath:(NSString *)path toURL:(NSString *)urlString headers:(NSDictionary *)headers;

- (void)uploadFileToAmazon:(NSString *)path forDeviceToken:(NSString *)deviceToken;
- (void)clearUploadList;

@end
