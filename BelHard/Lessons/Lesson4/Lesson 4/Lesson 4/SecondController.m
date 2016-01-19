//
//  SecondController.m
//  Lesson 4
//
//  Created by Vladas Zakrevskis on 19/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "SecondController.h"
#import "ThirdController.h"

@interface SecondController ()

- (IBAction)didPressButton:(UIButton *)sender;

@end

@implementation SecondController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}


- (IBAction)didPressButton:(UIButton *)sender
{
    ThirdController *controller = [self.storyboard instantiateViewControllerWithIdentifier:NSStringFromClass([ThirdController class])];
    
    [self.navigationController pushViewController:controller animated:YES];
}


@end
