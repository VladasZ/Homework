//
//  ProfileCell.h
//  Lesson 8
//
//  Created by Vladas Zakrevskis on 04/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ProfileCellDelegate;


@interface ProfileCell : UITableViewCell

@property (nonatomic, strong) id<ProfileCellDelegate> delegate;

@property (nonatomic, weak) IBOutlet UIImageView *icon;
@property (nonatomic, weak) IBOutlet UILabel *firstNameLabel;
@property (nonatomic, weak) IBOutlet UILabel *secondNameLabel;
@property (nonatomic, weak) IBOutlet UIButton *actionButton;

- (IBAction)didPressActionButton:(UIButton *)sender;

@end


@protocol ProfileCellDelegate <NSObject>

- (void)didPressButtonOnCell:(ProfileCell *)cell;

@end
