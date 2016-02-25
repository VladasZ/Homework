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
#import "DataManager.h"

@interface ViewController ()
<UITableViewDelegate,
UITableViewDataSource,
NSFetchedResultsControllerDelegate>

@property (nonatomic, strong) NSMutableArray *usersArray;

@property (nonatomic, strong) NSManagedObjectContext *contex;

@property (nonatomic, weak) IBOutlet UITableView *tableView;

@property (nonatomic, strong) NSFetchedResultsController *fetchedResultController;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    
    self.contex = [[CoreDataManager sharedManager] managedObjectContext];
    
    DataManager *dataManager = [[DataManager alloc] init];
    
    [dataManager addDataToDatabase];
   
    //[self getUsersFromDatabaseWithFetchedResultsController];
    
    [self getUsersFromDatabase];
    
    NSLog(@"%@", [dataManager valueForKey:@"privateName"]);
    
    [dataManager setValue:@"NEW BLA" forKey:@"privateName"];
    
    NSLog(@"%@", [dataManager valueForKey:@"privateName"]);
    
}
 
#pragma mark - Table view properties

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return self.usersArray.count;
  //  return [self.fetchedResultController sections].count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;
{
    MUser *user = [self.usersArray objectAtIndex:section];
    
    return user.rlsCars.count;
    
    //id<NSFetchedResultsSectionInfo> sectionInfo =
   // [self.fetchedResultController.sections objectAtIndex:section];
    
    //return [sectionInfo numberOfObjects];
    
}

- (nullable NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    MUser *user = [self.usersArray objectAtIndex:section];
    
    return [NSString stringWithFormat:@"%@, age - %@", user.mobName, user.mobAge];
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
        
        
        [self getUsersFromDatabase];

    }
}



- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    UITableViewCell *cell = [[UITableViewCell alloc] init];
    
    MUser *user = [self.usersArray objectAtIndex:indexPath.section];
    MCar *car = (MCar *)[user.rlsCars.allObjects objectAtIndex:indexPath.row];
    
    //cell.textLabel.text = [NSString stringWithFormat:@"Name - %@", user.mobName];
    cell.textLabel.text = [car valueForKey:@"mobName"];
    cell.detailTextLabel.text = [NSString stringWithFormat:@"Number - %@", car.mobNumber];
    cell.imageView.image = [UIImage imageWithData:user.mobAvatar];
    
    //MUser *user = [self.fetchedResultController objectAtIndexPath:indexPath];
    
   // cell.textLabel.text = user.mobName;
    //cell.imageView.image = [UIImage imageWithData:user.mobAvatar];
    
    return cell;
}

- (void)getUsersFromDatabase
{
    NSFetchRequest *fetchRequest =
    [[NSFetchRequest alloc] initWithEntityName:NSStringFromClass([MCar class])];
    
    
//    NSPredicate *predicate =
//    [NSPredicate predicateWithFormat:
//     @"mobAge == %@ OR mobAge == %@", @"Roberto", @"Marina"];
    
//    NSPredicate *predicate =
//    [NSPredicate predicateWithFormat:
//     @"mobAge > %@ AND mobAge < %@", @20, @30];
    
    
    
    NSPredicate *predicate =
    [NSPredicate predicateWithFormat:
     @"mobName == %@", @"BMW"];
    
    [fetchRequest setPredicate:predicate];
    
    NSError *error = nil;
    
    NSArray *array =
    [self.contex executeFetchRequest:fetchRequest error:&error];
    
    if (error == nil) {
        
        NSMutableSet *tempSet = [NSMutableSet set];
        
        for (MCar *car in array) {
            [tempSet addObject:car.rlsUser];
        }
        
        self.usersArray = tempSet.allObjects.mutableCopy;
        [self.tableView reloadData];
    }

    
}

- (void)getUsersFromDatabaseWithFetchedResultsController
{
    
    NSFetchRequest *fetchRequest = [[NSFetchRequest alloc] init];
    
    NSEntityDescription *entityDescription =
    [NSEntityDescription entityForName:NSStringFromClass([MUser class])
                inManagedObjectContext:self.contex];
    
    [fetchRequest setEntity:entityDescription];
    
    NSSortDescriptor *nameDiscriptor =
    [[NSSortDescriptor alloc] initWithKey:@"mobName"ascending:YES];
    
    [fetchRequest setSortDescriptors:@[nameDiscriptor]];
    
    self.fetchedResultController =
    [[NSFetchedResultsController alloc] initWithFetchRequest:fetchRequest
                                        managedObjectContext:self.contex
                                          sectionNameKeyPath:nil cacheName:nil];
    
    self.fetchedResultController.delegate = self;
    
    NSError *error = nil;
    
    if ([self.fetchedResultController performFetch:&error]) {
        
        [self.tableView reloadData];
        
    } else {
        
        NSLog(@"%@", error);
        
    }
  
}


#pragma mark - Actions

- (void)didPressAddUserButton:(UIButton *)sender
{
    
    
    [self getUsersFromDatabase];
}

@end
