//
//  DetailViewController.h
//  Lesson5
//
//  Created by Vladas Zakrevskis on 21/01/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol DetailViewControllerDelegate;


@interface DetailViewController : UIViewController

@property (nonatomic, weak) id<DetailViewControllerDelegate> delegate;
@property (nonatomic, weak) IBOutlet UITextField *textField;

@property (nonatomic, strong) NSString *labelText;

- (IBAction) didPressButton:(UIButton *)sender;

@end


@protocol DetailViewControllerDelegate <NSObject>

- (void) detailViewController:(DetailViewController *)detailViewController didPresButtonWithText:(NSString *)text;

@end