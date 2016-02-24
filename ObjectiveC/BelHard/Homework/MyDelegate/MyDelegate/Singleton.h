//
//  Singleton.h
//  MyDelegate
//
//  Created by Vladas Zakrevskis on 02/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Singleton : NSObject

@property (nonatomic, strong) NSString *textString;

+ (id)sharedManager;

@end
