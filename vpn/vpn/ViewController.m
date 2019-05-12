//
//  ViewController.m
//  vpn
//
//  Created by MacDev02 on 2019/5/5.
//  Copyright © 2019年 www.schinta.com.cn. All rights reserved.
//

#import "ViewController.h"
//#import "Sxfvpn.h"
//#import "SxfvpnCallback.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
//    SxfvpnCallback *callback = [SxfvpnCallback new];
//    Sxfvpn *sxfvpn = [[Sxfvpn alloc] init:callback];
//
//
//    BOOL isSuccess =  [sxfvpn startVPNInitAndLogin:@"https://222.180.194.114:443" name:@"cjkcliukang" passwd:@"5c7mq&68"];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(getvpn:) name:@"vpnState" object:nil];
    
}

- (void)getvpn:(NSNotification *)notification{
    NSLog(@"%@",notification);
}

@end
