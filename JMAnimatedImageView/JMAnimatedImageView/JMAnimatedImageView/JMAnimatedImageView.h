//
//  JMAnimatedImageView.h
//  JMAnimatedImageView
//
//  Created by jerome morissard on 15/08/14.
//  Copyright (c) 2014 jerome morissard. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JMOImageViewAnimationDelegate.h"
#import "JMOImageViewAnimationDatasource.h"
#import "JMGif.h"

#define JMDefaultGifDuration -1

typedef NS_ENUM(NSUInteger, JMAnimatedImageViewAnimationType) {
    JMAnimatedImageViewAnimationTypeNone                = 0,
    JMAnimatedImageViewAnimationTypeManualSwipe,
    JMAnimatedImageViewAnimationTypeAutomaticLinear,                    //use animationDuration + animationRepeatCount
    JMAnimatedImageViewAnimationTypeAutomaticLinearWithoutTransition,   //use animationDuration + animationRepeatCount
    JMAnimatedImageViewAnimationTypeAutomaticReverse                    //use animationDuration + animationRepeatCount
};

typedef NS_ENUM(NSUInteger, JMAnimatedImageViewMemoryOption) {
    JMAnimatedImageViewMemoryLoadImageSystemCache = 0,  //images memory will be retain by system
    JMAnimatedImageViewMemoryLoadImageLowMemoryUsage,   //images loaded but not retained by the system
    JMAnimatedImageViewMemoryLoadImageCustom            //images loaded by you (JMOImageViewAnimationDatasource)
};

typedef NS_ENUM(NSUInteger, JMAnimatedImageViewOrder) {
    JMAnimatedImageViewOrderNormal = 1,
    JMAnimatedImageViewOrderReverse = -1
};

typedef void (^JMCompletionFinishBlock)(BOOL resul);

@interface JMAnimatedImageView : UIImageView

@property (weak, nonatomic) IBOutlet id <JMOImageViewAnimationDatasource> animationDatasource;
@property (weak, nonatomic) IBOutlet id <JMOImageViewAnimationDelegate> animationDelegate;
@property (assign, nonatomic) JMAnimatedImageViewAnimationType animationType;
@property (assign, nonatomic) JMAnimatedImageViewMemoryOption memoryManagementOption;
@property (assign, nonatomic) JMAnimatedImageViewOrder imageOrder;
@property (assign, nonatomic) BOOL interactiveAnimation;

/**
 * reloadAnimationImages, This method will call animationDatasource
 */
- (void)reloadAnimationImages;

/**
 *  setCurrentIndex, This method will animate the modification of image
 *
 *  @param index    destination index
 *  @param animated BOOL animated
 */
- (void)setCurrentIndex:(NSInteger)index animated:(BOOL)animated;

/**
 *  setImage, This method will force the image to the index
 *
 *  @param img   UIImage
 *  @param index NSInteger index
 */
- (void)setImage:(UIImage *)img forCurrentIndex:(NSInteger)index;

/**
 *  animateToIndex:withDuration:, This method will animate the modification of images to access to the index in parameter.
 *
 *  @param index    NSInteger destination index
 *  @param duration NSTimeInterval duration
 */
- (void)animateToIndex:(NSInteger)index withDuration:(NSTimeInterval)duration;

/**
 *  animateToIndex:withDuration:withCompletionBlock:, This method will animate the modification of images to access to the index in parameter.
 *
 *  @param index    NSInteger destination index
 *  @param duration NSTimeInterval duration
 *  @param finishBlock JMCompletionFinishBlock CompletionBlock
 */
- (void)animateToIndex:(NSInteger)index withDuration:(NSTimeInterval)duration withCompletionBlock:(JMCompletionFinishBlock)finishBlock;

//Specific to GIF
@property (strong, readonly, nonatomic) JMGif *gifObject;

/**
 *  isAGifImageView
 *
 *  @return BOOL
 */
- (BOOL)isAGifImageView;

/**
 *  reloadAnimationImagesFromGifData:, This method reload a GIF image from a GIF NSData
 *
 *  @param data NSData data
 */
- (void)reloadAnimationImagesFromGifData:(NSData *)data;

/**
 *  reloadAnimationImagesFromGifNamed:, This method reload a GIF image from a GIF named
 *
 *  @param gitName NSString gitName
 */
- (void)reloadAnimationImagesFromGifNamed:(NSString *)gitName;

@end
