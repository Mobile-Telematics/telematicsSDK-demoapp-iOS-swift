//
//  RPURLConfig.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPSecure.h"

#ifdef RPSECURE

#define RPURLConfig nasdkb376
#define RPURLConfigStageCarServiceServerURL fnfnfnfn
#define RPURLConfigStageServerURL njjsdfkjv7
#define RPURLConfigIncomingServerURL kjbasdb17
#define RPURLConfigIncomingServerURLheartbeats kjbasffdb17
#define RPURLConfigLogsServerURL kjnasdlhb4
#define RPURLConfigMultipartServerURL ajn2jb3s
#define RPURLConfigStatisticsServerURL adfadfas231b
#define RPURLUserTelematics adffffadfas231b


#endif

FOUNDATION_EXPORT NSString *const RPURLConfigStageCarServiceServerURL;
FOUNDATION_EXPORT NSString *const RPURLUserTelematics;
FOUNDATION_EXPORT NSString *const RPURLConfigStageServerURL;
FOUNDATION_EXPORT NSString *const RPURLConfigIncomingServerURL;
FOUNDATION_EXPORT NSString *const RPURLConfigIncomingServerURLheartbeats;
FOUNDATION_EXPORT NSString *const RPURLConfigLogsServerURL;
FOUNDATION_EXPORT NSString *const RPURLConfigStatisticsServerURL;
FOUNDATION_EXPORT NSString *const RPURLConfigRealTimeLocationServerURL;


@interface RPURLConfig : NSObject {
    
}

@end
