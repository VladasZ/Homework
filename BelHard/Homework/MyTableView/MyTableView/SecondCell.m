//
//  SecondCell.m
//  MyTableView
//
//  Created by Vladas Zakrevskis on 07/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "SecondCell.h"

@implementation SecondCell

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        CGRect tempFrame = self.pushButton.frame;
        self.pushButton.frame = self.photoImageView.frame;
        self.photoImageView.frame = tempFrame;
    }
    return self;
}

@end
