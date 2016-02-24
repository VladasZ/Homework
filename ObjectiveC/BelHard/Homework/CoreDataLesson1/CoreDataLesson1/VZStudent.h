//
//  VZStudent.h
//  CoreDataLesson1
//
//  Created by Vladas Zakrevskis on 14/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VZStudent : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic) NSUInteger age;

+ (instancetype)studentWithName:(NSString *)name
                            age:(NSUInteger)age;

- (instancetype)initWintName:(NSString *)name
                         age:(NSUInteger)age;

@end
