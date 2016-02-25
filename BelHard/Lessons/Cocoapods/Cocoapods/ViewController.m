//
//  ViewController.m
//  Cocoapods
//
//  Created by Vladas Zakrevskis on 18/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"
#import "MUser.h"
#import <MagicalRecord/MagicalRecord.h>
#import "NetworkManager.h"

#import <UIImageView+WebCache.h>

#import <SVProgressHUD/SVProgressHUD.h>
#import <SDWebImageDownloader.h>

NSString * const firstImegeURL  =
@"http://www.curezone.org/upload/Members/New02/nasa1R3107_1000x1000.jpg";
NSString * const secondImegeURL =
@"http://img3.etsystatic.com/il_fullxfull.273213763.jpg";
NSString * const thirdImegeURL  = @"http://gascanmusic.com/wp-content/uploads/2011/05/SetItFree_jacket1000.jpg";
NSString * const fourthImegeURL = @"http://www.nasa.gov/images/content/156183main_sohoflare2000_1000x1000.jpg";
NSString * const fifthImegeURL  = @"http://gascanmusic.com/wp-content/uploads/2011/05/SetItFree_jacket1000.jpg";
NSString * const sixthImegeURL  = @"http://img3.etsystatic.com/il_fullxfull.273213763.jpg";


@interface ViewController ()

@property (nonatomic, weak) IBOutlet UIImageView *imageView;
@property (nonatomic, weak) IBOutlet UIImageView *secondImageView;
@property (nonatomic, weak) IBOutlet UIImageView *thirdImageView;
@property (nonatomic, weak) IBOutlet UIImageView *fourthImageView;
@property (nonatomic, weak) IBOutlet UIImageView *fifthImageView;
@property (nonatomic, weak) IBOutlet UIImageView *sixthImageView;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    [[SDImageCache sharedImageCache] cleanDisk];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
   
    
    
    [self setIndicatorForImageView:self.imageView withUrl:fifthImegeURL];
    [self setIndicatorForImageView:self.secondImageView withUrl:secondImegeURL];
    [self setIndicatorForImageView:self.thirdImageView withUrl:thirdImegeURL];
    [self setIndicatorForImageView:self.fourthImageView withUrl:fourthImegeURL];
    [self setIndicatorForImageView:self.fifthImageView withUrl:fifthImegeURL];
    [self setIndicatorForImageView:self.sixthImageView withUrl:sixthImegeURL];

    
}

- (void)setIndicatorForImageView:(UIImageView *)imageView
                         withUrl:(NSString *)URLString
{
    NSURL *imageURL = [NSURL URLWithString:URLString];
    
    UIActivityIndicatorView *indicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
    
    indicator.frame = imageView.bounds;
    [indicator startAnimating];
    [imageView addSubview:indicator];
    
    [imageView sd_setImageWithURL:imageURL completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType, NSURL *imageURL) {
        
        [indicator removeFromSuperview];
        
    }];
    
}

- (void)SDWebImage_SVProgressHUD
{
    NSURL *imageURL = [NSURL URLWithString:@"https://pp.vk.me/c629203/v629203508/1e325/WbiHX4x9n_s.jpg"];
    
    [SVProgressHUD showWithMaskType:SVProgressHUDMaskTypeGradient];
    
    //    [self.imageView sd_setImageWithURL:imageURL
    //                      placeholderImage:[UIImage imageNamed:@"placeholder.jpg"] completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType, NSURL *imageURL) {
    //
    //                          [SVProgressHUD dismiss];
    //
    //    }];
    
    __weak typeof(ViewController *)weakSelf = self;
    __block CGFloat progress;
    
    [[SDWebImageDownloader sharedDownloader] downloadImageWithURL:imageURL options:SDWebImageDownloaderLowPriority progress:^(NSInteger receivedSize,
                                                                                                                              NSInteger expectedSize) {
        
        progress = (CGFloat)receivedSize / (CGFloat)expectedSize;
        
        [[NSOperationQueue mainQueue] addOperationWithBlock:^{
            
            [SVProgressHUD showProgress:progress maskType:SVProgressHUDMaskTypeGradient];
            
        }];
        
    } completed:^(UIImage *image, NSData *data, NSError *error, BOOL finished) {
        
        [SVProgressHUD dismiss];
        [weakSelf.imageView setImage:image];
        
    }];
    

}

- (void)magicalRecord
{
    MUser *newUser = [MUser MR_findFirstByAttribute:@"mobID" withValue:@"2"];
    
    if (newUser == nil) {
        
        newUser = [MUser MR_createEntity];
        newUser.mobID = @"1";
        newUser.mobFirstName = @"Petja";
        newUser.mobLastName = @"Petrov";
        
        [[NSManagedObjectContext MR_defaultContext] MR_saveToPersistentStoreWithCompletion:^(BOOL contextDidSave, NSError * _Nullable error) {
            
            if (error != nil) {
                NSLog(@"%@", error);
            } else if(contextDidSave){
                NSLog(@"Context has been saved");
            }
            
        }];
        
        
        
    }
    
    NSLog(@"All users - %@", [MUser MR_findAll]);
    
    
    
    
}

- (void)AFNetworking
{
    [[NetworkManager sharedManager] getSomeDataWithSuccessBlock:^(id responseObject) {
        
        NSLog(@"Response object - %@", responseObject);
        
    } failureBlock:^(NSError *error) {
        
        NSLog(@"Error - %@", error);
        
    }];
}

@end
