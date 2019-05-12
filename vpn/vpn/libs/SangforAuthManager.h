/*!
 @header SangforAuthManager.h
 
 @brief SangforAuthManager
 
 文件包括了认证方法和代理
 
 @author sangfor
 @copyright  SANGFOR
 @version    1.0.0
 */

#import <Foundation/Foundation.h>
#import "SangforAuthHeader.h"

/*!
 @class SangforAuthManager
 @brief The SangforAuthManager class
 @discussion  认证管理类
 @superclass SuperClass: NSObject\n
 */
@interface SangforAuthManager : NSObject

/*!
@property delegate

@abstract 认证代理

*/
@property (nonatomic, weak) id<SangforAuthDelegate> delegate;

/*! @brief
 获取单实例对象

 @return SangforAuthManager实例对象
 */
+ (SangforAuthManager *)getInstance;

#pragma mark ---- 设置公共参数

/*! @brief
 设置认证连接超时时间
 
 @discussion 若没有设置, 则使用默认的超时时间8s
 
 @param seconds 超时时间，单位为秒
 */
- (void)setAuthConnectTimeOut:(int)seconds;

/*! @brief
 设置是否关闭自动重连，默认开启
 
 @discussion 若没有设置, 则VPN自动重连
 
 @param autoLoginOff YES:关闭 NO:开启
 */
- (void)setAutoLoginOff:(BOOL)autoLoginOff __attribute__((deprecated("使用disableAutoRelogin代替")));

/*! @brief
 关闭自动重连
 
 @discussion 若没有关闭, 则VPN自动重连
 */
- (void)disableAutoRelogin;

/*! @brief
 设置日志级别
 
 @discussion 设置日志级别，默认为LogLevelInfo
 
 @param level 日志级别
 */
- (void)setLogLevel:(LogLevel)level;

/*! @brief
 设置禁止越狱手机进行登录
 
@discussion 开启后越狱手机无法进行登录
 */
- (void)disableCrackedPhoneAuth;

/*! @brief
 开启ByPass模式
 
 @discussion 开启byPass模式之后，所有的方法直接返回结果。
 建议只在调试模式下使用，而且需要在调用所有方法之前调用。
 */
- (void)enableByPassMode;

#pragma mark ---- 组合认证回调时调用，以下的方法只在onLoginProcess回调中使用
/*! @brief
 组合认证：证书认证
 @discussion
 onLoginProcess回调中nextAuthType值VPNAuthTypeCertificate时调用。
 该方法只进行认证过程，不进行vpn初始化过程，注意与startVPNLogin的区别。

 @param cerPath 证书路径
 @param password 证书密码
 */
- (void)doCertificateAuth:(NSString *)cerPath password:(NSString *)password;

/*! @brief
 组合认证：用户名密码认证
 @discussion
 onLoginProcess回调中nextAuthType值VPNAuthTypePassword时调用。
 该方法只进行认证过程，不进行vpn初始化过程，注意与startVPNLogin的区别。

 @param username 用户名
 @param password 密码
 */
- (void)doPasswordAuth:(NSString *)username password:(NSString *)password;

/*! @brief
 组合认证：图形校验码认证
 @discussion
 onLoginProcess回调中nextAuthType值VPNAuthTypeRand时调用。
 该方法只进行认证过程，不进行vpn初始化过程，注意与startVPNLogin的区别。
 
 @param randCode 图形校验码
 */
- (void)doRandCodeAuth:(NSString *)randCode;

/*! @brief
 组合认证：短信认证
 @discussion
 onLoginProcess回调中nextAuthType值VPNAuthTypeSms时调用。
 该方法只进行认证过程，不进行vpn初始化过程，注意与startVPNLogin的区别。

 @param smsCode 短信验证码
 */
- (void)doSMSAuth:(NSString *)smsCode;

/*! @brief
 组合认证：动态令牌认证
 
 @discussion
 onLoginProcess回调中nextAuthType值VPNAuthTypeToken时调用。
 该方法只进行认证过程，不进行vpn初始化过程，注意与startVPNLogin的区别。
 
 @param token 动态口令
 */
- (void)doTokenAuth:(NSString *)token;

/*! @brief
 组合认证：Radius挑战认证
 
 @discussion
 onLoginProcess回调中nextAuthType值VPNAuthTypeRadius时调用。
 该方法只进行认证过程，不进行vpn初始化过程，注意与startVPNLogin的区别。
 
 @param radiusCode 挑战认证码
 */
- (void)doRadiusAuth:(NSString *)radiusCode;

/*! @brief
 组合认证：更新密码认证
 
 @discussion
 onLoginProcess回调中nextAuthType值VPNAuthTypeForceUpdatePwd时调用
 VPN后台开启密码策略，登录时对不符合密码策略的密码调用该接口修改密码。
 该方法只进行认证过程，不进行vpn初始化过程，注意与startVPNLogin的区别。
 
 @param newPassword 新密码
 */
