//
//  SecondProfileCell.m
//  Lesson 8
//
//  Created by Vladas Zakrevskis on 04/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "SecondProfileCell.h"

@implementation SecondProfileCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        
        UIImageView *imageView = [[UIImageView alloc] initWithFrame:CGRectMake(5, 5, self.frame.size.height - 10, self.frame.size.height - 10)];
        
        [imageView setBackgroundColor:[UIColor orangeColor]];
        
        [self addSubview:imageView];
        
        UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(50, 10, 200, 50)];
        
        label.text = @"Label";
        
        [self addSubview:label];
        
        
        
    }
    
    return self;
}

@end
