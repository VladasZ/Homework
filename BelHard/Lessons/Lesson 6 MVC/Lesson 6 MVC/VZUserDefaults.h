//
//  VZUserDefaults.h
//  Lesson 6 MVC
//
//  Created by Vladas Zakrevskis on 26/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const VZUserDefaultsFirstName;
//extern NSString * const VZUserDefaultsSecondName;
extern NSString * const VZUserDefaultsLastName;
//extern NSString * const VZUserDefaultsAge;
extern NSString * const VZUserDefaultsCity;
extern NSString * const VZUserDefaultsName;
extern NSString * const VZUserDefaultsAge;


@interface VZUserDefaults : NSObject

- (void)setObject:(id)object key:(NSString *)key;

- (id)getObjectForKey:(NSString *)key;

@end
