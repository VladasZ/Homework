//
//  DataManager.m
//  Lesson10CoreData
//
//  Created by Vladas Zakrevskis on 18/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "DataManager.h"
#import "MUser.h"
#import "MCar.h"
#import "CoreDataManager.h"

NSString * const IsDataInDatabase = @"IsDataInDatabase";

@interface DataManager ()

@property (nonatomic, strong) NSString *privateName;

@end


@implementation DataManager

- (void)addDataToDatabase
{
    self.privateName = @"blafldfla";
    
    if ([[NSUserDefaults standardUserDefaults] boolForKey:IsDataInDatabase] == NO) {
        
        [[NSUserDefaults standardUserDefaults]setBool:YES forKey:IsDataInDatabase];
        
        
        MUser *userOne = [self createUserNamed:@"Peter"
                                        height:@180
                                           age:@18
                                      selected:@YES
                                     birthDate:[NSDate date]
                                        avatar:@"1.png"];
        
        if (userOne) {
            
            [self createCarNamed:@"BMW"
                           color:[UIColor blackColor]
                          number:@1111
                            year:[NSDate date]
                    assignToUser:userOne];
            
            [self createCarNamed:@"Audi"
                           color:[UIColor blackColor]
                          number:@1112
                            year:[NSDate date]
                    assignToUser:userOne];
            
            [self createCarNamed:@"Mersedes"
                           color:[UIColor blackColor]
                          number:@1113
                            year:[NSDate date]
                    assignToUser:userOne];
        }
        
        
        
        
        
        MUser *userTwo = [self createUserNamed:@"Pavel"
                                        height:@181
                                           age:@16
                                      selected:@YES
                                     birthDate:[NSDate date]
                                        avatar:@"1.png"];
        
        [self createCarNamed:@"Lamborgini"
                       color:[UIColor yellowColor]
                      number:@2221
                        year:[NSDate date]
                assignToUser:userTwo];
        
        [self createCarNamed:@"Ferrari"
                       color:[UIColor redColor]
                      number:@2222
                        year:[NSDate date]
                assignToUser:userTwo];
        
        [self createCarNamed:@"BMW"
                       color:[UIColor brownColor]
                      number:@2223
                        year:[NSDate date]
                assignToUser:userTwo];
        
        MUser *userThree = [self createUserNamed:@"Marina"
                                        height:@170
                                           age:@22
                                      selected:@YES
                                     birthDate:[NSDate date]
                                        avatar:@"1.png"];
        
        [self createCarNamed:@"Kia"
                       color:[UIColor yellowColor]
                      number:@3331
                        year:[NSDate date]
                assignToUser:userThree];
        
        [self createCarNamed:@"VW"
                       color:[UIColor redColor]
                      number:@3332
                        year:[NSDate date]
                assignToUser:userThree];
        
        [self createCarNamed:@"Marka"
                       color:[UIColor brownColor]
                      number:@3333
                        year:[NSDate date]
                assignToUser:userThree];
        
        MUser *userFour = [self createUserNamed:@"Kate"
                                          height:@165
                                             age:@24
                                        selected:@YES
                                       birthDate:[NSDate date]
                                          avatar:@"1.png"];
        
        [self createCarNamed:@"Oka"
                       color:[UIColor yellowColor]
                      number:@4441
                        year:[NSDate date]
                assignToUser:userFour];
        
        [self createCarNamed:@"Jiga"
                       color:[UIColor redColor]
                      number:@4442
                        year:[NSDate date]
                assignToUser:userFour];
        
        [self createCarNamed:@"Zaporojec"
                       color:[UIColor brownColor]
                      number:@4443
                        year:[NSDate date]
                assignToUser:userFour];
        
        MUser *userFive = [self createUserNamed:@"Roberto"
                                         height:@165
                                            age:@24
                                       selected:@YES
                                      birthDate:[NSDate date]
                                         avatar:@"1.png"];
        
        [self createCarNamed:@"Traktor"
                       color:[UIColor yellowColor]
                      number:@5551
                        year:[NSDate date]
                assignToUser:userFive];
        
        [self createCarNamed:@"Velosiped"
                       color:[UIColor redColor]
                      number:@5552
                        year:[NSDate date]
                assignToUser:userFive];
        
        [self createCarNamed:@"Opel"
                       color:[UIColor brownColor]
                      number:@5553
                        year:[NSDate date]
                assignToUser:userFive];
        
        [[CoreDataManager sharedManager] saveContext];
        
        
    }
    
    
    
}

- (MUser *)createUserNamed:(NSString *)name
                    height:(NSNumber *)height
                       age:(NSNumber *)age
                  selected:(NSNumber *)selected
                 birthDate:(NSDate *)birthDate
                    avatar:(NSString *)avatarImageName
{
    
    NSManagedObjectContext *context = [[CoreDataManager sharedManager] managedObjectContext];

    MUser *newUser = [NSEntityDescription insertNewObjectForEntityForName:NSStringFromClass([MUser class]) inManagedObjectContext:context];
    
    if (newUser != nil) {
        
        newUser.mobName =       name;
        newUser.mobHeight =     height;
        newUser.mobAge =        age;
        newUser.mobSelected =   selected;
        newUser.mobBirthDate =  birthDate;
        newUser.mobAvatar =     UIImagePNGRepresentation([UIImage imageNamed:avatarImageName]);
    
    }

    return newUser;
}


- (MCar *)createCarNamed:(NSString *)mobName
                   color:(UIColor *)mobColor
                  number:(NSNumber *)mobNumber
                    year:(NSDate *)mobYear
                    assignToUser:(MUser *)user
{
    
    NSManagedObjectContext *context = [[CoreDataManager sharedManager] managedObjectContext];
    
    MCar *newCar = [NSEntityDescription insertNewObjectForEntityForName:NSStringFromClass([MCar class]) inManagedObjectContext:context];
    
    if (newCar != nil) {
        newCar.mobName = mobName;
        newCar.mobColor = mobColor;
        newCar.mobNumber = mobNumber;
        newCar.mobYear = mobYear;
        newCar.rlsUser = user;
    }
    
    [user addRlsCarsObject:newCar];
    
    return newCar;
}


@end
