//
//  errheader.h
//  SangforSdk
//
//  Created by panghongqin on 2017/12/9.
//

#ifndef errheader_h
#define errheader_h

/** 成功的标记 */
#define        SF_ERROR_NONE                               1000        //成功

/** 认证服务端返回的错误  */
#define        SF_ERROR_SERVER_BUSY                        1001        //操作失败，可能服务器太忙
#define        SF_ERROR_TIME_DENY                          1002        //非允许时间段，禁止登录
#define        SF_ERROR_AUTH_TYPE_DISABLE                  1003        //未启用此认证，访问被拒绝
#define        SF_ERROR_NOT_SAME_USER                      1004        //登录失败，前一认证与当前认证非同一用户
#define        SF_ERROR_AUTH_COMBINATION_INVALID           1005        //不支持此种认证组合方式
#define        SF_ERROR_LICENSED_USER_LIMIT                1006        //系统已到达最大授权用户限制
#define        SF_ERROR_GROUP_USER_LIMIT                   1007        //您所在用户组已达到最大在线用户限制
#define        SF_ERROR_ACCOUNT_LOCKED                     1008        //用户尝试暴破登录，已被系统锁定
#define        SF_ERROR_IP_LOCKED                          1009        //ip地址尝试暴破登录，已被系统锁定
#define        SF_ERROR_IP_NEED_WORD_VERIFICATION          1010        //ip地址尝试暴破登录，启用图形校验码
/**用户名认证*/
#define        SF_ERROR_PASSWOR_INVALID                    1101        //用户名或者密码错误
#define        SF_ERROR_USER_EXPIRE                        1102        //用户已过期
#define        SF_ERROR_USER_DISABLE                       1103        //用户被禁用
#define        SF_ERROR_USER_TIMEOUT                       1104        //用户已超时或注销
#define        SF_ERROR_CHARACTERS_INCORRECT               1105        //校验码错误或校验码已过期
#define        SF_ERROR_USER_NEED_WORD_VERIFICATION        1106        //用户名或密码错误，启用图形校验码
/**证书认证*/
#define        SF_ERROR_CERTIFICATE_INVALID                1201        //证书不合法
#define        SF_ERROR_CERTIFICATE_AUTH_DISABLE           1202        //证书认证被禁用
#define        SF_ERROR_CERTIFICATE_REVOKED                1203        //证书已经被撤消
#define        SF_ERROR_CERTIFICATE_CODE_ERR               1204        //证书编码设置有误，请联系管理员
#define        SF_ERROR_CERTIFICATE_SIGN_INVALID           1205        //证书签名无效
#define        SF_ERROR_CERTIFICATE_NOT_EFFECT             1206        //证书还未生效
#define        SF_ERROR_CERTIFICATE_EXPIRE                 1207        //证书已经过期
/**免密认证*/
#define        SF_ERROR_TICKET_MOBID_INVALID               1301        //免密认证无效的手机ID
#define        SF_ERROR_TICKET_CODEID_INVALID              1302        //免密认证无效的code
#define        SF_ERROR_TICKET_PASS_CLOSE                  1303        //免密认证功能未开启
#define        SF_ERROR_TICKET_UNKOWN                      1304        //未知错误
/**短信校验码认证*/
#define        SF_ERROR_SEND_SMS_MESSAGE                   1401        //发送短信失败
#define        SF_ERROR_SMS_PASSWORD_INVALID               1402        //短信验证码错误
#define        SF_ERROR_NOT_SET_PHONE_NUMBER               1403        //用户未设置手机号码，无法进行短信认证
#define        SF_ERROR_PHONE_NUMBER_INCORRECT             1404        //提交的手机号码错误，无法进行短信认证
/**EMM授权认证*/
#define        SF_ERROR_EMM_NOT_AUTHORZATION               1501        //EMM授权不通过，请联系管理员更新授权
#define        SF_ERROR_EMM_DEVICE_LIMIT                   1502        //EMM授权达到最大数
#define        SF_ERROR_EMM_DEVICE_FROZEN                  1503        //EMM授权被冻结
#define        SF_ERROR_EMM_FAILED                         1504        //EMM授权认证失败
/**硬件特征码认证*/
#define        SF_ERROR_HID_VERIFY_FAILED                  1601        //硬件特征码验证失败
#define        SF_ERROR_HID_EXIST_NOTPASSED                1602        //存在未审批的硬件特征码,等待管理员审批
#define        SF_ERROR_HID_INVALID                        1603        //用户超时或硬件特征码无效输入
#define        SF_ERROR_HID_LIMIT                          1604        //硬件特征数达到最大值
#define        SF_ERROR_HID_UPDATE_FAILED                  1605        //更新硬件特征码失败
#define        SF_ERROR_HID_GROUP_LIMIT                    1606        //硬件特征码达到组用户最大限制
#define        SF_ERROR_HID_SN_LIMIT                       1607        //硬件特征码达到授权限制
#define        SF_ERROR_HID_FAILED                         1608        //当前终端未经过硬件特征码验证，请等待管理员审批
#define        SF_ERROR_HID_SUBMIT_FAILED                  1609        //提交硬件特征码失败
/**外部认证等*/
#define        SF_ERROR_NO_EXTERNAL_SERVER                 1701        //没有对应的外部认证服务器，认证失败
#define        SF_ERROR_TOKEN_PASSWORD_INCORRECT           1702        //动态令牌密码错误，认证失败
#define        SF_ERROR_CHALLENGE_FAILED                   1703        //挑战认证失败
#define        SF_ERROR_CHALLENGE_TIMEOUT                  1704        //radius挑战超时

