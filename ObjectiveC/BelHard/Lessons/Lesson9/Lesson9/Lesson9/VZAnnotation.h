//
//  VZAnnotation.h
//  Lesson9
//
//  Created by Vladas Zakrevskis on 09/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

typedef enum {
    AnnotationTypeCar,
    AnnotationTypeHuman,
    AnnotationTypeAnimatedPin
} AnnotationType;

@interface VZAnnotation : NSObject <MKAnnotation>

@property (nonatomic) CLLocationCoordinate2D coordinate;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;

@property (nonatomic, strong) UIImage *image;

@property (nonatomic) AnnotationType annotationType;

- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate title:(NSString *)title subTitle:(NSString *)subTitle;


@end
