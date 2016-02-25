//
//  VZStudent+CoreDataProperties.h
//  CoreDataLesson2
//
//  Created by Vladas Zakrevskis on 18/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "VZStudent.h"

NS_ASSUME_NONNULL_BEGIN

@interface VZStudent (CoreDataProperties)

@property (nullable, nonatomic, retain) NSDate *dateOfBirth;
@property (nullable, nonatomic, retain) NSString *firstName;
@property (nullable, nonatomic, retain) NSString *lastName;
@property (nullable, nonatomic, retain) NSNumber *score;

@end

NS_ASSUME_NONNULL_END
