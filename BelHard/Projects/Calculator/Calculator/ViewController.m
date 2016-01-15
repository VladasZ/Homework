//
//  ViewController.m
//  Calculator
//
//  Created by Vladas Zakrevskis on 14/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"
#define RGB(r, g, b) [UIColor colorWithRed:(float)r / 255.0 green:(float)g / 255.0 blue:(float)b / 255.0 alpha:1.0]

@interface ViewController ()

typedef enum {
    Plus = 100,
    Minus,
    Multiply,
    Divide
} OperationType;

@property (nonatomic, strong) IBOutletCollection(UIButton) NSArray *lightGrayButtons;
@property (nonatomic, strong) IBOutletCollection(UIButton) NSArray *darkGrayButtons;
@property (nonatomic, strong) IBOutletCollection(UIButton) NSArray *orangeButtons;

@property (weak, nonatomic) IBOutlet UIButton *acButton;


@property (nonatomic, weak) IBOutlet UILabel *display;
@property (nonatomic) NSInteger displayValue;
@property (nonatomic) NSInteger previousValue;
@property (nonatomic) OperationType operationToDo;
@property (nonatomic) BOOL operationButtonPressed;

@property (nonatomic) CGFloat resizeCoefficient;
@property (nonatomic) BOOL needToResize;

- (IBAction)didPressDigitButton:(UIButton *)sender;
- (IBAction)didPressACBUtton:(UIButton *)sender;
- (IBAction)didPressOperationButton:(UIButton *)sender;
- (IBAction)didPressEqualsButton:(UIButton *)sender;
- (IBAction)didPressPlusMinusButton:(UIButton *)sender;

- (void)showDisplayValue;

@end

@implementation ViewController

#pragma mark - Default methods
- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSLog(@"Width - %f. Height - %f", self.view.frame.size.width, self.view.frame.size.height);
    
    self.displayValue = 0;
    self.previousValue = 0;
    
    
    
    for (UIButton *button in self.darkGrayButtons) {
        button.backgroundColor = RGB(204, 205, 209);
    }
    
    for (UIButton *button in self.lightGrayButtons) {
        button.backgroundColor = RGB(190, 190, 193);
    }
    
    for (UIButton *button in self.orangeButtons) {
        button.backgroundColor = RGB(255, 141, 12);
    }
    
    self.view.backgroundColor = RGB(29, 29, 29);
    
    [self resizing];

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
    self.display.font = [self.display.font fontWithSize:100];
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
        [self calculate];
}

- (IBAction)didPressPlusMinusButton:(UIButton *)sender
{
    self.displayValue = -self.displayValue;
    [self showDisplayValue];
}

#pragma mark - Other methods
- (void)showDisplayValue
{
    self.display.text = [NSString stringWithFormat:@"%ld" , (long)self.displayValue];
    
    if (self.display.text.length > 6) {
        
        self.display.font = [self.display.font fontWithSize:75];

    }
    
    if (self.display.text.length > 7) {
        
        self.display.font = [self.display.font fontWithSize:60];

    }
    
    if (self.display.text.length > 8) {
        
        self.display.font = [self.display.font fontWithSize:50];

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

- (void) resizeButton:(UIButton *)element
{
    NSLog(@"resize");
    
    CGRect frame = element.frame;
    
    frame.origin.x *= self.resizeCoefficient;
    frame.origin.y *= self.resizeCoefficient;
    frame.size.height *= self.resizeCoefficient;
    frame.size.width *= self.resizeCoefficient;
    
    element.frame = frame;
}

- (void)resizing// don't work
{
        if (self.view.frame.size.width == 375) {
    
            self.resizeCoefficient = 1;
            self.needToResize = NO;
            NSLog(@"No need to resize");
    
        } else {
                [super viewDidLayoutSubviews];
        [super viewDidLayoutSubviews];
    
            self.resizeCoefficient = self.view.frame.size.width / 375;
            self.needToResize = YES;
            NSLog(@"Starting with resize %f", self.resizeCoefficient);
    
            for (UIButton *button in self.darkGrayButtons) {
    
                CGRect frame = button.frame;
    
                frame.origin.x *= self.resizeCoefficient;
                frame.origin.y *= self.resizeCoefficient;
                frame.size.height *= self.resizeCoefficient;
                frame.size.width *= self.resizeCoefficient;
    
                button.frame = frame;        }
            
        }
        
    
}

@end
