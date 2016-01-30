//
//  OpenImageViewController.m
//  ImageGallery
//
//  Created by Vladas Zakrevskis on 31/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "OpenImageViewController.h"

@interface OpenImageViewController ()

@end

@implementation OpenImageViewController

- (void)viewDidLoad {
    [super viewDidLoad];

}

- (void)viewWillAppear:(BOOL)animated
{
    NSLog(@"%lu", (unsigned long)self.imageNumber);
}


@end
