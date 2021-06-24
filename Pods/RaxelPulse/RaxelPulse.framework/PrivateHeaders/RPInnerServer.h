//
//  RPInnerServer.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSURLRequest+RPServer.h"
#import "RPBackgroundUploader.h"
#import "RPURLConfig.h"
#import "RPDataTask.h"

@class RPInnerServer;


@interface RPInnerServer : NSObject {
    
}

@property (readonly, nonatomic) NSURLSession        *session;
@property (readonly, nonatomic) NSSet<RPDataTask *> *activeTasks;


#pragma mark - Root

+ (instancetype)instance;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;


#pragma mark - Requests

- (void)performTask:(RPDataTask *)task completion:(RPDataTaskCompletionBlock)onComplete;
- (void)performRequest:(NSURLRequest *)request
         responseClass:(Class)responseClass
            completion:(RPDataTaskCompletionBlock)onComplete;


#pragma mark - Utils

+ (NSDictionary *)defaultHeaders;

@end
