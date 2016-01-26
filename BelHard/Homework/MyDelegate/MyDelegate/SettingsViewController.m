//
//  SettingsViewController.m
//  MyDelegate
//
//  Created by Vladas Zakrevskis on 21/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "SettingsViewController.h"
#import "DisplayViewController.h"

@interface SettingsViewController () <UITextFieldDelegate>

@end

@implementation SettingsViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
}

- (void)didPressSetLabelTextButton:(UIButton *)sender
{
    
    if ([self.delegate respondsToSelector:@selector(settingsViewController:didPressSetLabelTextButton:secondText:thirdText:fouthText:)]) {
        
        [self.delegate settingsViewController:self didPressSetLabelTextButton:self.textField.text secondText:self.secondTextField.text thirdText:self.thirdTextField.text fouthText:self.fouthTextField.text];
        
    }
    
    [self.navigationController popToRootViewControllerAnimated:YES];
}


- (void)textFieldDidEndEditing:(UITextField *)textField
{
    if ([self.delegate respondsToSelector:@selector(settingsViewController:textFieldDidEndEditing:)]) {
        
        [self.delegate settingsViewController:self textFieldDidEndEditing:textField];
        
    }
}


@end
