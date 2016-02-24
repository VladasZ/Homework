//
//  ViewController.m
//  Lesson3
//
//  Created by Vladas Zakrevskis on 14/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic, weak) IBOutlet UIButton *button1;
@property (nonatomic, weak) IBOutlet UIButton *button2;
@property (nonatomic, weak) IBOutlet UIButton *button3;

@property (weak, nonatomic) IBOutlet UIButton *resizeButton;

- (IBAction)didPressButton1:(UIButton *)sender;
- (IBAction)didPressButton2:(UIButton *)sender;
- (IBAction)didPressButton3:(UIButton *)sender;



//{
//
//@property (nonatomic, weak) IBOutlet UILabel *firstLabel;
//@property (nonatomic, strong)
//IBOutletCollection(UILabel) NSArray *labelsArray;
//@property (nonatomic, weak) IBOutlet UIButton *button;
//
//- (IBAction)didPressFirstButton:(UIButton *)sender;
//}

@end

@implementation ViewController

- (IBAction)didPressButton1:(UIButton *)sender
{
    CGRect rect;
    rect.size.height = 100;
    rect.size.width = 100;
    rect.origin.x = 100;
    rect.origin.y = 100;
    
    self.resizeButton.frame = rect;

}

- (IBAction)didPressButton2:(UIButton *)sender
{
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
//CODE
    {
//    CGPoint origin = CGPointMake(100, 100);
//    CGSize size = CGSizeMake(100, 100);
//    CGRect frame;
//    
//    frame.origin = origin;
//    frame.size = size;
//    
//    //Center
//    frame.origin.x = (self.view.frame.size.width - frame.size.width) / 2;
//    frame.origin.y = (self.view.frame.size.height - frame.size.height) / 2;
//
//    UILabel *firstLabel = [[UILabel alloc] initWithFrame:frame];
//    firstLabel.text = @"Label text";
//    firstLabel.backgroundColor = [UIColor redColor];
//    
    //[self.view addSubview:firstLabel];
    }
    
  //  self.firstLabel.backgroundColor = [UIColor yellowColor];
    
}


//- (IBAction)didPressFirstButton:(UIButton *)sender
//{
//    [super viewDidLayoutSubviews];
//    
//    sender.backgroundColor = [UIColor brownColor];
//    sender.selected = !sender.selected;
//    
//    for (UILabel *label in self.labelsArray) {
//        
//        if ([label isKindOfClass:[UILabel class]]) {
//            
//            label.backgroundColor = [UIColor redColor];
//            label.textColor = [UIColor blueColor];
//            
////            if (sender.selected) {
////                label.text = @"selected";
////            } else {
////                label.text = @"unselected";
////            }
//            
//            srand(time(0));
//            
//            CGRect frame = label.frame;
//            frame.size.width = arc4random() % 200;
//            label.frame = frame;
//            
//           // [label removeFromSuperview];
//            
//
//            
//            
//        }
//    }
//    
//    
//}

//Size change
- (void)viewDidLayoutSubviews
{
    
}



- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
