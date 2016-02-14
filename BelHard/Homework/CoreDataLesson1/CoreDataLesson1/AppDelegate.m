//
//  AppDelegate.m
//  CoreDataLesson1
//
//  Created by Vladas Zakrevskis on 14/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "AppDelegate.h"
#import "VZStudent.h"

@interface AppDelegate ()

@property (nonatomic, strong) VZStudent *student;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
   
    self.student = [[VZStudent alloc] init];
    
    [self.student addObserver:self
                   forKeyPath:@"name"
                      options:NSKeyValueObservingOptionNew
                      context:nil];
    
    self.student.name = @"Alex";
    self.student.age = 23;
    
    [self.student setValue:@"Peter" forKey:@"name"];
    [self.student setValue:@25 forKey:@"age"];
    
    NSLog(@"%@", [self.student description]);
    
    return YES;
}

- (void)observeValueForKeyPath:(NSString *)keyPath
                      ofObject:(id)object
                        change:(NSDictionary<NSString *,id> *)change
                       context:(void *)context
{
    NSLog(@"observer %@", [object valueForKey:keyPath]);
}

- (void)dealloc
{
    [self.student removeObserver:self  forKeyPath:@"name"];
}

@end
