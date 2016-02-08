//
//  PhotoViewController.m
//  MyTableView
//
//  Created by Vladas Zakrevskis on 07/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "PhotoViewController.h"

@interface PhotoViewController ()

@property (nonatomic, weak) IBOutlet UIImageView *imageView;

@end

@implementation PhotoViewController

-(void)viewWillAppear:(BOOL)animated
{    
    self.imageView.image = self.photoImage;
}

@end
