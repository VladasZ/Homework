//
//  VZUserDefaults.m
//  Lesson 6 MVC
//
//  Created by Vladas Zakrevskis on 26/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "VZUserDefaults.h"

NSString * const VZUserDefaultsFirstName = @"FirstName";
//NSString * const VZUsDefaultsSecondName = @"SecondName";
NSString * const VZUserDefaultsLastName = @"LastName";
//NSString * const VZUserDefaultsAge = @"Age";
NSString * const VZUserDefaultsCity = @"City";

NSString * const VZUserDefaultsName = @"SecondName";
NSString * const VZUserDefaultsAge = @"Age";


@implementation VZUserDefaults


- (void)setObject:(id)object key:(NSString *)key
{
    [[NSUserDefaults standardUserDefaults] setObject:object forKey:key];
    
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (id)getObjectForKey:(NSString *)key
{
    return [[NSUserDefaults standardUserDefaults] objectForKey:key];
}


@end
