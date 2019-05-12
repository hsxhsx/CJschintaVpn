//
//  xxViewController.h
//  vpn
//
//  Created by 胡双喜 on 2019/5/8.
//  Copyright © 2019 www.schinta.com.cn. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SangforAuthManager.h"
#import "SxfvpnCallback.h"

NS_ASSUME_NONNULL_BEGIN

@interface SxfViewController : UIViewController
- (void)initSangforSdk;
- (instancetype)init:(UIViewController *)rootController claaBack:(SxfvpnCallback *)sxfvpnCallback app:(UIApplication *)app;
@end

NS_ASSUME_NONNULL_END
