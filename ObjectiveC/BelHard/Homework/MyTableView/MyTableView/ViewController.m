//
//  ViewController.m
//  MyTableView
//
//  Created by Vladas Zakrevskis on 04/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"
#import "FirstCell.h"
#import "SecondCell.h"
#import "Profile.h"
#import "InfoViewController.h"
#import "PhotoViewController.h"

const NSUInteger rowHeight = 75;
const NSUInteger sectionCount = 2;



@interface ViewController () <UITableViewDelegate, UITableViewDataSource, MyCellDelegate>

@property (nonatomic, weak) IBOutlet UITableView *tableView;

@property (nonatomic, strong) NSMutableArray *dataArray;

@property (nonatomic, strong) UIImage *testImage;

@property (nonatomic) BOOL isEditing;

@property (nonatomic, strong) InfoViewController *infoViewController;
@property (nonatomic, strong) PhotoViewController *photoViewController;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    UIBarButtonItem *editButton = [[UIBarButtonItem alloc] initWithTitle:@"Edit" style:UIBarButtonItemStylePlain target:self action:@selector(didPressEditBarButtonItem)];
    [self.navigationItem setRightBarButtonItem:editButton];
    
    self.dataArray = [NSMutableArray new];
    
    self.testImage = [UIImage imageNamed:@"Amanda Seyfried.jpg"];
    
    self.infoViewController = [self.storyboard instantiateViewControllerWithIdentifier:NSStringFromClass([InfoViewController class])];
    self.photoViewController = [self.storyboard instantiateViewControllerWithIdentifier:NSStringFromClass([PhotoViewController class])];
    
    
    [self dataLoading];

}


- (void)dataLoading
{
    NSString* pathToNamesList = [[NSBundle mainBundle] pathForResource:@"namesList"
                                                     ofType:@"txt"];
    
    NSString *namesList = [NSString stringWithContentsOfFile:pathToNamesList encoding:NSUTF8StringEncoding error:NULL];
    
    NSArray *namesArray = [namesList componentsSeparatedByString:@"\n#"];
    
    for (NSUInteger i = 0; i < sectionCount; i++) {
        
        static NSUInteger nameIndex = 0;
        
        NSMutableArray *sectionArray = [NSMutableArray new];
        
        for (NSUInteger j = 0; j < [namesArray count] / sectionCount; j++) {
            
        
            NSString *name =  [namesArray objectAtIndex:nameIndex];
            UIImage *photo = [UIImage imageNamed:[NSString stringWithFormat:@"%@.jpg", name]];
            NSString *pathToBio = [[NSBundle mainBundle] pathForResource:name ofType:@"txt"];
            NSString *bio = [NSString stringWithContentsOfFile:pathToBio encoding:NSUTF8StringEncoding error:NULL];
            
            Profile *profile = [[Profile alloc] initWithName:name photo:photo bio:bio];
            
            FirstCell *cell;
            
            if (i == 0) {
                cell = [[FirstCell alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, rowHeight)];
            } else {
                cell = [[SecondCell alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, rowHeight)];
            }
            
            [cell setInfoWithProfile:profile];
            [cell setDelegate:self];
            
            [sectionArray addObject:cell];
            
            nameIndex++;
        }
        
        [self.dataArray addObject:sectionArray];
    }
                           
  
}

- (void)didPressEditBarButtonItem
{
    if (self.isEditing) {
        [self.tableView setEditing:NO animated:YES];
        self.isEditing = NO;
    } else {
        [self.tableView setEditing:YES animated:YES];
        self.isEditing = YES;
    }
}

#pragma mark - MyCellDelegate implementation

- (void)didPressButonOnCell:(FirstCell *)sender
{
    
    
    self.infoViewController.photoImage = sender.photoImageView.image;
    self.infoViewController.nameString = sender.label.text;
    self.infoViewController.bioString = sender.bioInfo;
    
    [self.navigationController pushViewController:self.infoViewController animated:YES];
    
}

- (void)didPressOnCellImage:(FirstCell *)sender
{
    
    
    self.photoViewController.photoImage = sender.photoImageView.image;
    
    [self.navigationController pushViewController:self.photoViewController animated:YES];
}

#pragma mark - Table properties

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return rowHeight;
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.dataArray[section] count];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return [self.dataArray count];
}


#pragma mark - Table settings

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    return YES;
}

- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    return YES;
}

- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath *)destinationIndexPath
{
    id temp = self.dataArray[sourceIndexPath.section][sourceIndexPath.row];

    [self.dataArray[sourceIndexPath.section] removeObject:temp];
        
    [self.dataArray[destinationIndexPath.section] insertObject:temp atIndex:destinationIndexPath.row];

    
    [self.tableView reloadData];
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    [self.dataArray[indexPath.section] removeObjectAtIndex:indexPath.row];
    
    [self.tableView reloadData];
}



#pragma mark - Cell for row at index path

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    FirstCell *cell;
    
    if ([self.dataArray[indexPath.section][indexPath.row] isKindOfClass:[FirstCell class]]) {
        cell = self.dataArray[indexPath.section][indexPath.row];
    }
    
    return cell;
}




@end
