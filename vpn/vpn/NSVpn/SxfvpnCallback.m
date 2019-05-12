//
//  SxfvpnCallback.m
//  VPNDemo
//
//  Created by 胡双喜 on 2019/5/7.
//  Copyright © 2019 sangfor. All rights reserved.
//

#import "SxfvpnCallback.h"
@interface SxfvpnCallback()
@property (nonatomic,assign)int state ;
@property (nonatomic,assign)int callback ;

@end
@implementation SxfvpnCallback
- (void)stateChange:(int)state callback:(int)callback{
    _state = state;
    _callback = callback;
}
@end
