//
//  ViewController.m
//  Lesson 4
//
//  Created by Vladas Zakrevskis on 19/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

- (IBAction)didPressPop:(UIButton *)sender;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void) viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:YES];
    
    self.navigationController.navigationBarHidden = YES;
    
}

- (void) viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:YES];
    
    self.navigationController.navigationBarHidden = NO;
}

- (IBAction)didPressPop:(UIButton *)sender
{
    //back to root
   // [self.navigationController popToRootViewControllerAnimated:YES];
    
    //back
    [self.navigationController popViewControllerAnimated:YES];
    

    
}


@end
