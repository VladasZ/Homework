//
//  VZAnnotation.m
//  Lesson9
//
//  Created by Vladas Zakrevskis on 09/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "VZAnnotation.h"

@implementation VZAnnotation

- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate title:(NSString *)title subTitle:(NSString *)subTitle
{
    if (self = [super init]) {
        _coordinate = coordinate;
        _title = title;
        _subtitle = subTitle;
    }
    return self;
}

@end
