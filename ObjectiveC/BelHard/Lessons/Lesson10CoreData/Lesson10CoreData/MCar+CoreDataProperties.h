//
//  MCar+CoreDataProperties.h
//  Lesson10CoreData
//
//  Created by Vladas Zakrevskis on 18/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "MCar.h"

NS_ASSUME_NONNULL_BEGIN

@interface MCar (CoreDataProperties)

@property (nullable, nonatomic, retain) id mobColor;
@property (nullable, nonatomic, retain) NSString *mobName;
@property (nullable, nonatomic, retain) NSNumber *mobNumber;
@property (nullable, nonatomic, retain) NSDate *mobYear;
@property (nullable, nonatomic, retain) MUser *rlsUser;

@end

NS_ASSUME_NONNULL_END
