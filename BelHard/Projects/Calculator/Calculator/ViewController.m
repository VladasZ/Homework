//
//  ViewController.m
//  Calculator
//
//  Created by Vladas Zakrevskis on 14/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

typedef enum {
    Plus = 100,
    Minus,
    Multiply,
    Divide
} OperationType;

@property (nonatomic, weak) IBOutlet UILabel *display;
@property (nonatomic) NSInteger displayValue;
@property (nonatomic) NSInteger previousValue;
@property (nonatomic) OperationType operationToDo;
@property (nonatomic) BOOL operationButtonPressed;

- (IBAction)didPressDigitButton:(UIButton *)sender;
- (IBAction)didPressACBUtton:(UIButton *)sender;
- (IBAction)didPressOperationButton:(UIButton *)sender;
- (IBAction)didPressEqualsButton:(UIButton *)sender;

- (void)showDisplayValue;

@end

@implementation ViewController

#pragma mark - Default methods
- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSLog(@"Width - %f. Height - %f", self.view.frame.size.width, self.view.frame.size.height);
    
    self.displayValue = 0;
    self.previousValue = 0;
    
    self.display.font = [UIFont systemFontOfSize:89];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Action methods
- (IBAction)didPressDigitButton:(UIButton *)sender
{
    if (self.operationButtonPressed) {
        
        self.previousValue = self.displayValue;
        self.displayValue = sender.tag;
        
        [self showDisplayValue];
        
        self.operationButtonPressed = NO;

    } else {
        
        self.displayValue *= 10;
        self.displayValue += sender.tag;
    
        [self showDisplayValue];
    }
}

- (IBAction)didPressACBUtton:(UIButton *)sender
{
    self.displayValue = 0;
    self.previousValue = 0;
    self.operationButtonPressed = NO;
    self.display.text = @"0";
    self.display.font = [UIFont systemFontOfSize:89];

}

- (IBAction)didPressOperationButton:(UIButton *)sender
{
    if (self.previousValue) {
        [self calculate];
    }
    
    self.operationButtonPressed = YES;
    self.previousValue = self.displayValue;

    if (sender.tag >= Plus && sender.tag <= Divide) {
        self.operationToDo = (OperationType)sender.tag;
    }
    
}

- (IBAction)didPressEqualsButton:(UIButton *)sender
{
    
}

#pragma mark - Other methods
- (void)showDisplayValue
{
    self.display.text = [NSString stringWithFormat:@"%ld" , (long)self.displayValue];
    
    if (self.display.text.length > 6) {
        self.display.font = [UIFont systemFontOfSize:75];
    }
    
    if (self.display.text.length > 7) {
        self.display.font = [UIFont systemFontOfSize:60];
    }
    
    if (self.display.text.length > 8) {
        self.display.font = [UIFont systemFontOfSize:50];
    }
    
}

- (void)calculate
{
    switch (self.operationToDo) {
            
        case Plus:
            
            self.displayValue += self.previousValue;
            
            break;
            
        case Minus:
            
            self.previousValue -= self.displayValue;
            self.displayValue = self.previousValue;
            
            break;
            
        case Multiply:
            
            self.displayValue *= self.previousValue;
            
            break;
            
        case Divide:
            
            if (!self.displayValue) break;// division by zero. Add message.
            
            self.previousValue /= self.displayValue;
            self.displayValue = self.previousValue;
            
            break;
            
        default:
            break;
    }
    
    [self showDisplayValue];
}
@end
