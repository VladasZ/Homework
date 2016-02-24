//
//  InfoViewController.m
//  MyTableView
//
//  Created by Vladas Zakrevskis on 07/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "InfoViewController.h"

@implementation InfoViewController


- (void)viewWillAppear:(BOOL)animated
{    
    self.nameLabel.text = self.nameString;
    self.photoImageView.image = self.photoImage;
    self.bioTextView.text = self.bioString;
}

@end