- (void)doRenewPasswordAuth:(NSString *)newPassword;

/*! @brief
 组合认证：更新密码认证
 
 @discussion
 onLoginProcess回调中nextAuthType值VPNAuthTypeForceUpdatePwd2时调用
 VPN后台开启密码策略，登录时对不符合密码策略的密码调用该接口修改密码。
 该方法只进行认证过程，不进行vpn初始化过程，注意与startVPNLogin的区别。
 该方法与doRenewPasswordAuth:(NSString *)newPassword;区别在于之前没有设置登录密码
 
 @param prePassword 旧密码
 @param newPassword 新密码
 */
- (void)doRenewPasswordAuth:(NSString *)prePassword newPassword:(NSString *)newPassword;

#pragma mark ---- 主认证方式接口

/*! @brief
 主认证方式---------用户名密码认证
 
 @discussion
 SDK初始化以及进行用户名/密码认证
 先开始vpn初始化流程，初始化成功之后自动开始用户名/密码认证流程
 
 @param mode VPN模式
 @param url VPN地址
 @param username 用户名
 @param password 密码
 */
- (void)startPasswordAuthLogin:(VPNMode)mode
                    vpnAddress:(NSURL *)url
                      username:(NSString *)username
                      password:(NSString *)password;

/*! @brief
 主认证方式---------证书认证
 
 @discussion
 SDK初始化以及进行证书认证
 先开始vpn初始化流程，初始化成功之后自动开始证书认证流程
 
 @param mode VPN模式
 @param url VPN地址
 @param cerPath 证书路径
 @param cerPassword 证书密码
 */
- (void)startCertificateAuthLogin:(VPNMode)mode
                       vpnAddress:(NSURL *)url
                  certificatePath:(NSString *)cerPath
              certificatePassword:(NSString *)cerPassword;

/*! @brief
 主认证方式---------共享session认证
 
 @discussion
 SDK初始化以及进行共享session认证
 先开始vpn初始化流程，初始化成功之后自动开始共享session认证流程
 
 @param mode VPN模式
 @param url VPN地址
 @param session 共享session
 */
- (void)startSessionAuthLogin:(VPNMode)mode
                   vpnAddress:(NSURL *)url
                      session:(NSString *)session;

/*! @brief
 主认证方式--------钉钉认证
 
 @discussion
 SDK初始化以及进行钉钉Code认证
 先开始vpn初始化流程，初始化成功之后自动开始钉钉认证流程
 
 @param mode VPN模式
 @param url VPN地址
 @param code 钉钉的Code
 */
- (void)startCodeAuthLogin:(VPNMode)mode
                vpnAddress:(NSURL *)url
                      code:(NSString *)code;

/*! @brief
 主认证方式-------Ticket认证
 @discussion
 其他的登录信息从保存的配置中获取
 
 @param mode VPN模式
 */
- (void)startTicketAuthLogin:(VPNMode)mode;

#pragma mark ---- 注销

/*! @brief
 注销VPN
 */
- (void)vpnLogout;

#pragma mark ---- 主动调用获取信息

/*! @brief
 判断当前是否支持免密登录
 1，未成功登录成功过，不支持
 2，Ticket中的ticketEnable为NO，不支持
 @return YES:支持
 */
- (BOOL)ticketAuthAvailable;

/*! @brief
 获取共享登录的Session
 
 @return Session
 */
- (NSString *)getSession;

/*! @brief
 获取VPN状态
 
 @discussion 代表VPN在本地的状态，会定时跟服务端同步，值参考VPNStatus枚举。
 未初始化SDK时调用将直接返回 VPNStatusOffLine，如需要在不初始化SDK时获取插件存活状态，
 可以使用 - (void)querySFNEStaus:(void (^)(SFNEStatus neStatus)) queryHandler
 
 @return VPN状态
 */
- (VPNStatus)queryStatus;


/*! @brief
 异步获取NetworkExtion扩展的状态
 
 @discussion 表示NetworkExtion扩展是否处于正确的状态（是否正在运行）
 
 */
- (void)querySFNEStaus:(void (^)(SFNEStatus neStatus)) queryHandler;


/*! @brief
 重新获取短信验证码，请求为阻塞型
 
 @return 短信认证中用到的信息
 */
- (SmsMessage *)reacquireSmsCode;

/*! @brief
 主动获取图形校验码
 
 @discussion
 用于更新图形校验码，结果需要回调onRndCodeCallback实现
 */
- (void)reacquireRandCode;

/*! @brief
 主动调用修改VPN账号密码
 异步回调
 @param prePassword 旧密码
 @param newPassword 新密码
 @param complete 修改密码之后的结果回调(主线程)
 */
- (void)changePassword:(NSString *)prePassword newPassword:(NSString *)newPassword
              complete:(void(^)(bool result, NSError *error))complete;

@end
