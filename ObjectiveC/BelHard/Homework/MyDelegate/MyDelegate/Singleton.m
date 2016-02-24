//
//  Singleton.m
//  MyDelegate
//
//  Created by Vladas Zakrevskis on 02/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "Singleton.h"

@implementation Singleton

+ (instancetype)sharedManager
{
    static Singleton *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[Singleton alloc] init];
        // Do any other initialisation stuff here
    });
    return sharedInstance;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.textString = [[NSString alloc] init];
    }
    return self;
}

@end
