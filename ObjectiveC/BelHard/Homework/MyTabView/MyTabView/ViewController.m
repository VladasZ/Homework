//
//  ViewController.m
//  MyTabView
//
//  Created by Vladas Zakrevskis on 24/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic, weak) IBOutlet UIView *containerView;

@end

@implementation ViewController

- (void)didPressLeftBUtton:(UIButton *)sender
{
    UIViewController *controller = [self.storyboard instantiateViewControllerWithIdentifier:@"leftViewController"];

    controller.view.frame = self.containerView.frame;
    
    [self addChildViewController:controller];
    
    [self.containerView addSubview:controller.view];
}

-(void)didPressRightBUtton:(UIButton *)sender
{
    
    UIViewController *controller = [self.storyboard instantiateViewControllerWithIdentifier:@"rightViewController"];
    
    controller.view.frame = self.containerView.frame;
    
    [self addChildViewController:controller];
    
    [self.containerView addSubview:controller.view];
    
//    [self presentViewController:[self.storyboard instantiateViewControllerWithIdentifier:@"rightViewController"] animated:NO completion:nil];
}

@end
