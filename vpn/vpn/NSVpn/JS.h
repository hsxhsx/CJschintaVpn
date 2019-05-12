//
//  JS.h
//  vpn
//
//  Created by 胡双喜 on 2019/5/9.
//  Copyright © 2019 www.schinta.com.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
NS_ASSUME_NONNULL_BEGIN
@protocol AppJSObjectDelegate <JSExport>

-(void)scan:(NSString *)message;

@end
@interface JS : NSObject<AppJSObjectDelegate>
@property(nonatomic,weak) id<AppJSObjectDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
