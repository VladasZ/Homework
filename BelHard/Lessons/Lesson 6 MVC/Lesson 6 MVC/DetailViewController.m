//
//  DetailViewController.m
//  Lesson 6 MVC
//
//  Created by Vladas Zakrevskis on 26/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "DetailViewController.h"

@interface DetailViewController ()

@end

@implementation DetailViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    NSLog(@"%@", [self.userDefaults getObjectForKey:VZUserDefaultsFirstName]);
}

@end
