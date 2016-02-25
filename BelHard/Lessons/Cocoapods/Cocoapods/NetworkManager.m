//
//  NetworkManager.m
//  Cocoapods
//
//  Created by Vladas Zakrevskis on 23/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "NetworkManager.h"

NSString * const NetworkManagerBaseURL = @"http://dev.ebuyts.com";
NSString * const someURL = @"/api/common";

@interface NetworkManager ()

@property (nonatomic, strong) AFHTTPSessionManager *requestManager;

@end

@implementation NetworkManager

- (instancetype)init
{
    self = [super init];
    if (self) {
        
        self.requestManager =
        [[AFHTTPSessionManager alloc]
         initWithBaseURL:[NSURL URLWithString:NetworkManagerBaseURL]];
        
        [self.requestManager setRequestSerializer:[AFJSONRequestSerializer serializer]];
        [self.requestManager setResponseSerializer:[AFJSONResponseSerializer serializer]];
        
    }
    return self;
}

+ (instancetype)sharedManager
{
    static NetworkManager *sharedManager;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        sharedManager = [[NetworkManager alloc] init];
    });
    
    return sharedManager;
}

- (void)getSomeDataWithSuccessBlock:(SuccessBlock)successBlock
                       failureBlock:(FailureBlock)failureBlock
{
    
    [self.requestManager GET:someURL parameters:nil progress:^(NSProgress * _Nonnull downloadProgres) {
        
        
    } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        
        successBlock(responseObject);
        
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        
        failureBlock(error);
        
    }];
    
}

@end
