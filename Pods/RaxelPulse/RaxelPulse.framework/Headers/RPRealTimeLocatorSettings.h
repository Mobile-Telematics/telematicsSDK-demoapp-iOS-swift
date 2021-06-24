//
//  RPRealTimeLocatorSettings.h
//  RaxelPulse
//
//  Created by Igor Nabokov on 26/01/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, RPRealTimeLocationBehavior) {
    RPRealTimeRawLocationBehavior,
    RPRealTimeFilteredLocationBehavior
};

NS_ASSUME_NONNULL_BEGIN

@interface RPRealTimeLocatorSettings : NSObject <NSCopying, NSCoding>

@property (readonly, nonatomic) BOOL realtimeLocationsEnabled;

@property (readonly, nonatomic) RPRealTimeLocationBehavior locationBehavior;

/// timeout between uploading locations (in seconds)
@property (readonly, nonatomic) double uploadTimeout;

- (id)copyWithZone:(nullable NSZone *)zone;


#pragma mark - initializers

- (instancetype)initWithRealtimeLocationsEnabled:(BOOL)realtimeLocationsEnabled locationBehavior:(RPRealTimeLocationBehavior)locationBehavior uploadTimeout:(double)uploadTimeout;

+ (instancetype)settingsWithRealtimeLocationsEnabled:(BOOL)realtimeLocationsEnabled locationBehavior:(RPRealTimeLocationBehavior)locationBehavior uploadTimeout:(double)uploadTimeout;

+ (instancetype)defaultSettings;

+ (instancetype)defaultEnabledSettings;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
