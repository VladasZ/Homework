//
//  MasterViewController.m
//  Lesson 6 MVC
//
//  Created by Vladas Zakrevskis on 26/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "MasterViewController.h"
#import "DetailViewController.h"
#import "VZUserDefaults.h"

@interface MasterViewController () <UITextFieldDelegate>

@property (nonatomic, weak) IBOutlet UIImageView *imageView;

@property (nonatomic, weak) IBOutlet UITextField *textFieldOne;
@property (nonatomic, weak) IBOutlet UITextField *textFieldTwo;
@property (nonatomic, weak) IBOutlet UITextField *textFieldThree;

@property (nonatomic, weak) IBOutlet UILabel *labelOne;
@property (nonatomic, weak) IBOutlet UILabel *labelTwo;

@property (nonatomic, strong) VZUserDefaults *userDefaults;

- (IBAction)didPressButton:(UIButton *)sender;

@end

@implementation MasterViewController

#pragma mark - Getters

- (VZUserDefaults *)userDefaults
{
    if (_userDefaults == nil) {
        _userDefaults = [[VZUserDefaults alloc] init];
    }
    
    return _userDefaults;
}

#pragma mark - ViewDidLoad

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self.userDefaults setObject:@"Vasija" key:VZUserDefaultsFirstName];
    [self.userDefaults setObject:@"Petrovich" key:VZUserDefaultsName];
    [self.userDefaults setObject:@"Petrov" key:VZUserDefaultsLastName];
    [self.userDefaults setObject:@"Minsk" key:VZUserDefaultsCity];
    [self.userDefaults setObject:@33 key:VZUserDefaultsAge];

    self.textFieldOne.text = [self.userDefaults getObjectForKey:VZUserDefaultsFirstName];
    self.textFieldTwo.text = [self.userDefaults getObjectForKey:VZUserDefaultsName];
    self.textFieldThree.text = [self.userDefaults getObjectForKey:VZUserDefaultsLastName];
    
    self.labelOne.text = [self.userDefaults getObjectForKey:VZUserDefaultsCity];
    self.labelTwo.text = [NSString stringWithFormat:@"%@" ,[self.userDefaults getObjectForKey:VZUserDefaultsAge]];
    
}

#pragma mark - Actions

- (IBAction)didPressButton:(UIButton *)sender;
{
    DetailViewController *controller = [self.storyboard instantiateViewControllerWithIdentifier:NSStringFromClass(([DetailViewController class]))];
    
    controller.userDefaults = self.userDefaults;
    
    [self.navigationController pushViewController:controller animated:YES];
    
    
}

#pragma mark - UITextFieldDelegate implementation

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    switch (textField.tag) {
            
        case 0:
            [self.userDefaults setObject:textField.text key:VZUserDefaultsFirstName];
            break;
            
        case 1:
            [self.userDefaults setObject:textField.text key:VZUserDefaultsName];
            break;
            
        case 2:
            [self.userDefaults setObject:textField.text key:VZUserDefaultsLastName];
            break;
            
        default:
            break;
    }
}

-(BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    
    return YES;
}



@end
