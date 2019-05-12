//
//  JS.m
//  vpn
//
//  Created by 胡双喜 on 2019/5/9.
//  Copyright © 2019 www.schinta.com.cn. All rights reserved.
//

#import "JS.h"

@implementation JS
-(void)scan:(NSString *)message{
    [self.delegate scan:message];
}
@end
