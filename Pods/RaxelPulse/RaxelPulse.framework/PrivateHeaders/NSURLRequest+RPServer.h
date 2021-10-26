//
//  NSURLRequest+RPInnerServer.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#define GET sdfasdflk3l42k34asdf
#define POST sdfaana9ansdfasdf

FOUNDATION_EXPORT NSString *const GET;
FOUNDATION_EXPORT NSString *const POST;
FOUNDATION_EXPORT NSTimeInterval const RPServerRequestTimeInterval;
FOUNDATION_EXPORT NSTimeInterval const RPServerHeartbeatTimeInterval;


@interface NSURLRequest (RPServer)

+ (NSURLRequest *)requestCarServiceWithPath:(NSString *)path parameters:(NSDictionary *)params headers:(NSDictionary *)headers method:(NSString *)method;
+ (NSURLRequest *)requestWithPath:(NSString *)path
                       parameters:(NSDictionary *)params
                          headers:(NSDictionary *)headers
                           method:(NSString *)method;
+ (NSURLRequest *)requestWithPath:(NSString *)path
                          baseURL:(NSString *)baseURL
                       parameters:(NSDictionary *)params
                          headers:(NSDictionary *)headers
                           method:(NSString *)method;
+ (NSURLRequest *)requestHeartWithPath:(NSString *)path
                          baseURL:(NSString *)baseURL
                       parameters:(NSDictionary *)params
                          headers:(NSDictionary *)headers
                           method:(NSString *)method;
+ (NSURLRequest *)requestUserTelematicssdkWithPath:(NSString *)path parameters:(NSDictionary *)params headers:(NSDictionary *)headers method:(NSString *)method;

@end
