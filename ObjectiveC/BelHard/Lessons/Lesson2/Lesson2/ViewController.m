//
//  ViewController.m
//  Lesson2
//
//  Created by Vladas Zakrevskis on 12/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"


@interface ViewController ()
//private
@property (nonatomic, strong) NSArray *array;
@property (nonatomic, strong) NSMutableArray *mutableArray;

@property (nonatomic, strong) NSDictionary *dictionary;
@property (nonatomic, strong) NSMutableDictionary *mutableDictionary;

@property (nonatomic, strong) NSSet *set;
@property (nonatomic, strong) NSMutableSet *mutableSet;




@end

@implementation ViewController

- (NSArray *) array // lazy loading
{
    if (_array == nil) {
        _array = [[NSArray alloc] initWithObjects:@"bla1", @"bla2", nil];
    }
    return _array;
}

#pragma mark - NSArray
/*
 //    self.array = [[NSArray alloc] init];
 //    self.array = [NSArray array];
 //    self.array = [[NSArray alloc] initWithObjects:@"bla", @"bla2", nil];
 //    self.array = [NSArray arrayWithObjects:@"bla3", @"bla4", nil];
 
 // NSLog(@"%@", self.array);
 
 NSString *firstObject = [self.array objectAtIndex:0];
 //firstObject = [self.array firstObject];
 
 NSLog(@"firstObject - %@", firstObject);
*/

#pragma mark - NSMutableArray
/*NSString *string = @"bla";
 self.mutableArray = [NSMutableArray array];
 
 [self.mutableArray addObject:string];
 [self.mutableArray addObject:string];
 [self.mutableArray addObject:string];
 
 
 NSLog(@"%@", self.mutableArray);
 
 // [self.mutableArray removeObjectAtIndex:0];
 [self.mutableArray removeObject:string];
 
 
 NSLog(@"%@", self.mutableArray);*/

#pragma mark - NSDictionary
/*
 self.dictionary = [NSDictionary dictionary];
 self.dictionary =
 [NSDictionary dictionaryWithObjectsAndKeys:
 @5, @"numberFive",
 @6, @"numberSix",
 nil];
 
 //    NSLog(@"%@", self.dictionary);
 //    NSLog(@"%@", [self.dictionary allKeys]);
 //    NSLog(@"%@", [self.dictionary allValues]);
 
 for (NSString *key in [self.dictionary allKeys]) {
 
 if ([key isKindOfClass:[NSString class]]) {
 
 NSLog(@"%@", key);
 NSLog(@"%@", [self.dictionary objectForKey:key]) ;
 
 }
 
 }
*/
#pragma mark - NSMutableDictionary
/*
 self.mutableDictionary = [NSMutableDictionary dictionary];
 
 [self.mutableDictionary setObject:@5 forKey:@"numberFive"];
 [self.mutableDictionary setObject:@6 forKey:@"numberSix"];
 
 [self.mutableDictionary removeObjectForKey:@"numberFive"];
 
 
 NSLog(@"%@", self.mutableDictionary);
 */
- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.set = [NSSet set];
    self.mutableSet = [NSMutableSet set];
    
    [self.mutableSet addObject:@"bla"];
    [self.mutableSet addObject:@"bla"];
    [self.mutableSet addObject:@"bla1"];
    [self.mutableSet addObject:@"bla"];

    NSLog(@"%@", self.mutableSet);
    
    NSCountedSet *countedSet = [NSCountedSet set];
    
    [countedSet addObject:@"bla"];
    [countedSet addObject:@"bla"];
    [countedSet addObject:@"bla1"];
    [countedSet addObject:@"bla"];
    
    NSLog(@"%@", countedSet);
    //(bla [3], bla1 [1])
    
    self.dictionary = @{@4:@"numberFour", @7:@"numberSeven"};
    
    self.mutableDictionary = @{@4:@"numberFour", @7:@"numberSeven"}.mutableCopy;
    
    self.array = @[@"bla1", @"bla2"];
    
    self.mutableArray = self.array.mutableCopy;
    
    NSLog(@"%@", self.mutableDictionary);
    
}


@end
