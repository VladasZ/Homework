//
//  OpenImageViewController.m
//  ImageGallery
//
//  Created by Vladas Zakrevskis on 31/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "OpenImageViewController.h"

@interface OpenImageViewController () <UIScrollViewDelegate>

@property (nonatomic, strong) UIScrollView *scrollView;

@end

@implementation OpenImageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.scrollView = [[UIScrollView alloc] initWithFrame:self.view.frame];
    self.scrollView.pagingEnabled = YES;
    
    for (NSUInteger i = 0; i < 12; i++) {
        
        UIImageView *imageView = [[UIImageView alloc] initWithImage:[self.images objectAtIndex:i]];

        UIScrollView *scrollView =
        [[UIScrollView alloc]initWithFrame:CGRectMake(
        self.screenSize.width * i,
        0,
        self.screenSize.width,
        self.screenSize.height - self.navigationController.navigationBar.frame.size.height)];
        
        
        [scrollView setDelegate:self];
        [scrollView setContentSize:[[self.images objectAtIndex:i] size]];
        [scrollView addSubview:imageView];
        [scrollView setMaximumZoomScale:5];
        [scrollView setMinimumZoomScale:self.screenSize.width / [[self.images objectAtIndex:i] size].width];
        [scrollView zoomToRect:imageView.frame animated:NO];
        
        [self.scrollView addSubview:scrollView];
        
        [self.scrollView setContentSize:CGSizeMake(CGRectGetMaxX(scrollView.frame), self.screenSize.width)];
        
    }
    
    [self.view addSubview:self.scrollView];

}

- (void)viewWillAppear:(BOOL)animated
{
    [self.scrollView setContentOffset:CGPointMake((self.pushedImageNumber * self.screenSize.width), 0)];
}

-(UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView
{
    
    for (UIView *view in scrollView.subviews) {
        
        if ([view isKindOfClass:[UIImageView class]])
            return view;
        
    }
    
    return nil;
}


@end
