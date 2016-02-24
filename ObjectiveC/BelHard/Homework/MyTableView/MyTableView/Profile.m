//
//  Profile.m
//  MyTableView
//
//  Created by Vladas Zakrevskis on 07/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "Profile.h"

@implementation Profile

- (instancetype)initWithName:(NSString *)name photo:(UIImage *)photo bio:(NSString *)bio
{
    self = [super init];
    if (self) {
        _name = name;
        _photo = photo;
        _bio = bio;
    }
    return self;
}



@end