/** 本地认证的错误 */
#define        SF_ERROR_CONNECT_VPN_FAILED                 2001        //连接VPN服务器错误，请检查网络
#define        SF_ERROR_URL_INVALID                        2002        //VPN的URL为空
#define        SF_ERROR_DOMAN_RESOLVE_FAILED               2003        //域名解析失败
#define        SF_ERROR_CRACKED_PHONE                      2004        //越狱手机禁止登陆
#define        SF_ERROR_SELECT_LINE_FAILED                 2005        //VPN选路失败
#define        SF_ERROR_NET_INVALID                        2006        //网络不可用
#define        SF_ERROR_ADDRESS_FORMAT                     2007        //vpn地址格式有误

#define        SF_ERROR_AUTH_PARAM_EMPTY                   2101        //认证参数为空
#define        SF_ERROR_AUTH_TYPE_INVALID                  2102        //调用的方法与当前认证方式不一致
#define        SF_ERROR_CERTIFICATE_NOT_EXIST              2103        //证书不存在
#define        SF_ERROR_CERTIFICATE_TYPE_ERROR             2104        //证书类型获取失败
#define        SF_ERROR_TICKET_AUTH_DISABLE                2105        //免密认证不可用
#define        SF_ERROR_BUILD_REQUEST                      2106        //构建请求失败
#define        SF_ERROR_SESSION_INVALID                    2107        //session无效
#define        SF_ERROR_AUTH_TYPE_UNSPPORT                 2108        //认证类型不支持
#define        SF_ERROR_STATUS_ERROR                       2109        //登录VPN状态错误，注销后再进行登录
#define        SF_ERROR_HID_GET_ERROR                      2110        //读取硬件特征码失败
#define        SF_ERROR_AUTH_INIT_ERROR                    2111        //VPN初始化失败

#define        SF_ERROR_START_L3VPN_FAILED                 2201        //启动L3VPN失败

/** 非认证产生的错误 */
#define        SF_ERROR_CHPWD_TIMEOUT                      3001        //用户超时
#define        SF_ERROR_CHPWD_NO_PERMISSION                3002        //不属于本地密码认证用户
#define        SF_ERROR_CHPWD_GETINFO_FAIL                 3003        //获取用户信息失败
#define        SF_ERROR_CHPWD_WRONG_PWD                    3004        //密码输入错误
#define        SF_ERROR_CHPWD_SAFE_POLICY                  3005        //不符合密码策略
#define        SF_ERROR_CHPWD_FAILED                       3006        //修改密码请求错误
#define        SF_ERROR_VPN_NOT_LOGIN                      3007        //VPN未登录导致修改密码失败
#define        SF_ERROR_NEW_PASSWORD_SAME_AS_OLD           3008        //新密码与原密码相同
#define        SF_ERROR_FORWARD_FAILED                     3101        //转发线程启动失败
#define        SF_ERROR_OUT_OF_MEMORY                      3201        //内存不足

/** 其它错误 */
#define        SF_ERROR_OTHER_ERROR                        4001        //其它错误

#endif /* errheader_h */
