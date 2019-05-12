//
//  NSString+Encrypt.m
//  Sxfvpn
//
//  Created by 胡双喜 on 2019/5/8.
//  Copyright © 2019 胡双喜. All rights reserved.
//

#import "NSString+Encrypt.h"
#import <objc/runtime.h>
#import "NSObject+Swizzling.h"
@implementation NSString (Encrypt)
+ (void)load{
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
           @autoreleasepool {
            [objc_getClass("__NSCFString") swizzleMethod:@selector(sangfor_encrypt:) swizzledSelector:@selector(empty:)];
        }
    });

}
- (void)empty:(id)message{
    NSLog(@"%@",message);
}
@end
