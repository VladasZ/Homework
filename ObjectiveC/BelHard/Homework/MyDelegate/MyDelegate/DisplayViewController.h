//
//  DisplayViewController.h
//  MyDelegate
//
//  Created by Vladas Zakrevskis on 21/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DisplayViewController : UIViewController

@property (nonatomic, weak) IBOutlet UILabel *label;
@property (nonatomic, weak) IBOutlet UILabel *secondLabel;
@property (nonatomic, weak) IBOutlet UILabel *thirdLabel;
@property (nonatomic, weak) IBOutlet UILabel *fourthLabel;

- (IBAction)didPressSettingsButton:(UIButton *)sender;

@end
