//
//  RPTrack+CoreDataClass.h
//  RaxelPulse
//
//  Created by Igor Nabokov on 28/08/2018.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

typedef NS_ENUM(NSUInteger, RPTrackState) {
    RPTrackStateUndefined,
    RPTrackStateStarted,
    RPTrackStateFinished,
    RPTrackStateUploaded,
    RPTrackStateProcessed
};

NS_ASSUME_NONNULL_BEGIN

@interface RPTrack : NSManagedObject

@property (nonatomic) RPTrackState trackState;
@property (nullable, nonatomic, copy) NSDate *endDate;
@property (nullable, nonatomic, copy) NSDate *startDate;
@property (nonatomic) int32_t state;
@property (nullable, nonatomic, copy) NSString *filename;
@property (nullable, nonatomic, copy) NSString *startReason;
@property (nullable, nonatomic, copy) NSString *endReason;

+ (instancetype)createInContext:(NSManagedObjectContext *)context;
+ (NSFetchRequest<RPTrack *> *)fetchRequest;

@end

NS_ASSUME_NONNULL_END

