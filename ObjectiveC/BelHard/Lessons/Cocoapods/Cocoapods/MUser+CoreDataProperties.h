//
//  MUser+CoreDataProperties.h
//  Cocoapods
//
//  Created by Vladas Zakrevskis on 23/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "MUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface MUser (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *mobFirstName;
@property (nullable, nonatomic, retain) NSString *mobLastName;
@property (nullable, nonatomic, retain) NSString *mobID;

@end

NS_ASSUME_NONNULL_END
