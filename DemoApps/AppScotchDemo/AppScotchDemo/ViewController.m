//
//  ViewController.m
//  AppScotchDemo
//
//  Created by Sadgb on 14/09/14.
//  Copyright (c) 2014 AppScotch. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic, retain) IBOutlet UIButton* playButton;
@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	
    [AppScotch setDelegate:self];
}

- (IBAction)runAppScotch:(id)sender
{
    self.playButton.enabled = NO;
    [self.playButton setAlpha:0.5];
    [AppScotch playAd:self];
}

- (void)onAdAvailable
{
    self.playButton.enabled = YES;
    [self.playButton setAlpha:1];
}

- (void)onAdUnavailable:(NSError *)error
{
    self.playButton.enabled = NO;
    [self.playButton setAlpha:0.5];
}

@end
