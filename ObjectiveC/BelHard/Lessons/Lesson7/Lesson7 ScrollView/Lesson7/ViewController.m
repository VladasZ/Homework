//
//  ViewController.m
//  Lesson7
//
//  Created by Vladas Zakrevskis on 28/01/16.
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
    
    UIImage *myFirstImage = [UIImage imageNamed:@"1.jpg"];
    
    
    
    CGRect imageFrame = CGRectMake(10,
                                   10,
                                   self.view.frame.size.width  - 20,
                                   self.view.frame.size.height - 20);
    
    
    
    UIImageView *imageView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, myFirstImage.size.width, myFirstImage.size.height)];
    [imageView setImage:myFirstImage];
    
    self.imageView = [[UIImageView alloc] initWithImage:myFirstImage];
    
    [self.scrollView setContentSize:CGSizeMake(500, 500)];
    
    self.scrollView.bounces = NO;
    
    [self.scrollView addSubview:self.imageView];
    
    [self.scrollView setContentSize:myFirstImage.size];
    
    self.scrollView.minimumZoomScale = 0.1;
    self.scrollView.maximumZoomScale = 10;
    self.scrollView.zoomScale = 0.1;
    
    
    UITapGestureRecognizer *singleTapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(didSingleTapOnView:)];
    
    [self.scrollView addGestureRecognizer:singleTapRecognizer];
    
    
    UITapGestureRecognizer *doubleTapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(didDoubleTapOnView:)];
    
    doubleTapRecognizer.numberOfTapsRequired = 2;
    doubleTapRecognizer.numberOfTouchesRequired = 1;
    
    [self.scrollView addGestureRecognizer:doubleTapRecognizer];
    
    
    UILongPressGestureRecognizer *longPressRecognizer = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(didLongPressOnView:)];
    
    [self.scrollView addGestureRecognizer:longPressRecognizer];
    
    
    
    [self.view addSubview:self.scrollView];
    
    
}


#pragma mark - UIScrollViewDelegate implementation

- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
   // NSLog(@"%@", NSStringFromCGPoint(scrollView.contentOffset));
}

- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView
{
    return nil;//self.imageView;
}

- (void)didSingleTapOnView:(UIGestureRecognizer *)recognizer
{
    if (recognizer.state == UIGestureRecognizerStateEnded) {
        
        self.scrollView.zoomScale = 0.1;
        
    }
}

- (void)didDoubleTapOnView:(UIGestureRecognizer *)recognizer
{
    if (recognizer.state == UIGestureRecognizerStateEnded) {
        
        self.scrollView.zoomScale = 5.0;
        
    }
}
//
- (void)didLongPressOnView:(UILongPressGestureRecognizer *)recognizer
{
    if (recognizer.state == UIGestureRecognizerStateBegan) {
        
        self.scrollView.zoomScale = 0.1;
        
    }
    
    if (recognizer.state == UIGestureRecognizerStateChanged) {
        
        self.scrollView.zoomScale = 0.5;
        
    }
    
    if (recognizer.state == UIGestureRecognizerStateEnded) {
        
        self.scrollView.zoomScale = 1.0;
    }
    
}




@end



//vdd



/////////////////



