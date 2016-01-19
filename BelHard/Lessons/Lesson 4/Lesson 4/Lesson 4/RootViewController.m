//
//  RootViewController.m
//  Lesson 4
//
//  Created by Vladas Zakrevskis on 19/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "RootViewController.h"
#import "ViewController.h"

@interface RootViewController ()



- (IBAction)didPressButton:(UIButton *)sender;

@end

@implementation RootViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void) viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:YES];
    
}

- (void) viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:YES];
    //self.view.backgroundColor = [UIColor blackColor];
}

- (void) viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:YES];
}

- (void) viewDidLayoutSubviews
{
    [super viewDidLayoutSubviews];
}

- (IBAction)didPressButton:(UIButton *)sender
{
    
    ViewController *controller = [self.storyboard instantiateViewControllerWithIdentifier:NSStringFromClass([ViewController class])];
    
    [self.navigationController pushViewController:controller animated:YES];
    
    NSLog(@"%@",[self.navigationController viewControllers]);
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
