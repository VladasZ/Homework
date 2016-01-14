//
//  ViewController.m
//  Lesson 3 - Text FIeld
//
//  Created by Vladas Zakrevskis on 14/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *textField;
@property (weak, nonatomic) IBOutlet UIButton *textFieldButton;
@property (weak, nonatomic) IBOutlet UITextView *textView;
@property (weak, nonatomic) IBOutlet UIButton *textViewButton;
@property (weak, nonatomic) IBOutlet UITextField *textFieldToLabel;
@property (weak, nonatomic) IBOutlet UILabel *label;
@property (weak, nonatomic) IBOutlet UIButton *textToLabelButton;

- (IBAction)didPressTextFieldButton:(UIButton *)sender;
- (IBAction)didPressTextViewButton:(UIButton *)sender;
- (IBAction)didPressTextToLabelButton:(UIButton *)sender;


@end

@implementation ViewController

- (IBAction)didPressTextFieldButton:(UIButton *)sender
{
    [self.textField becomeFirstResponder];
}

- (IBAction)didPressTextViewButton:(UIButton *)sender
{
    [self.textView becomeFirstResponder];
}

- (IBAction)didPressTextToLabelButton:(UIButton *)sender
{
    if (self.textFieldToLabel.text.length > 0) {
        
        self.label.text = self.textFieldToLabel.text;
        
    }
}


- (void)viewDidLoad {
    [super viewDidLoad];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}

@end
