//
//  VZStudent.m
//  CoreDataLesson1
//
//  Created by Vladas Zakrevskis on 14/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "VZStudent.h"

@implementation VZStudent

+ (instancetype)studentWithName:(NSString *)name
                            age:(NSUInteger)age
{
    return [[VZStudent alloc] initWintName:name age:age];
}

- (instancetype)initWintName:(NSString *)name
                         age:(NSUInteger)age
{
    self = [super init];
    if (self) {
        _name = name;
        _age = age;
    }
    return self;
}

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

- (BOOL)validateName:(inout id  _Nullable __autoreleasing *)ioValue error:(out NSError * _Nullable __autoreleasing *)outError
{
    
    NSLog(@"Validate name");
    
    return NO;
}


@end
