//
//  Profile.h
//  MyTableView
//
//  Created by Vladas Zakrevskis on 07/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ProfileDelegate;

@interface Profile : NSObject

@property (nonatomic, strong) UIImage *photo;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *bio;

- (instancetype)initWithName:(NSString *)name photo:(UIImage *)photo bio:(NSString *)bio;

@end

