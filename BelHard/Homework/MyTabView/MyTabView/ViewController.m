//
//  ViewController.m
//  MyTabView
//
//  Created by Vladas Zakrevskis on 24/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

-(void)didPressRightBUtton:(UIButton *)sender
{
    
    [self addChildViewController:[self.storyboard instantiateViewControllerWithIdentifier:@"rightViewController"]];
    
    [self.view addSubview:[self.storyboard instantiateViewControllerWithIdentifier:@"rightViewController"].view];
    
    [self presentViewController:[self.storyboard instantiateViewControllerWithIdentifier:@"rightViewController"] animated:NO completion:nil];
}

@end
