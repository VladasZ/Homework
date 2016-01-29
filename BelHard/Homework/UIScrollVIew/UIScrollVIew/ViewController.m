//
//  ViewController.m
//  UIScrollVIew
//
//  Created by Vladas Zakrevskis on 30/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"



@interface ViewController ()

@property (nonatomic) CGSize screenSize;

@property (nonatomic, strong) UIImage *image;
@property (nonatomic, strong) UIScrollView *scrollView;


@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    
    _screenSize = CGSizeMake(self.view.frame.size.width, self.view.frame.size.height);
    
    _image = [UIImage imageNamed:@"1.jpg"];
    
    _scrollView = [[UIScrollView alloc] initWithFrame:self.view.frame];
    _scrollView.pagingEnabled = YES;
    
    [self.view addSubview:_scrollView];
    
    CGRect imageRect = CGRectMake(10, 10, _screenSize.width - 20, _screenSize.height - 20);
    
    
    
    

    for (NSUInteger i = 0; i < 10; i++) {
        
        UIImageView *imageView = [[UIImageView alloc] initWithFrame:imageRect];
        [imageView setImage:_image];
        
        [_scrollView addSubview:imageView];
        
        _scrollView.contentSize = CGSizeMake(_screenSize.width, _screenSize.height * (i + 1));
        
        imageRect.origin.y += _screenSize.height;
    }
   
    
}


@end
