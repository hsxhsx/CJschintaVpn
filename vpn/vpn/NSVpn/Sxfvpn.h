//
//  NsAuthManager.h
//  VPNDemo
//
//  Created by MacDev02 on 2019/5/6.
//  Copyright © 2019年 sangfor. All rights reserved.
//

#import "NSString+Encrypt.h"
#import "SxfvpnCallback.h"
#import "Sxfvpn.h"
#import "SangforAuthManager.h"
#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
@protocol AppJSObjectDelegate <JSExport>

-(void)scan:(NSString *)message;

@end
@interface Sxfvpn : NSObject<AppJSObjectDelegate>
typedef enum{
    AUTH_TYPE_PASSWORD = 1,
    AUTH_TYPE_SMS = 2,
    AUTH_TYPE_RADIUS = 6,
    AUTH_TYPE_CERTIFICATE = 0,
    AUTH_TYPE_TOKEN = 7,
    AUTH_TYPE_RAND_CODE = 22,
    AUTH_TYPE_RENEW_PASSWORD = 18,
    AUTH_TYPE_RENEW_PASSWORD_WITH_OLDPASSWORD = 20
} SxfvpnSdkMode;
- (instancetype)init:(SxfvpnCallback *)sxfvpnCallback;
- (BOOL)startVPNInitAndLogin:(NSString *)ip name:(NSString *)name passwd:(NSString *)passwd;
- (void)sendConnectState;
- (void)loginByPasswd:(NSString *)user passwd:(NSString *)passwd;
- (void)loginBySMS:(NSString *)smsCode;
- (void)logoutVpn;
- (NSString *)getAuthTypeDescription:(SxfvpnSdkMode)authType;
- (void)initSangforSdk;
@property(nonatomic,weak) id<AppJSObjectDelegate> delegate;
@end
