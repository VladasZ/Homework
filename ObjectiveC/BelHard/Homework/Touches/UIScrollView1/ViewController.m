//
//  ViewController.m
//  UIScrollView1
//
//  Created by Vladas Zakrevskis on 29/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

@interface ViewController () 

@property (nonatomic, strong) UILabel *infoLabel;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, strong) UIImageView *imageView;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    _infoLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 300, 50)];
    _infoLabel.text = @"Hello!";
    [self.view addSubview:_infoLabel];
    
    _image = [UIImage imageNamed:@"1.jpg"];
    
    _imageView = [[UIImageView alloc] initWithImage:_image];
    
    _imageView.frame = CGRectMake(0, 0, 100, 100);
    
    [self.view addSubview:_imageView];
    
    
    
    
}

#pragma mark - Gesture recognizer methods
 
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    UITouch *myTouch = [[touches allObjects] objectAtIndex: 0];
    CGPoint currentPos = [myTouch locationInView: self.view];
    _imageView.frame = CGRectMake(currentPos.x, currentPos.y, _imageView.frame.size.height, _imageView.frame.size.width);
    [self showInfo:[NSString stringWithFormat:@"%f, %f", currentPos.x, currentPos.y]];
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    UITouch *myTouch = [[touches allObjects] objectAtIndex: 0];
    CGPoint currentPos = [myTouch locationInView: self.view];
    _imageView.frame = CGRectMake(currentPos.x, currentPos.y, _imageView.frame.size.height, _imageView.frame.size.width);
    [self showInfo:[NSString stringWithFormat:@"%f, %f", currentPos.x, currentPos.y]];
}


#pragma mark - Help methods

- (void)showInfo:(NSString *)info
{
    _infoLabel.text = info;
}

@end
