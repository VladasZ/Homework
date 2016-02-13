//
//  SettingsViewController.m
//  MyDelegate
//
//  Created by Vladas Zakrevskis on 21/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "SettingsViewController.h"
#import "DisplayViewController.h"
#import "Singleton.h"

@interface SettingsViewController () <UITextFieldDelegate>

@end

@implementation SettingsViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    if (self.completionBlock) {
        self.completionBlock(@"bla1", @"bla2");
    }
    
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
    
    if (textField.tag == 1) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"observer" object:self.textField.text];
    }
    
    if (textField.tag == 2) {
        [[Singleton sharedManager] setTextString:self.secondTextField.text];
    }
    
}
@end
