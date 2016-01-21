//
//  MasterViewController.m
//  Lesson5
//
//  Created by Vladas Zakrevskis on 21/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "MasterViewController.h"
#import "DetailViewController.h"

@interface MasterViewController () <DetailViewControllerDelegate>


@end

@implementation MasterViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

#pragma mark - DetailViewControllerDelegate

- (void)detailViewController:(DetailViewController *)detailViewController didPresButtonWithText:(NSString *)text
{
    self.label.text = text;
    self.secondLabel.text = text;
    self.thirdLabel.text = text;

    detailViewController.labelText = self.labelText;
}


- (IBAction)didPressButton:(UIButton *)sender
{
    
    DetailViewController *controller = [self.storyboard instantiateViewControllerWithIdentifier:NSStringFromClass([DetailViewController class])];
    
    controller.delegate = self;
    
    [self.navigationController pushViewController:controller animated:YES];
    
    
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:YES];
    
    self.label.text = self.labelText;
}

@end
