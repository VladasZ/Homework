//
//  ProfileCell.m
//  Lesson 8
//
//  Created by Vladas Zakrevskis on 04/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ProfileCell.h"

@implementation ProfileCell

- (void)prepareForReuse
{
    [super prepareForReuse];
    
    self.firstNameLabel.text = @"";
    self.secondNameLabel.text = @"";
    self.icon.image = nil;
}

- (IBAction)didPressActionButton:(UIButton *)sender{
        
    if ([self.delegate respondsToSelector:@selector(didPressButtonOnCell:)]) {
        [self.delegate didPressButtonOnCell:self];
    }
    
}

@end
