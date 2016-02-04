//
//  FirstCell.m
//  MyTableView
//
//  Created by Vladas Zakrevskis on 04/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "FirstCell.h"

@interface FirstCell ()

@end

@implementation FirstCell

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        
        _image = [[UIImageView alloc] initWithFrame:CGRectMake(10, 10, frame.size.height - 20, frame.size.height - 20)];
        
        NSLog(@"%f", self.frame.size.height);
        
        [_image setBackgroundColor:[UIColor blueColor]];
        
        [self addSubview:_image];
    }
    
    return self;
}


@end
