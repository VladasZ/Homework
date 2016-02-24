//
//  ViewController.m
//  Animations
//
//  Created by Vladas Zakrevskis on 11/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic, strong) UIImageView *animatedImageView;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self.view addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(didTap:)]];
    
    UIImageView *animatedImageView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, 100, 100)];
    
    [animatedImageView setImage:[UIImage imageNamed:@"6.jpg"]];
    [animatedImageView setContentMode:UIViewContentModeScaleAspectFill];
    
    [self.view addSubview:animatedImageView];
    [self setAnimatedImageView:animatedImageView];

}

- (void)didTap:(UITapGestureRecognizer *)sender
{
    CGPoint tapLocation = [sender locationInView:self.view];
    
   // CGRect frame = CGRectMake(tapLocation.x - 50, tapLocation.y - 50, 100, 100);
    
//    UIView *animatedView = [[UIView alloc] initWithFrame:frame];
//    
//    [animatedView setBackgroundColor:[UIColor colorWithRed:0.0 green:255.0/255.0 blue:0.3 alpha:0.3]];
//    
//    animatedView.layer.transform = CATransform3DMakeScale(0.0, 0.0, 0.0);
//    animatedView.layer.cornerRadius = animatedView.bounds.size.height / 2;
//    animatedView.layer.masksToBounds = YES;
//    
//    [UIView animateWithDuration:2.0 delay:0 options:UIViewAnimationOptionRepeat animations:^{
//        
//        animatedView.layer.transform = CATransform3DMakeScale(1.0, 1.0, 1.0);
//        animatedView.alpha = 0.0;
//        
//    } completion:^(BOOL finished) {
//        
//        animatedView.layer.transform = CATransform3DMakeScale(0.0, 0.0, 0.0);
//        animatedView.alpha = 0.3;
//        
//    }];
    
    __block CGRect frame = self.animatedImageView.frame;
    
    frame.origin.x = tapLocation.x;
    frame.origin.y = tapLocation.y;
    
    [UIView animateWithDuration:0.2 delay:0 options:UIViewAnimationOptionCurveEaseInOut animations:^{
        
        self.animatedImageView.frame = frame;
        
    } completion:^(BOOL finished) {
        
//        frame.origin.x -= 100.0;
//        frame.origin.y -= 100.0;
//        
//        
//        [UIView animateWithDuration:2.0 delay:0 options:UIViewAnimationOptionCurveEaseInOut animations:^{
//            
//            self.animatedImageView.frame = frame;
//            
//        } completion:^(BOOL finished) {
//            
//        }];
    }];
    
    

   // [self.view addSubview:animatedView];

}


@end
