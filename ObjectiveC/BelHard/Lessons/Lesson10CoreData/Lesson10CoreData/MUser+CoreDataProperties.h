//
//  MUser+CoreDataProperties.h
//  Lesson10CoreData
//
//  Created by Vladas Zakrevskis on 16/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "MUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface MUser (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *mobName;
@property (nullable, nonatomic, retain) NSNumber *mobAge;
@property (nullable, nonatomic, retain) NSDate *mobBirthDate;
@property (nullable, nonatomic, retain) NSNumber *mobHeight;
@property (nullable, nonatomic, retain) NSNumber *mobSelected;
@property (nullable, nonatomic, retain) NSData *mobAvatar;
@property (nullable, nonatomic, retain) NSSet<NSManagedObject *> *rlsCars;

@end

@interface MUser (CoreDataGeneratedAccessors)

- (void)addRlsCarsObject:(NSManagedObject *)value;
- (void)removeRlsCarsObject:(NSManagedObject *)value;
- (void)addRlsCars:(NSSet<NSManagedObject *> *)values;
- (void)removeRlsCars:(NSSet<NSManagedObject *> *)values;

@end

NS_ASSUME_NONNULL_END
