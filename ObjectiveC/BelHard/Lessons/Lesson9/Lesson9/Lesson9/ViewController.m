//
//  ViewController.m
//  Lesson9
//
//  Created by Vladas Zakrevskis on 09/02/16.
//  Copyright © 2016 Vladas Zakrevskis. All rights reserved.
//

#import "ViewController.h"
#import "VZAnnotation.h"

@interface ViewController () <MKMapViewDelegate, CLLocationManagerDelegate>

@property (nonatomic, weak) IBOutlet MKMapView *mapView;

@property (nonatomic, strong) CLLocationManager *locationManager;

@property (nonatomic, strong) VZAnnotation *userAnnotation;

@property (nonatomic) CGPoint tapLocation;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self init1];
    
    [self.mapView addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(didTapOnMap:)]];
    
}

- (void)didTapOnMap:(UITapGestureRecognizer *)sender
{
    CGPoint tapPoint = [sender locationInView:self.mapView];
    
    self.tapLocation = tapPoint;
    
    CLLocationCoordinate2D tapCoordinate = [self.mapView convertPoint:tapPoint toCoordinateFromView:self.mapView];
    
    VZAnnotation *annotation = [[VZAnnotation alloc] initWithCoordinate:tapCoordinate title:@"bla" subTitle:@"bla"];
    annotation.image = [UIImage imageNamed:@"pin1.png"];
    
    annotation.annotationType = AnnotationTypeAnimatedPin;
    
    [self.mapView addAnnotation:annotation];
    
    CLGeocoder *geoCoder = [[CLGeocoder alloc] init];
    
    CLLocation *location = [[CLLocation alloc] initWithLatitude:tapCoordinate.latitude longitude:tapCoordinate.longitude];
    
    [geoCoder reverseGeocodeLocation:location completionHandler:^(NSArray<CLPlacemark *> * _Nullable placemarks, NSError * _Nullable error) {
//        NSLog(@"%@", placemarks);
        
        if (placemarks.count > 0) {
            CLPlacemark *placemark = [placemarks firstObject];
            
            NSLog(@"%@", placemark.addressDictionary);
        }
    }];
    
}

- (void)locationManager:(CLLocationManager *)manager
     didUpdateLocations:(NSArray<CLLocation *> *)locations __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0){
    
    
    CLLocation *location = [locations lastObject];
    

    
    if (self.userAnnotation == nil){
        
        self.userAnnotation = [[VZAnnotation alloc] initWithCoordinate:location.coordinate title:@"user" subTitle:@"userLocation"];
        
        self.userAnnotation.annotationType = AnnotationTypeHuman;
        
    } else {
        
        self.userAnnotation.coordinate = location.coordinate;
        
    }
    
    [self.mapView addAnnotation:self.userAnnotation];
    
}

