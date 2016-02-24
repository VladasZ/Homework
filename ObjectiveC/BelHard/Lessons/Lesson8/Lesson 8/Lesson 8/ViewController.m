//
//  ViewController.m
//  Lesson 8
//
//  Created by Vladas Zakrevskis on 02/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"
#import "ProfileCell.h"
#import "SecondProfileCell.h"

#define GENERATE_RANDOM_COLOR CGFloat hue = (arc4random() % 256 / 256.0);\
CGFloat saturation = (arc4random() % 128 / 256.0) + 0.5;\
CGFloat brightness = (arc4random() % 128 / 256.0) + 0.5;\
UIColor *color = [UIColor colorWithHue:hue saturation:saturation brightness:brightness alpha:1];

@interface ViewController () <UITableViewDelegate, UITableViewDataSource, ProfileCellDelegate>

@property (nonatomic, weak) IBOutlet UITableView *tableView;

@property (nonatomic, strong) NSArray *dataArray;

@property (nonatomic) BOOL isEditing;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    UIBarButtonItem *editButton = [[UIBarButtonItem alloc] initWithTitle:@"Edit" style:UIBarButtonItemStylePlain target:self action:@selector(didPressEditBarButtonItem)];
    
    [self.navigationItem setRightBarButtonItem:editButton];
    
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

- (NSArray *)dataArray
{
    if (_dataArray == nil) {
        _dataArray = [NSArray arrayWithObjects:
                      @"Kolja", @"Vasia", @"Petja", @"Masha", @"Dasha", nil];
    }
    
    return _dataArray;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 75;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 50;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    return 0;
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.dataArray.count;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    //return indexPath.row == 0 ? NO : YES;
    return YES;
}

- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    return YES;
}

- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath *)destinationIndexPath
{
    id sourceObject = [self.dataArray objectAtIndex:sourceIndexPath.row];
    id destinationObject = [self.dataArray objectAtIndex:destinationIndexPath.row];
    
    NSMutableArray *tempArray = self.dataArray.mutableCopy;
    
    [tempArray replaceObjectAtIndex:sourceIndexPath.row withObject:destinationObject];
    [tempArray replaceObjectAtIndex:destinationIndexPath.row withObject:sourceObject];
    
    self.dataArray = tempArray.copy;
    
   // ![tableView reloadData];
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        
        NSMutableArray *tempArray = self.dataArray.mutableCopy;
        
        [tempArray removeObjectAtIndex:indexPath.row];
        
        self.dataArray = tempArray.copy;
        [tableView reloadData];
    }
}

-(void)didPressButtonOnCell:(ProfileCell *)cell
{
    NSLog(@"didPressButtonOnCell %@", cell.firstNameLabel.text);
    
    NSIndexPath *indexPath = [self.tableView indexPathForCell:cell];
    
    NSLog(@"%@", indexPath);
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *cellID = @"cell";
    
    SecondProfileCell *cell = [tableView dequeueReusableCellWithIdentifier:@"qwe"];
    
    if (cell == nil) {
        cell = [[SecondProfileCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"SecondProfileCell"];
    }
    
    //cell.delegate = self;
    //cell.firstNameLabel.text = [self.dataArray objectAtIndex:indexPath.row];
    
    return cell;
}



@end
