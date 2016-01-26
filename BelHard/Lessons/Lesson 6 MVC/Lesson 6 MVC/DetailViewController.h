//
//  DetailViewController.h
//  Lesson 6 MVC
//
//  Created by Vladas Zakrevskis on 26/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VZUserDefaults.h"

@interface DetailViewController : UIViewController

@property (strong, nonatomic) id detailItem;
@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@property (nonatomic, strong) VZUserDefaults *userDefaults;

@end

