//
//  ViewController.m
//  Lesson10CoreData
//
//  Created by Vladas Zakrevskis on 16/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"
#import "NSString+CheckEmail.h"
#import "MUser.h"
#import "CoreDataManager.h"
#import "MCar.h"

@interface ViewController () <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) NSMutableArray *usersArray;

@property (nonatomic, strong) NSManagedObjectContext *contex;

@property (nonatomic, weak) IBOutlet UITableView *tableView;

- (IBAction)didPressAddUserButton:(UIButton *)sender;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    
    [self getUserFromDatabase];

    
}

#pragma mark - Table view properties

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return self.usersArray.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;
{
    MUser *user = [self.usersArray objectAtIndex:section];
    
    return user.rlsCars.count;
}

- (nullable NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    MUser *user = [self.usersArray objectAtIndex:section];
    
    return user.mobName;
}


- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        
        MUser *user = [self.usersArray objectAtIndex:indexPath.section];
        MCar *car = (MCar *)[user.rlsCars.allObjects objectAtIndex:indexPath.row];
        
        [[[CoreDataManager sharedManager] managedObjectContext] deleteObject:car];
        
        [user removeRlsCarsObject:car];
        
        if (user.rlsCars.count == 0) {
            
            [[[CoreDataManager sharedManager] managedObjectContext] deleteObject:user];
            
        }
        
        [self getUserFromDatabase];

    }
}



- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    UITableViewCell *cell = [[UITableViewCell alloc] init];
    
    MUser *user = [self.usersArray objectAtIndex:indexPath.section];
    MCar *car = (MCar *)[user.rlsCars.allObjects objectAtIndex:indexPath.row];
    
    //cell.textLabel.text = [NSString stringWithFormat:@"Name - %@", user.mobName];
    cell.textLabel.text = [NSString stringWithFormat:@"Car - %@", car.mobName];
    cell.detailTextLabel.text = [NSString stringWithFormat:@"Number - %@", car.mobNumber];
    cell.imageView.image = [UIImage imageWithData:user.mobAvatar];
    
    return cell;
}

- (void)getUserFromDatabase
{
    NSFetchRequest *fetchRequest =
    [[NSFetchRequest alloc] initWithEntityName:NSStringFromClass([MUser class])];
    
    NSError *error = nil;
    
    NSArray *array =
    [self.contex executeFetchRequest:fetchRequest error:&error];
    
    if (error == nil) {
        self.usersArray = array.mutableCopy;
        [self.tableView reloadData];
    }

    
}

#pragma mark - Actions

- (void)didPressAddUserButton:(UIButton *)sender
{
    self.contex = [[CoreDataManager sharedManager] managedObjectContext];
    
    MUser *newUser = [NSEntityDescription insertNewObjectForEntityForName:NSStringFromClass([MUser class]) inManagedObjectContext:self.contex];

    
    
    if (newUser != nil) {
        
        newUser.mobName =       @"Peter";
        newUser.mobHeight =     @189.7;
        newUser.mobAge =        @35;
        newUser.mobSelected =   @NO;
        newUser.mobBirthDate =  [NSDate date];
        newUser.mobAvatar =     UIImagePNGRepresentation([UIImage imageNamed:@"1.png"]);
        
        MCar *carOne = [NSEntityDescription insertNewObjectForEntityForName:NSStringFromClass([MCar class]) inManagedObjectContext:self.contex];
        
        if (carOne != nil) {
            carOne.mobName = @"BMW";
            carOne.mobColor = [UIColor blackColor];
            carOne.mobNumber = @1234;
            carOne.mobYear = [NSDate date];
            
            carOne.rlsUser = newUser;

        }
        
        
        MCar *carTwo = [NSEntityDescription insertNewObjectForEntityForName:NSStringFromClass([MCar class]) inManagedObjectContext:self.contex];
        
        if (carTwo != nil) {
            carTwo.mobName = @"Audi";
            carTwo.mobColor = [UIColor whiteColor];
            carTwo.mobNumber = @4321;
            carTwo.mobYear = [NSDate date];
            
            carTwo.rlsUser = newUser;
        }
        
        [newUser addRlsCarsObject:carOne];
        [newUser addRlsCarsObject:carTwo];
        
    
        [[CoreDataManager sharedManager] saveContext];
    }
    
    [self getUserFromDatabase];
}

@end
