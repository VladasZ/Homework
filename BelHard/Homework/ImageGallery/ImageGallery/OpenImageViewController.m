//
//  OpenImageViewController.m
//  ImageGallery
//
//  Created by Vladas Zakrevskis on 31/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "OpenImageViewController.h"

@interface OpenImageViewController ()

@property (nonatomic, strong) UIScrollView *scrollView;

@end

@implementation OpenImageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.scrollView = [[UIScrollView alloc] initWithFrame:self.view.frame];
    self.scrollView.pagingEnabled = YES;
    
    
    for (NSUInteger i = 1; i <= 12; i++) {
        
        UIImageView *imageView =
        [[UIImageView alloc]initWithFrame:self.view.frame];
        
        [imageView setImage:[self.images objectAtIndex:i - 1]];
        [imageView setContentMode:UIViewContentModeScaleAspectFit];
        
        
        UIScrollView *scrollView =
        [[UIScrollView alloc]initWithFrame:CGRectMake(
                                                      
                       self.screenSize.width * (i - 1),
                       0,
                       self.screenSize.width,
                       self.screenSize.height - self.navigationController.navigationBar.frame.size.height)];
        
        
        [scrollView addSubview:imageView];
        
        [scrollView setMaximumZoomScale:50];
        [scrollView setMinimumZoomScale:0.1];
        
        [self.scrollView addSubview:scrollView];
        
        [self.scrollView setContentSize:CGSizeMake(CGRectGetMaxX(scrollView.frame), self.screenSize.width)];
        
        
    }
    
    
    [self.view addSubview:self.scrollView];


}

- (void)viewWillAppear:(BOOL)animated
{
    [self.scrollView setContentOffset:CGPointMake((self.imageNumber * self.screenSize.width), 0)];
    NSLog(@"%lu", (unsigned long)self.imageNumber);
}


@end
