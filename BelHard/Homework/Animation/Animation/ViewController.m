//
//  ViewController.m
//  Animation
//
//  Created by Vladas Zakrevskis on 13/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

#define DEGREES_TO_RADIANS(x) (M_PI * (x) / 180.0)
#define RADIANS_TO_DEGREES(radians) ((radians) * (180.0 / M_PI))

const NSUInteger GunWidth = 219;
const NSUInteger GunHeight = 240;

const NSUInteger BulletWidth = 38;
const NSUInteger BulletHeight = 15;

const CGFloat BulletSpeed = 0.5;

@interface ViewController ()

@property (nonatomic, strong) UIImageView *gunImageView;
@property (nonatomic, strong) UIImageView *gunFireImageView;

@property (nonatomic) CGPoint gunRotatePoint;
@property (nonatomic) NSUInteger maxBulletDistance;
@property (nonatomic) CGFloat cornerAngle;
@property (nonatomic) CGFloat gunFireLocation;

@property (nonatomic, strong) AVAudioPlayer *audioPlayer;

@property (nonatomic, strong) NSURL *audioUrl;


@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self gunImageViewInit];
    
    NSString *path = [NSString stringWithFormat:@"%@/shotSOund.mp3", [[NSBundle mainBundle] resourcePath]];
    
    self.audioUrl = [NSURL fileURLWithPath:path];
    
    self.audioPlayer = [[AVAudioPlayer alloc] initWithContentsOfURL:self.audioUrl error:nil];
    
    
    
    [self.view addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(didTap:)]];
}

#pragma mark - Views init

- (void)gunImageViewInit
{
    self.gunImageView = [[UIImageView alloc] initWithFrame:
    CGRectMake(0,
               self.view.frame.size.height / 2 - GunHeight / 2,
               GunWidth,
               GunHeight)];
    
    [self.gunImageView setImage:[UIImage imageNamed:@"gun.png"]];
    
    self.gunImageView.layer.zPosition = 1;
    
    [self.view addSubview:self.gunImageView];
    
    self.gunRotatePoint =
    CGPointMake(self.gunImageView.frame.origin.x + self.gunImageView.frame.size.width / 2,
                self.gunImageView.frame.origin.y + self.gunImageView.frame.size.height / 2);
    
    self.maxBulletDistance =
    sqrt(pow(self.view.frame.size.width - self.gunRotatePoint.x, 2) +
         pow(self.view.frame.size.height - self.gunRotatePoint.y, 2));
    
    self.cornerAngle = [self tapRotateAngle:
    CGPointMake(self.view.frame.size.width,
                0)];
    
    self.gunFireImageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"gunFire.png"]];
    
}

#pragma mark - Actions

- (void)didTap:(UITapGestureRecognizer *)sender
{
    CGPoint tapLocation = [sender locationInView:self.view];
    
    if (tapLocation.x < self.gunRotatePoint.x) {
        tapLocation.x += self.gunRotatePoint.x - tapLocation.x;
    }
    
    CGFloat tapRotateAngle = [self tapRotateAngle:tapLocation];
    
    [self.gunImageView setTransform:
     CGAffineTransformMakeRotation(tapRotateAngle)];
    
    [self.view addSubview:[self shotBulletAtAngle:tapRotateAngle]];
    
    self.audioPlayer = [[AVAudioPlayer alloc] initWithContentsOfURL:self.audioUrl error:nil];
    [self.audioPlayer setVolume:0.01];
    [self.audioPlayer play];
    
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    UITouch *myTouch = [[touches allObjects] firstObject];
    CGPoint tapLocation = [myTouch locationInView: self.view];
    
    if (tapLocation.x < self.gunRotatePoint.x) {
        tapLocation.x += self.gunRotatePoint.x - tapLocation.x;
    }
    
    
    self.gunImageView.transform =
    CGAffineTransformMakeRotation([self tapRotateAngle:tapLocation]);
    
    NSLog(@"%f %f", [self tapRotateAngle:tapLocation], self.cornerAngle);

    
}

#pragma mark - Calculations

- (CGFloat)tapRotateAngle:(CGPoint)tapLocation
{
    
    CGFloat triangleA = tapLocation.x - self.gunRotatePoint.x;
    CGFloat triangleB = tapLocation.y - self.gunRotatePoint.y;
    
    return atan(triangleB / triangleA);
}

- (UIImageView *)shotBulletAtAngle:(CGFloat)tapRotateAngle
{
    
#pragma mark Bullet creation
    
    UIImageView *bulletImageView = [[UIImageView alloc] initWithFrame:
                                    CGRectMake(self.gunRotatePoint.x - BulletWidth / 2,
                                               self.gunRotatePoint.y - BulletHeight / 2,
                                               BulletWidth,
                                               BulletHeight)];
    
    [bulletImageView setImage:[UIImage imageNamed:@"bullet.png"]];
    
    
    
    
#pragma mark Calculations
    
    __block CGRect frame = bulletImageView.frame;
    
    if (tapRotateAngle <= self.cornerAngle) {
        
        frame.origin.x = - ((self.view.frame.size.height / 2) / tan(tapRotateAngle) - self.gunRotatePoint.x);
        frame.origin.y = 0;
        
    } else if (tapRotateAngle > self.cornerAngle
               && tapRotateAngle <= -self.cornerAngle) {
        
        frame.origin.x = self.view.frame.size.width - 30;
        frame.origin.y = self.view.frame.size.width * tan(tapRotateAngle) + self.view.frame.size.height / 2;
        
        
    } else if (tapRotateAngle > - self.cornerAngle){
    
        frame.origin.x = ((self.view.frame.size.height / 2) / tan(tapRotateAngle) + self.gunRotatePoint.x);
        frame.origin.y = self.view.frame.size.height + 30;
        
    }
    
    CGFloat bulletDistance =
    sqrt(pow(frame.origin.x - self.gunRotatePoint.x, 2) +
         pow(frame.origin.y - self.gunRotatePoint.y, 2));
    
    CGFloat bulletSpeed = BulletSpeed * (bulletDistance / self.maxBulletDistance);
    
    
    
    
#pragma mark Animation
    
    [UIView animateWithDuration:bulletSpeed animations:^{
        bulletImageView.frame = frame;
        
    } completion:^(BOOL finished) {
        
        bulletImageView.layer.zPosition = 2;
        
        //stackoverflow
        CABasicAnimation* animation = [CABasicAnimation animationWithKeyPath:@"transform.rotation.z"];
        animation.fromValue = [NSNumber numberWithFloat:0.0f];
        animation.toValue = [NSNumber numberWithFloat: 2*M_PI];
        animation.duration = 0.3;
        animation.repeatCount = INFINITY;
        [bulletImageView.layer addAnimation:animation forKey:@"SpinAnimation"];
        
        
        frame.origin.y = bulletImageView.frame.origin.y + self.view.frame.size.height;
        
        [bulletImageView setTransform:CGAffineTransformMakeRotation(0)];

        
        [UIView animateWithDuration:1 animations:^{
            bulletImageView.frame = frame;
        } completion:^(BOOL finished) {
            [bulletImageView removeFromSuperview];
            
            
            
            
        }];
        
        
        
    }];
    
    [bulletImageView setTransform:
     CGAffineTransformMakeRotation(tapRotateAngle)];
    
    
#pragma mark Gun fire
    
    
    
    
    return bulletImageView;
}



@end