- (nullable MKAnnotationView *)mapView:(MKMapView *)mapView viewForAnnotation:(id <MKAnnotation>)annotation
{
    
    if ([annotation isKindOfClass:[MKUserLocation class]]) {

        return nil;
    }
    
    static NSString *annotationIdentifier = @"annotation";
    
    
    VZAnnotation *myAnnotation = (VZAnnotation *)annotation;
    
    MKAnnotationView *annotationView = [[MKAnnotationView alloc] initWithAnnotation:myAnnotation reuseIdentifier:annotationIdentifier];
    
  //  [annotationView setImage:myAnnotation.image];

    
    if (myAnnotation.annotationType == AnnotationTypeCar) {
        
        [annotationView setImage:[UIImage imageNamed:@"pin1.png"]];
        
    } else if (myAnnotation.annotationType == AnnotationTypeHuman) {
        
        [annotationView setImage:[UIImage imageNamed:@"pin2.png"]];
        
    } else if (myAnnotation.annotationType == AnnotationTypeAnimatedPin) {
        
        CGRect frame = CGRectZero;
        
        frame.origin = CGPointZero;
        frame.size.width  = 100.0;
        frame.size.height = 100.0;
        
        UIView *animatedView = [[UIView alloc] initWithFrame:frame];
        
        [annotationView setImage:[UIImage imageNamed:@"pin2.png"]];
        
        [animatedView setBackgroundColor:[UIColor colorWithRed:0.0 green:255.0/255.0 blue:0.3 alpha:0.3]];
        
        animatedView.layer.transform = CATransform3DMakeScale(0.0, 0.0, 0.0);
        animatedView.layer.cornerRadius = animatedView.bounds.size.height / 2;
        animatedView.layer.masksToBounds = YES;
        
        [UIView animateWithDuration:2.0 delay:0 options:UIViewAnimationOptionRepeat animations:^{
            
            animatedView.layer.transform = CATransform3DMakeScale(1.0, 1.0, 1.0);
            animatedView.alpha = 0.0;
            
        } completion:^(BOOL finished) {
        
            animatedView.layer.transform = CATransform3DMakeScale(0.0, 0.0, 0.0);
            animatedView.alpha = 0.3;
            
        }];
        
        [annotationView addSubview:animatedView];
        
    }
    

    return annotationView;
}


- (void)init1
{
    VZAnnotation *firstAnnotation = [[VZAnnotation alloc] initWithCoordinate:CLLocationCoordinate2DMake(53.001, 27) title:@"BLR1" subTitle:@"Belarus1"];
    
    VZAnnotation *secondAnnotation = [[VZAnnotation alloc] initWithCoordinate:CLLocationCoordinate2DMake(53.002, 27) title:@"BLR2" subTitle:@"Belarus2"];
    
    firstAnnotation.image = [UIImage imageNamed:@"pin1.png"];
    secondAnnotation.image = [UIImage imageNamed:@"pin2.png"];
    
    self.userAnnotation.image = [UIImage imageNamed:@"pin1.png"];
    
    
    firstAnnotation.annotationType = AnnotationTypeCar;
    secondAnnotation.annotationType = AnnotationTypeHuman;
    
    // [self.mapView addAnnotation:firstAnnotation];
    // [self.mapView addAnnotation:secondAnnotation];
    
    //[self.mapView addAnnotation:self.userAnnotation];
    
    self.locationManager = [[CLLocationManager alloc] init];
    self.locationManager.delegate = self;
    
    
    if ([self.locationManager respondsToSelector:@selector(requestAlwaysAuthorization)]) {
        [self.locationManager requestAlwaysAuthorization];
    }
    
    
    
    [self.locationManager startUpdatingLocation];
    
}


- (void)dispatch
{
    
//    
//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        [self.mapView addAnnotation:firstAnnotation];
//        [self.mapView addAnnotation:secondAnnotation];
//    });
//  
    
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        //code
        dispatch_sync(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            //main stream
        });
    });
    
    
    dispatch_queue_t mySerialQueue = dispatch_queue_create("Lesson9.Queue", NULL);
    
    dispatch_async(mySerialQueue, ^{
        for (NSUInteger i = 0; i < 100; i++) {
            // NSLog(@"Async");
        }
        dispatch_sync(mySerialQueue, ^{
            for (NSUInteger i = 0; i < 100; i++) {
                NSLog(@"Sync");//?
            }
        });
    });
    
    for (NSUInteger i = 0; i < 100; i++) {
        //  NSLog(@"Sync");
    }
    
    NSLog(@"0 seconds");
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        NSLog(@"5 seconds");
    });
    
    dispatch_apply(10, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(size_t i) {
        NSLog(@"dispatch apply");
    });
    
    
    dispatch_suspend(mySerialQueue);
    dispatch_resume(mySerialQueue);
    
    
    //- (void)setString:(NSString *)string;
    //{
    //    if (![_string isEqualToString:string]) {
    //
    //        NSString *oldString = _string;
    //        _string = [string retain];
    //        [oldString release];
    //        
    //    }
    //}
}


@end
