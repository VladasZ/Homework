//
//  DisplayViewController.m
//  MyDelegate
//
//  Created by Vladas Zakrevskis on 21/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "DisplayViewController.h"
#import "SettingsViewController.h"

@interface DisplayViewController () <SettingsViewControllerProtocol>

@end

@implementation DisplayViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

}


#pragma mark - Actions

- (IBAction)didPressSettingsButton:(UIButton *)sender
{
    
    SettingsViewController *controller = [self.storyboard instantiateViewControllerWithIdentifier:NSStringFromClass([SettingsViewController class])];
    
    controller.delegate = self;

    [self.navigationController pushViewController:controller animated:YES];
}

#pragma mark - SettingsViewControllerProtocol implementation

- (void)settingsViewController:(SettingsViewController *)settingsViewController didPressSetLabelTextButton:(NSString *)text secondText:(NSString *)secondText thirdText:(NSString *)thirdText fouthText:(NSString *)fourthText
{
    self.label.text = text;
    self.secondLabel.text = secondText;
    self.thirdLabel.text = thirdText;
    self.fourthLabel.text = fourthText;
}

- (void)settingsViewController:(SettingsViewController *)settingsViewController textFieldDidEndEditing:(UITextField *)textField
{
    switch (textField.tag) {
            
        case 1:
            self.label.text = textField.text;
            break;
            
        case 2:
            self.secondLabel.text = textField.text;
            break;
            
        case 3:
            self.thirdLabel.text = textField.text;
            break;
            
        case 4:
            self.fourthLabel.text = textField.text;
            break;
            
        default:
            break;
    }
}

@end
