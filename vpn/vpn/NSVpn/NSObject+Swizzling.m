//
//  NSObject+Swizzling.m
//  NSobject
//
//  Created by  on 2017/4/6.
//  Copyright © 2017年 . All rights reserved.
//
#import <objc/runtime.h>
#import "NSObject+Swizzling.h"

@implementation NSObject (Swizzling)
+(void)swizzleMethod:(SEL)origoinalSelector swizzledSelector:(SEL)swizzledSelector{
    Class class = [self class];
    Method orignalMethod = class_getInstanceMethod(class, origoinalSelector);
    Method swizzledMethod = class_getInstanceMethod(class, swizzledSelector);
    BOOL didAddMethod = class_addMethod(class, origoinalSelector, method_getImplementation(swizzledMethod), method_getTypeEncoding(swizzledMethod));
    if(didAddMethod){
        class_replaceMethod(class, swizzledSelector, method_getImplementation(orignalMethod), method_getTypeEncoding(orignalMethod));
    }
    else{
        method_exchangeImplementations(orignalMethod, swizzledMethod);
    }
}
@end
