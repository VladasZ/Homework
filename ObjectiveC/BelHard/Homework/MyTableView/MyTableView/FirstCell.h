//
//  FirstCell.h
//  MyTableView
//
//  Created by Vladas Zakrevskis on 04/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Profile.h"

@protocol MyCellDelegate;

@interface FirstCell : UITableViewCell

@property (nonatomic, strong) id<MyCellDelegate> delegate;

@property (nonatomic, strong) UIImageView *photoImageView;
@property (nonatomic, strong) UILabel *label;
@property (nonatomic, strong) UIButton *pushButton;
@property (nonatomic, strong) NSString *bioInfo;

- (void)setInfoWithProfile:(Profile *)profile;

@end

@protocol MyCellDelegate <NSObject>

- (void)didPressButonOnCell:(FirstCell *)sender;
- (void)didPressOnCellImage:(FirstCell *)sender;

@end
