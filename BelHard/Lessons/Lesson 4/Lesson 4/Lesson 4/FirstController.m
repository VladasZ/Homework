//
//  FirstController.m
//  Lesson 4
//
//  Created by Vladas Zakrevskis on 19/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "FirstController.h"
#import "SecondController.h"

@interface FirstController ()

- (IBAction)didPressButton:(UIButton *)sender;

@end

@implementation FirstController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}


- (IBAction)didPressButton:(UIButton *)sender
{
    SecondController *controller = [self.storyboard instantiateViewControllerWithIdentifier:NSStringFromClass([SecondController class])];
    
    [self.navigationController pushViewController:controller animated:YES];
}



@end
