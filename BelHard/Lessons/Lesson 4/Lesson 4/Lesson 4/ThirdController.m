//
//  ThirdController.m
//  Lesson 4
//
//  Created by Vladas Zakrevskis on 19/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ThirdController.h"
#import "FirstController.h"
#import "SecondController.h"

@interface ThirdController ()

- (IBAction)didPressButton:(UIButton *)sender;

@end

@implementation ThirdController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}


- (IBAction)didPressButton:(UIButton *)sender
{
   // [self.navigationController popToRootViewControllerAnimated:YES];
    
    UIViewController *popViewController = nil;
    
    for (UIViewController *controller in self.navigationController.viewControllers) {
        if ([controller isKindOfClass:[FirstController class]]) {
            popViewController = controller;
        }
    }
    
    if (popViewController) {
        [self.navigationController popToViewController:popViewController animated:YES];
    }
    

    
}

@end
