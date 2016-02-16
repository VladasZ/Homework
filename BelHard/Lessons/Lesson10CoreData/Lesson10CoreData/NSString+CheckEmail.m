//
//  NSString+CheckEmail.m
//  Lesson10CoreData
//
//  Created by Vladas Zakrevskis on 16/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "NSString+CheckEmail.h"

@implementation NSString (CheckEmail)

- (BOOL)checkString
{
    return self.length > 0 ? YES : NO;
}

@end
