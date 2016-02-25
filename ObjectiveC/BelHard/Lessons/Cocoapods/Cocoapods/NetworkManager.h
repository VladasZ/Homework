//
//  NetworkManager.h
//  Cocoapods
//
//  Created by Vladas Zakrevskis on 23/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFNetworking.h>

typedef void(^SuccessBlock)(id responseObject);
typedef void(^FailureBlock)(NSError *error);

extern NSString * const NetworkManagerBaseURL;

@interface NetworkManager : NSObject

+ (instancetype)sharedManager;

- (void)getSomeDataWithSuccessBlock:(SuccessBlock)successBlock
                       failureBlock:(FailureBlock)failureBlock;

@end
