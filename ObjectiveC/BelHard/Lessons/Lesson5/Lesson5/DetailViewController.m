//
//  DetailViewController.m
//  Lesson5
//
//  Created by Vladas Zakrevskis on 21/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "DetailViewController.h"

@interface DetailViewController () <UITextFieldDelegate>

@end

@implementation DetailViewController



- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    NSLog(@"textField did begin editing");
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    
//    if ([self.delegate respondsToSelector:@selector(detailViewController:didPresButtonWithText:)]) {
//        
//        [self.delegate detailViewController:self didPresButtonWithText:self.textField.text];
//        
//    }
    

    
    self.labelText = textField.text;
    
    [self.navigationController popToRootViewControllerAnimated:YES];

    NSLog(@"textField did end editing");
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    //hides keyboard
    [textField resignFirstResponder];
    return YES;
}


- (IBAction) didPressButton:(UIButton *)sender
{
    if ([self.delegate respondsToSelector:@selector(detailViewController:didPresButtonWithText:)]) {
        
        [self.delegate detailViewController:self didPresButtonWithText:self.textField.text];
        
    }
    
    [self.navigationController popToRootViewControllerAnimated:YES];
    
}



@end
