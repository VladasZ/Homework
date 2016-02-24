//
//  SettingsViewController.h
//  MyDelegate
//
//  Created by Vladas Zakrevskis on 21/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^CompletionBlock)(NSString *, NSString *);

@protocol SettingsViewControllerProtocol;


@interface SettingsViewController : UIViewController

@property (nonatomic, copy) CompletionBlock completionBlock;

@property (nonatomic, strong) IBOutlet UITextField *textField;
@property (nonatomic, strong) IBOutlet UITextField *secondTextField;
@property (nonatomic, strong) IBOutlet UITextField *thirdTextField;
@property (nonatomic, strong) IBOutlet UITextField *fouthTextField;

@property (nonatomic, weak) id<SettingsViewControllerProtocol> delegate;

- (IBAction)didPressSetLabelTextButton:(UIButton *)sender;

@end



@protocol SettingsViewControllerProtocol <NSObject>

- (void)settingsViewController:(SettingsViewController *)settingsViewController didPressSetLabelTextButton:(NSString *)text secondText:(NSString *)secondText thirdText:(NSString *)thirdText fouthText:(NSString *) fourthText;
- (void)settingsViewController:(SettingsViewController *)settingsViewController textFieldDidEndEditing:(UITextField *)textField;

@end