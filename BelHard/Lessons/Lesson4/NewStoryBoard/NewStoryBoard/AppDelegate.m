//
//  AppDelegate.m
//  NewStoryBoard
//
//  Created by Vladas Zakrevskis on 19/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import "SecondViewController.h"
#import "ThirdViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    self.window = [[UIWindow alloc] initWithFrame:
                   [UIScreen mainScreen].bounds];
    
    [self.window makeKeyAndVisible];
    
    // lesson 5
    
    ViewController *controller = [[ViewController alloc] init];
    SecondViewController *secondController = [[SecondViewController alloc] init];
    ThirdViewController *thirdController = [[ThirdViewController alloc] init];
    
    UINavigationController *navigationController =
    [[UINavigationController alloc]
     initWithRootViewController:controller];

    UINavigationController *secondNavigationController =
    [[UINavigationController alloc]
     initWithRootViewController:secondController];
    
    UINavigationController *thirdNavigationController =
    [[UINavigationController alloc]
     initWithRootViewController:thirdController];
    
    controller.title = @"controller";
    secondController.title = @"secondController";
    thirdController.title = @"thirdController";
    
    
    UITabBarController *tabBarController = [[UITabBarController alloc] init];

    [tabBarController setViewControllers:@[navigationController, secondNavigationController, thirdNavigationController]];
    
    self.window.rootViewController = tabBarController;
    
    return YES;
}


@end
