//
//  ViewController.m
//  MyUIScrollView
//
//  Created by Vladas Zakrevskis on 01/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

@interface ViewController () <UIScrollViewDelegate>

@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) UIImageView *imageView;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    
    UIImage *image = [UIImage imageNamed:@"1.jpg"];
    
    self.imageView = [[UIImageView alloc] initWithImage:image];
    
    self.scrollView = [[UIScrollView alloc] initWithFrame:self.view.frame];
    self.scrollView.delegate = self;

    [self.scrollView setContentSize:image.size];
    [self.scrollView setMinimumZoomScale:0.1];
    [self.scrollView setMaximumZoomScale:10];
    [self.scrollView addSubview:self.imageView];
    

    [self.view addSubview:self.scrollView];
    
}



- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView
{
    return self.imageView;
}



@end
