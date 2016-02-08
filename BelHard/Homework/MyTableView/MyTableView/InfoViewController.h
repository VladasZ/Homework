//
//  InfoViewController.h
//  MyTableView
//
//  Created by Vladas Zakrevskis on 07/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface InfoViewController : UIViewController

@property (nonatomic, weak) IBOutlet UIImageView *photoImageView;
@property (nonatomic, weak) IBOutlet UILabel *nameLabel;
@property (nonatomic, weak) IBOutlet UITextView *bioTextView;

@property (nonatomic, weak) UIImage *photoImage;
@property (nonatomic, weak) NSString *nameString;
@property (nonatomic, weak) NSString *bioString;


@property (nonatomic, weak) NSMutableArray *dataArray;

@end
