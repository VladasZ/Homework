//
//  MasterViewController.h
//  Lesson5
//
//  Created by Vladas Zakrevskis on 21/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MasterViewController : UIViewController

@property (nonatomic, weak) IBOutlet UILabel *label;
@property (nonatomic, weak) IBOutlet UILabel *secondLabel;
@property (nonatomic, weak) IBOutlet UILabel *thirdLabel;

@property (nonatomic, weak) IBOutlet UIButton *button;

@property (nonatomic, strong) NSString *labelText;

- (IBAction)didPressButton:(UIButton *)sender;

@end
