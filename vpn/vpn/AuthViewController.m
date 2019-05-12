//
//  AuthViewController.m
//  VPNDemo
//
//  Created by sangfor on 2017/8/23.
//  Copyright © 2017年 sangfor. All rights reserved.
//
//#import "SxfViewController.h"
//#import "SxfvpnCallback.h"
//#import "Sxfvpn.h"
#import "AuthViewController.h"
//#import "DLRadioButton.h"
//#import "SDAutoLayout.h"
//#import "AuthTableViewCell.h"
//#import <SangforSdklib/SangforAuthManager.h>
#import "SangforAuthManager.h"
//#import "RandAlertView.h"
//#import "NetworkViewController.h"
//#import "MBProgressHUD.h"
//#import "SmsAlertView.h"
//#import "errheader.h"

#define kVpnIp      @"vpnIp"       //VPN地址
#define kPort       @"vpnport"     //VPN端口号
#define kVpnModel   @"vpnModel"     //VPN模式

@interface AuthViewController ()<SangforAuthDelegate>

///背景图
@property (nonatomic, strong)   UIImageView             *backgroundView;        //背景

//VPN类型相关控件
///L3VPN模式的选项
//@property (strong, nonatomic)   DLRadioButton           *l3VPNRadio;
/////TCP模式的选项
//@property (strong, nonatomic)   DLRadioButton           *easyAppRadio;

//VPN地址相关控件
///VPN地址的输入框
@property (strong, nonatomic)   UITextField             *vpnIpTextField;

//VPN登录相关控件
///登录的View，包含其它子View
@property (strong, nonatomic)   UIView                  *loginView;
///用户名密码表单
@property (nonatomic, strong)   UITableView             *userNameTableView;
///证书表单
@property (nonatomic, strong)   UITableView             *cerTableView;

//分段相关控件
///分段控制器
@property (nonatomic, strong)   UISegmentedControl      *segmentedControl;
///分段控制器的选中下划线
@property (nonatomic, strong)   UILabel                 *selectedSegmentLabel;

//VPN登录
///单例的authManager
@property (nonatomic, retain)   SangforAuthManager      *sdkManager;
///VPN模式
@property (nonatomic, assign)   VPNMode                 mode;
///认证类型
@property (nonatomic, assign)   VPNAuthType             authType;

//图形校验码认证
///图形校验码视图
//@property (nonatomic, strong)   RandAlertView           *randView;

//网络视图
///网络请求的ViewController
//@property (nonatomic, strong)   NetworkViewController   *networkController;

///BYPASS按钮
@property (nonatomic, strong) UIButton                  *bypassBtn;

//免密认证
@property (nonatomic, strong) UIButton                  *tickAuthBtn;

//注销接口
@property (nonatomic, strong) UIButton                  *logoutBtn;

@end

@implementation AuthViewController

#pragma mark - 生命周期
- (void)viewWillAppear:(BOOL)animated{
//    SxfvpnCallback *callback = [SxfvpnCallback new];
//    xxViewController *xx = [[xxViewController alloc] init:self claaBack:callback app:[UIApplication sharedApplication]];
}
- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
//    Sxfvpn *sxfvpn = [[Sxfvpn alloc] init];
//    [sxfvpn initSangforSdk];
//  BOOL ij  =  [sxfvpn startVPNInitAndLogin:@"https://222.180.194.114:443" name:@"cjkcliukang" passwd:@"5c7mq&68"];
//    //初始化Sdk信息
    [self initSangforSdk];
//    [self.view addSubview:xx.view];
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
