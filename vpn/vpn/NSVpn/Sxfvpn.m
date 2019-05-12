//
//  NsAuthManager.m
//  VPNDemo
//
//  Created by MacDev02 on 2019/5/6.
//  Copyright © 2019年 sangfor. All rights reserved.
//
#import "SxfvpnCallback.h"
#import "Sxfvpn.h"
#import "SangforAuthManager.h"
@interface Sxfvpn()<SangforAuthDelegate>


//VPN登录
///单例的authManager
@property (nonatomic, retain)   SangforAuthManager      *sdkManager;
///VPN模式
@property (nonatomic, assign)   VPNMode                 mode;
///认证类型
@property (nonatomic, assign)   VPNAuthType             authType;
@property (nonatomic, assign)   int             vpnState;
@property (nonatomic, assign)   int             vpnConnect;
@property (nonatomic, retain)   SxfvpnCallback             *sxfvpnCallback;


@end
@implementation Sxfvpn
- (instancetype)init:(SxfvpnCallback *)sxfvpnCallback{
    self = [super init];
    if(self){
        _sxfvpnCallback = sxfvpnCallback;
        _vpnState = 0;
        _vpnConnect = 0;
        _sxfvpnCallback = [SxfvpnCallback new];
        [self initSangforSdk];
    }
    return self;
}
#pragma mark - sdk初始化
///初始化Sdk信息
- (void)initSangforSdk
{
    //默认VPN模式为L3VPN
    _mode = VPNModeL3VPN;
    
    //认证类型，默认为用户名密码
    _authType = VPNAuthTypePassword;
    
    //初始化AuthMangager
    _sdkManager = [SangforAuthManager getInstance];
    _sdkManager.delegate = self;
    
    //探测插件是否存在,L3VPN模式下使用
    [_sdkManager querySFNEStaus:^(SFNEStatus neStatus) {
        NSLog(@"current ne Status is %d", (int)neStatus);
    }];
    
    
    
    //禁止越狱手机登录
    //[_sdkManager disableCrackedPhoneAuth];
    
    //设置日志级别
    [_sdkManager setLogLevel:LogLevelDebug];
  
    
}

- (BOOL)startVPNInitAndLogin:(NSString *)ip name:(NSString *)name passwd:(NSString *)passwd{
    NSURL *vpnUrl = [NSURL URLWithString:ip];
    //密码认证
    [_sdkManager startPasswordAuthLogin:_mode vpnAddress:vpnUrl
                                   username:name password:passwd];
    
    return YES;
}
- (void)addStatusChangedListener{
    VPNStatus status = [_sdkManager queryStatus];
    if(status == 0){
        _vpnConnect = -1;
        _vpnState = 0;
    }
    if(status == 1){
        _vpnConnect = 1;
    }
}
- (NSString *) getAuthTypeDescription:(SxfvpnSdkMode) authType {
    switch (authType) {
        case AUTH_TYPE_PASSWORD:
            return @"密码认证";
        case AUTH_TYPE_SMS:
            return @"短信认证";
        case AUTH_TYPE_RADIUS:
            return @"挑战认证";
        case AUTH_TYPE_CERTIFICATE:
            return @"证书认证";
        case AUTH_TYPE_TOKEN:
            return @"令牌认证";
        case AUTH_TYPE_RAND_CODE:
            return @"图形校验码";
        case AUTH_TYPE_RENEW_PASSWORD:
        case AUTH_TYPE_RENEW_PASSWORD_WITH_OLDPASSWORD:
            return @"修改密码";
        default:
            return @"VPN认证";
    }
}

- (void)onLoginProcess:(VPNAuthType)nextAuthType message:(BaseMessage *)msg{
    if(nextAuthType == 1){
        _vpnState = 0;
    }
    if(nextAuthType == 2){
        _vpnState = 1;
    }
    _vpnConnect = 0;
    [self sendConnectState];
}
- (void)onLoginSuccess{
    _vpnState = 2;
    [self doResourceRequest];
    [self sendConnectState];
}
- (void)onLoginFailed:(NSError *)error{
    _vpnState = -1;
    _vpnConnect = 0;
    [self sendConnectState];
    
}
- (void)loginByPasswd:(NSString *)user passwd:(NSString *)passwd{
    [_sdkManager doPasswordAuth:user password:passwd];
}
- (void)loginBySMS:(NSString *)smsCode{
    [_sdkManager doSMSAuth:smsCode];
}
- (void)doResourceRequest{
    
}
- (void)logoutVpn{
    [[SangforAuthManager getInstance] vpnLogout];
}
- (void)cancelLogInVpn{
    
}
- (void)sendConnectState{
    if(!_sxfvpnCallback){
        _sxfvpnCallback = [SxfvpnCallback new];
    }
    [_sxfvpnCallback stateChange:_vpnState callback:_vpnConnect];
    NSMutableDictionary *dic = [NSMutableDictionary dictionary];
    [dic setObject:[NSNumber numberWithInt:_vpnState] forKey:@"vpnState"];
    [dic setObject:[NSNumber numberWithInt:_vpnConnect] forKey:@"vpnConnect"];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"sxfvpn.state" object:nil userInfo:dic];
    
    // 将分享结果返回给js
    NSString *jsStr = [NSString stringWithFormat:@"getResult('%d','%d')",_vpnState,_vpnConnect];
    [[JSContext currentContext] evaluateScript:jsStr];
   
}
- (void)onRndCodeCallback:(NSData *)data
{
  
}

@end
