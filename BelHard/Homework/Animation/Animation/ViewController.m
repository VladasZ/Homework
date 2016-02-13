//
//  ViewController.m
//  Animation
//
//  Created by Vladas Zakrevskis on 13/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic, weak) IBOutlet UIImageView *gunImageView;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.gunImageView.frame =
    CGRectMake(100,
               -100,
               self.gunImageView.frame.size.width,
               self.gunImageView.frame.size.height);
    
    [self.view addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(didTap:)]];
}

- (void)didTap:(UITapGestureRecognizer *)sender
{
    NSLog(@"%@", sender);
}



@end
