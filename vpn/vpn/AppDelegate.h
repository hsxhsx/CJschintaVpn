//
//  AppDelegate.h
//  vpn
//
//  Created by MacDev02 on 2019/5/5.
//  Copyright © 2019年 www.schinta.com.cn. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

