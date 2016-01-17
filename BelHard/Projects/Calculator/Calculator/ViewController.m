//
//  ViewController.m
//  Calculator
//
//  Created by Vladas Zakrevskis on 14/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

#define RGB(r, g, b) [UIColor colorWithRed:(float)r / 255.0 green:(float)g / 255.0 blue:(float)b / 255.0 alpha:1.0]
#define EightDigitsNumber 99999999

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
    
 //   [self resizing];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Action methods
- (IBAction)didPressDigitButton:(UIButton *)sender
{
    if (self.displayValue > EightDigitsNumber ||
        self.displayValue < -EightDigitsNumber) return;
    
    if (self.operationButtonPressed) {
        
        self.previousValue = self.displayValue;
        self.displayValue = sender.tag;
        
        [self showDisplayValue];
        
        self.operationButtonPressed = NO;

    } else {
        
        self.displayValue *= 10;
        
        if (self.displayValue >= 0) self.displayValue += sender.tag;
        else                        self.displayValue -= sender.tag;
        
        [self showDisplayValue];
    }
}

- (IBAction)didPressACBUtton:(UIButton *)sender
{
    self.displayValue = 0;
    self.previousValue = 0;
    self.operationButtonPressed = NO;
    self.display.text = @"0";
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
    NSMutableString *displayString = [NSMutableString stringWithFormat:@"%ld", (long)self.displayValue];
    
    BOOL valueIsLessThanOne = (self.displayValue < 0);
    
    if (valueIsLessThanOne) {
        [displayString deleteCharactersInRange:NSMakeRange(0, 1)];
    }
    
    int commaPosition = 3;
    
    for (int i = 0; i < displayString.length ; i++) {
        
        if ( i == commaPosition) {
            
            [displayString insertString:@"," atIndex: displayString.length - i];
            
            commaPosition += 3;
            commaPosition++;

        }
    }
    
    if (valueIsLessThanOne) {
        [displayString insertString:@"-" atIndex:0];
    }
    
    self.display.text = displayString;

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

- (UIImage *)imageFromColor:(UIColor *)color// from stackovefwlow
{
    CGRect rect = CGRectMake(0, 0, 1, 1);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}

@end
