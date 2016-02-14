//
//  VZStudent.m
//  CoreDataLesson1
//
//  Created by Vladas Zakrevskis on 14/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "VZStudent.h"

@implementation VZStudent

- (void)setName:(NSString *)name
{
    _name = name;
    
    NSLog(@"student setName %@", name);
}

- (void)setAge:(NSUInteger)age
{
    _age = age;
    
    NSLog(@"student setAge %lu", (unsigned long)age);
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"%@, %lu", self.name, self.age];
}

- (void)setValue:(id)value forKey:(NSString *)key
{
    NSLog(@"setValue:%@ forKey:%@", value, key);
    
    [super setValue:value forKey:key];
}

@end
