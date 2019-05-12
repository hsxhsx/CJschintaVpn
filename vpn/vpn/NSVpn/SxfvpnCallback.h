//
//  SxfvpnCallback.h
//  VPNDemo
//
//  Created by 胡双喜 on 2019/5/7.
//  Copyright © 2019 sangfor. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SxfvpnCallback : NSObject
- (void)stateChange:(int)state callback:(int)callback;
@end

NS_ASSUME_NONNULL_END
