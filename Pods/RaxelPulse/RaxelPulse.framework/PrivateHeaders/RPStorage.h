//
//  RPStorage.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPSecure.h"

typedef void(^RPUploadCallback)(Boolean success);
typedef void(^RPInnerLogCallback)(NSMutableArray<NSString*>* list);

@interface RPStorage : NSObject {
    
}

@property (readonly, nonatomic) NSString  *docsPath;
@property (readonly, nonatomic) NSString  *storagePath;
@property (readonly, nonatomic) NSInteger logFilesCount;
@property (readonly, nonatomic) NSInteger trackFilesCount;
@property (assign, nonatomic) RPUploadCallback uploadCallback;
@property (assign, nonatomic) BOOL restoreBlock;


#pragma mark - Root

+ (instancetype)instance;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;


#pragma mark - Data Management

- (BOOL)writeString:(NSString *)string toFilePath:(NSString *)fpath;
- (void)flushLog;
- (void)uploadData:(RPUploadCallback)callback;
- (void)destroyAllFiles;
- (NSInteger)filesCount;
- (void)removeFromStack:(NSString *)path callback:(RPUploadCallback)callback;
- (void)removeFromStackOnly:(NSString *)path callback:(RPUploadCallback)callback;
- (void)processingUploadData;
- (void)showBadge:(NSInteger)value;
- (void)cleanLogs;


#pragma mark - Utils

+ (NSString *)stringFromJSON:(id)json error:(NSError **)error;
- (void)updateFilePath:(NSString *)path withSessionUploadTaskIdentifier:(NSInteger)taskId;
- (void)clearSessionUploadTaskIdentifier:(NSInteger)taskId counterCode:(Boolean)counterCode callback:(RPUploadCallback)callback;
- (void)removePhysicallyBySessionUploadTaskId:(NSInteger)taskId callback:(RPUploadCallback)callback;
- (void)upsendData:(RPInnerLogCallback)callback;
- (void)uploadBackgroundTask;
- (void)restoreTracks;
- (void)clearUploadList;

@end
