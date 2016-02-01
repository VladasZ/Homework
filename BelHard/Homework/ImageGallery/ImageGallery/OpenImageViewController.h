//
//  OpenImageViewController.h
//  ImageGallery
//
//  Created by Vladas Zakrevskis on 31/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface OpenImageViewController : UIViewController

@property (nonatomic) NSUInteger pushedImageNumber;
@property (nonatomic, weak) NSMutableArray *images;
@property (nonatomic) CGSize screenSize;


@end
