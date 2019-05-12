//
//  xxViewController.m
//  vpn
//
//  Created by 胡双喜 on 2019/5/8.
//  Copyright © 2019 www.schinta.com.cn. All rights reserved.
//
#import "AuthViewController.h"
#import "SxfViewController.h"

@interface SxfViewController ()<SangforAuthDelegate>


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

@property (nonatomic,retain)UIViewController *rootController;
@property (nonatomic,retain)UIApplication *app;

@end

@implementation SxfViewController

#pragma mark - 生命周期
- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    AuthViewController *au = [AuthViewController new];
    [self.view addSubview:au.view];
    SxfvpnCallback *callback = [SxfvpnCallback new];
    //    Sxfvpn *sxfvpn = [[Sxfvpn alloc] init: callback];
    //  BOOL ij  =  [sxfvpn startVPNInitAndLogin:@"https://222.180.194.114:443" name:@"cjkcliukang" passwd:@"5c7mq&68"];
    //    //初始化Sdk信息
        [self initSangforSdk];
  
    //
    //    //创建点击收起键盘事件
    //    [self initViewTapAction];
    //
    //    //增加VPN类型UI
    //    [self setupVpnTypeSegment];
    //
    //    //增加VPN地址UI
    //    [self setupVpnAddrView];
    //
    //    //增加VPN登录UI
    //    [self setupLoginView];
    //
    //    //设置bypass按钮
    //    [self setupBypassButton];
    //
    //    //设置免密登录按钮
    //    [self setupTicketButton];
    //
    //    //设置注销按钮
    //    [self setupLogoutButton];
    //
    //    //获取保存的配置
    //    [self getUserConf];
    
}
- (instancetype)init:(UIViewController *)rootController claaBack:(SxfvpnCallback *)sxfvpnCallback app:(UIApplication *)app{
    self.rootController = rootController;
    self.app = app;
    _sxfvpnCallback = sxfvpnCallback;
    [self initSangforSdk];
    return self;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(transformView:) name:UIKeyboardWillChangeFrameNotification object:nil];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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
    [_sdkManager startPasswordAuthLogin:_mode vpnAddress:[NSURL URLWithString:@"https://222.180.194.114:443"]
                               username:@"cjkcliukang" password:@"5c7mq&68"];
}

#pragma mark - UI


#pragma mark - SangforAuthDelegate
/**
 认证失败
 
 @param error 错误信息
 */
- (void)onLoginFailed:(NSError *)error
{
    NSLog(@"xxxx");
}

/**
 认证过程回调
 
 @param nextAuthType 下个认证类型
 */
- (void)onLoginProcess:(VPNAuthType)nextAuthType message:(BaseMessage *)msg
{
    
    NSLog(@"%@",msg);
}

/**
 认证成功
 */
- (void)onLoginSuccess
{
    NSLog(@"xxxx");
    
}

/**
 图形校验码回调
 
 @param data 图片信息
 */
- (void)onRndCodeCallback:(NSData *)data
{
    
}

@end
