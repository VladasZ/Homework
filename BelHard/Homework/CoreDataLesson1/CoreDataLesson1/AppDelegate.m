//
//  AppDelegate.m
//  CoreDataLesson1
//
//  Created by Vladas Zakrevskis on 14/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "AppDelegate.h"
#import "VZStudent.h"
#import "VZGroup.h"

@interface AppDelegate ()

//@property (nonatomic, strong) VZStudent *student;
@property (nonatomic, strong) VZGroup *group;
@property (nonatomic, strong) VZGroup *group2;

@property (nonatomic, strong) NSArray *groups;


@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
   
    /*self.student = [[VZStudent alloc] init];
    
    [self.student addObserver:self
                   forKeyPath:@"name"
                      options:NSKeyValueObservingOptionNew
                      context:nil];
    
    self.student.name = @"Alex";
    self.student.age = 23;
    
    [self.student setValue:@"Peter" forKey:@"name"];
    [self.student setValue:@25 forKey:@"age"];
    
    NSLog(@"%@", [self.student description]);*/
    
    self.group = [[VZGroup alloc] init];
    self.group2 = [[VZGroup alloc] init];
    
    self.group.students =
    [NSArray arrayWithObjects:
     [VZStudent studentWithName:@"Kolja" age:20],
     [VZStudent studentWithName:@"Petja" age:24],
     [VZStudent studentWithName:@"Vasia" age:22],
     [VZStudent studentWithName:@"Dasha" age:27],
     [VZStudent studentWithName:@"Masha" age:19],
     [VZStudent studentWithName:@"Sasha" age:20],
                                            nil];
    
    
    self.group2.students = @[
    [VZStudent studentWithName:@"Kukarina" age:12],
    [VZStudent studentWithName:@"Vasilisa" age:32],
    [VZStudent studentWithName:@"Krel"     age:21],
    [VZStudent studentWithName:@"Pistrun"  age:54],
    [VZStudent studentWithName:@"Mda"      age:65],
    [VZStudent studentWithName:@"Kulik"    age:34]];
    
    self.groups = @[self.group, self.group2];

    
    NSLog(@"maxAge - %@", [self.groups valueForKeyPath:@"@unionOfArrays.students"]);

    for (VZStudent *student in self.group2.students) {
        NSLog(@"%@", student);
    }
    
    NSMutableArray *array = self.group.students.mutableCopy;
    
    NSString *value = @"bla";
    
    if (![[self.group.students lastObject] validateValue:&value forKey:@"name" error:nil])
    {
        NSLog(@"bla");
    }
    
    
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
    //[self.student removeObserver:self  forKeyPath:@"name"];
}



@end
