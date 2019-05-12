/*!
 @header SangforAuthHeader.h
 
 @brief angforAuthHeader
 
 文件描述了在VPN中使用到的枚举，宏定义以及协议
 
 @author sangfor
 @copyright  SANGFOR
 @version    1.0.0
 @sdkversion 7.6.2.88895
 */
#ifndef SangforAuthHeader_h
#define SangforAuthHeader_h

//定义支持的VPN模式类型
typedef NS_ENUM(NSUInteger, VPNMode)
{
    VPNModeL3VPN = 0,       //L3VPN模式，全局VPN，手机上的应用都可以访问资源
    VPNModeEasyApp = 1,     //TCP模式，只在当前APP内有效，有效期至2018-6-30
};

//定义支持的VPN认证类型
typedef NS_ENUM(NSUInteger, VPNAuthType)
{
    VPNAuthTypeCertificate = 0,         //证书认证
    VPNAuthTypePassword = 1,            //用户名密码认证
    VPNAuthTypeSms = 2,                 //短信认证
    VPNAuthTypeRadius = 6,              //挑战认证或者Radius认证
    VPNAuthTypeToken = 7,               //令牌认证
    VPNAuthTypeCode = 11,               //钉钉code认证
    VPNAuthTypeSession = 16,            //Session认证
    VPNAuthTypeNone = 17,               //无认证
    VPNAuthTypeRenewPassword = 18,      //强制修改密码认证
    VPNAuthTypeRenewPassword2 = 20,     //强制修改密码认证,处理之前没有输入密码的情况。
    VPNAuthTypeRand = 22,                //图形校验码认证
    VPNAuthTypeTicket =  1<<11          //Ticket认证
};

//定义VPN的状态
typedef NS_ENUM(NSUInteger, VPNStatus)
{
    VPNStatusOnLine = 0,                //在线状态
    VPNStatusOffLine = 1,               //离线状态
};



typedef NS_ENUM(NSUInteger, SFNEStatus) {
    //NetworkExtion运行异常
    SFNEStatusInvalid,
    //NetworkExtion运行正常
    SFNEStatusValid
};

//定义VPN的日志级别
typedef NS_ENUM(NSUInteger, LogLevel)
{
    LogLevelDebug = 10,             //Debug级别
    LogLevelInfo = 20,              //Info级别
    LogLevelWarn = 30,              //Warn级别
    LogLevelError = 40,             //Error级别
    LogLevelFatal = 50              //Fatal级别
};

#pragma mark - BaseMessage
/*! @brief 下次认证信息的基础类
 *
 */
@interface BaseMessage : NSObject
/*! 错误码 */
@property (nonatomic, assign) int errCode;
/*! 错误提示字符串 */
@property (nonatomic, retain) NSString *errStr;

@end

#pragma mark - SmsMessage
/*! @brief 下一次认证类型为VPNAuthTypeSms时，返回的信息
 *
 *  短信认证需要的结构体
 */
@interface SmsMessage : BaseMessage
/*! 短信认证的手机号码 */
@property (nonatomic, retain) NSString *phoneNum;
/*! 重新发送短信倒计时时间 */
@property (nonatomic, assign) int countDown;
/*! 上次发送的短信验证码是否在有效期 */
@property (nonatomic, assign) BOOL stillValid;

@end

#pragma mark - SmsMessage
/*! @brief 下一次认证类型为VPNAuthTypeRadius时，返回的信息
 *
 *  挑战认证(Radius认证)需要的结构体
 */
@interface ChallengeMessage : BaseMessage
/*! 挑战认证的提示信息 */
@property (nonatomic, retain) NSString *challengeMsg;

@end

#pragma mark - ChangePswMessage
/*! @brief 下一次认证类型为VPNAuthTypeForceUpdatePwd时，返回的信息
 *
 *  强制修改密码认证需要的结构体
 */
@interface ChangePswMessage : BaseMessage
/*! 请求修改密码认证的密码规则信息 */
@property (nonatomic, retain) NSString *pswMsg;

@end

#pragma mark - StatusChangeMessage
/*! @brief VPN的状态发生变化时返回的信息
 *
 *  VPNStatusDidChangeNotification通知里面带的object
 */
@interface StatusChangeMessage : BaseMessage
/*! VPN状态变化的当前状态 */
@property (nonatomic, assign) VPNStatus status;
/*! VPN状态变化的原因 */
@property (nonatomic, copy) NSString *changeReason;
@end

#pragma mark SangforAuthDelegate
/*!
 
 @protocol SangforAuthDelegate
 
 @abstract SangforAuthManager的回调接口。
 
 @discussion 接收认证结果的回调
 
 */
@protocol SangforAuthDelegate

@required

/*!
 认证失败回调
 
 @param error 错误信息
 */
- (void)onLoginFailed:(NSError *)error;

/*!
 认证过程回调
 nextAuthType为VPNAuthTypeSms、VPNAuthTypeRadius、VPNAuthTypeForceUpdatePwd
 这三个类型的中的一个时，msg才不为空，具体的类参考上面对信息类的定义
 
 @param nextAuthType 下个认证类型
 @param msg 认证需要的信息类
 */
- (void)onLoginProcess:(VPNAuthType)nextAuthType message:(BaseMessage *)msg;

/*!
 认证成功回调
 */
- (void)onLoginSuccess;

@optional

/*!
 图形校验码回调
 
 @param data 图片信息
 */
- (void)onRndCodeCallback:(NSData *)data;

@end
#endif /* SangforAuthHeader_h */

/*!
 当VPN的状态发生变化时进行通知
 */
FOUNDATION_EXPORT NSString * const VPNStatusDidChangeNotification;

/*!
 当VPN进行重连失败时进行通知
 */
FOUNDATION_EXPORT NSString * const VPNReloginFailedNotification;
