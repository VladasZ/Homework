//
//  FirstCell.m
//  MyTableView
//
//  Created by Vladas Zakrevskis on 04/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "FirstCell.h"

const NSUInteger ButtonHeight = 30;
const NSUInteger ButtonWidth = 50;
const NSUInteger Indent = 5;

#define StandartButtonColour [UIColor colorWithRed:0 green:0.478431 blue:1.0 alpha:1.0]
//google

@interface FirstCell ()

@end

@implementation FirstCell

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        
#pragma mark - Image view initialization
        
        _photoImageView = [[UIImageView alloc]
                           initWithFrame:CGRectMake(
                                                    Indent,
                                                    Indent,
                                                    frame.size.height - Indent * 2,
                                                    frame.size.height - Indent * 2)];
        
        UITapGestureRecognizer *gestureRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(didPressImage:)];
        
        [_photoImageView addGestureRecognizer:gestureRecognizer];
        [_photoImageView setBackgroundColor:[UIColor blueColor]];
        [_photoImageView setUserInteractionEnabled:YES];
        [_photoImageView setClipsToBounds:YES];
        [_photoImageView setContentMode:UIViewContentModeScaleAspectFill];
        
        [self addSubview:_photoImageView];

#pragma mark - Label initialization

        _label = [[UILabel alloc]
                  initWithFrame:CGRectMake(
                                           100,
                                           frame.size.height / 2 - ButtonHeight / 2,
                                           300,
                                           30)];
        
        [self addSubview:_label];
        
#pragma mark - Button initialization
        
        _pushButton = [[UIButton alloc]
                       initWithFrame:CGRectMake(
                                                frame.size.width - _photoImageView.frame.size.width - Indent,
                                                frame.size.height - _photoImageView.frame.size.height - Indent,
                                                _photoImageView.frame.size.width,
                                                _photoImageView.frame.size.height)];
        
        [_pushButton setTitle:@"Info" forState:UIControlStateNormal];
        [_pushButton setTitleColor:StandartButtonColour forState:UIControlStateNormal];
        
        [_pushButton addTarget:self
                     action:@selector(didPressButton:)
           forControlEvents:UIControlEventTouchUpInside];
        
        [self addSubview:_pushButton];
    }
    
    return self;
}

#pragma mark - Action methods

- (void)didPressButton:(UIButton *)sender
{
    [self.delegate didPressButonOnCell:self];
}

- (void)didPressImage:(UIImage *)sender
{
    [self.delegate didPressOnCellImage:self];
}

#pragma mark - Other methods

- (void)setInfoWithProfile:(Profile *)profile
{
    self.photoImageView.image = profile.photo;
    self.label.text = profile.name;
    self.bioInfo = profile.bio;
}


@end
