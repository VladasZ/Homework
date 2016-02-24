//
//  ViewController.m
//  Tags
//
//  Created by Vladas Zakrevskis on 14/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic, weak) IBOutlet UIButton *buttonOne;
@property (nonatomic, weak) IBOutlet UIButton *buttonTwo;
@property (nonatomic, weak) IBOutlet UIButton *buttonThree;
@property (nonatomic) NSInteger value;

- (IBAction)didPressButton:(UIButton *)sender;

@end

@implementation ViewController

- (IBAction)didPressButton:(UIButton *)sender
{
    NSLog(@"%ld", (long)sender.tag);
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
