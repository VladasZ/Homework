//
//  ViewController.m
//  ImageGallery
//
//  Created by Vladas Zakrevskis on 30/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"
#import "OpenImageViewController.h"

@interface ViewController ()


@property (nonatomic) CGSize screenSize;
@property (nonatomic) CGSize imageViewSize;
@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) OpenImageViewController *openImageViewController;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self commonInit];
    [self mainScreenInit];
    
}

- (void)didPressImage:(UIGestureRecognizer *)gestureRecognizer
{
    self.openImageViewController.pushedImageNumber = [gestureRecognizer view].tag;
    
    [self.navigationController pushViewController:self.openImageViewController animated:YES];
}

#pragma mark - Init

- (void)commonInit
{
    self.openImageViewController = [self.storyboard instantiateViewControllerWithIdentifier:@"OpenImageViewController"];

    self.images = [NSMutableArray new];
    self.screenSize = CGSizeMake(self.view.frame.size.width, self.view.frame.size.height);
    self.imageViewSize = CGSizeMake((self.screenSize.width - 1) / 2, (self.screenSize.height - 2) / 3);
    
    self.scrollView = [[UIScrollView alloc] initWithFrame:self.view.frame];
    [self.scrollView setUserInteractionEnabled:YES];
    
    [self.view addSubview:self.scrollView];
}

- (void)mainScreenInit
{
    for (NSUInteger i = 0; i < 12; i++) {
        
        static NSUInteger row = 0;
        
        [self.images addObject:[UIImage imageNamed:[NSString stringWithFormat:@"%lu.jpg", (unsigned long)i]]];
        
        UIImageView *imageView =
        [[UIImageView alloc]initWithFrame:CGRectMake(
        (!(i % 2) ? 0 : self.imageViewSize.width + 1),
        (self.imageViewSize.height + 1) * (row),
        self.imageViewSize.width,
        self.imageViewSize.height)];
        
        if (i % 2) {
            row++;
        }
        
        [imageView setImage:[self.images lastObject]];
        
        imageView.tag = i;
        
        UITapGestureRecognizer *newTap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(didPressImage:)];
        
        [imageView addGestureRecognizer:newTap];
        [imageView setUserInteractionEnabled:YES];
        [imageView setClipsToBounds:YES];
        [imageView setContentMode:UIViewContentModeScaleAspectFill];
        
        [self.scrollView addSubview:imageView];
        [self.scrollView setContentSize:CGSizeMake(self.screenSize.width, CGRectGetMaxY(imageView.frame))];
    }
    
    [self.scrollView setContentOffset:CGPointMake(0, self.scrollView.contentSize.height - self.screenSize.height + self.navigationController.navigationBar.frame.size.height)];
    
    self.openImageViewController.images = self.images;
    self.openImageViewController.screenSize = self.screenSize;
    
}


@end
