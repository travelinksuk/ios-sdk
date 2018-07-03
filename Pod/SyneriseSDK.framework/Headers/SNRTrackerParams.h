//
//  SNRTrackerParams.h
//  SyneriseSDK
//
//  Copyright © 2018 Synerise. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(TrackerParamsBuilder)
@interface SNRTrackerParamsBuilder : NSObject

/**
 Adds provided @c NSString object to the parameters.

 @param string @c NSString object to be saved.
 @param key @c NSString object representing key under which @c string will be stored.
 */
- (void)setString:(nonnull NSString *)string forKey:(nonnull NSString *)key;

/**
 Adds provided @c NSInteger value to the parameters.

 @param integer @c NSInteger value to be saved.
 @param key @c NSString object representing key under which @c integer will be stored.
 */
- (void)setInt:(NSInteger)integer forKey:(nonnull NSString *)key;

/**
 Adds provided @c double value to the parameters.

 @param doubleValue @c double value to be saved.
 @param key @c NSString object representing key under which @c doubleValue will be stored.
 */
- (void)setDouble:(double)doubleValue forKey:(nonnull NSString *)key;

/**
 Adds provided @c float value to the parameters.

 @param floatValue @c float value to be saved.
 @param key @c NSString object representing key under which @c floatValue will be stored.
 */
- (void)setFloat:(float)floatValue forKey:(nonnull NSString *)key;

/**
 Adds provided @c BOOL value to the parameters.

 @param boolValue @c BOOL value to be saved.
 @param key @c NSString object representing key under which @c boolValue will be stored.
 */
- (void)setBool:(BOOL)boolValue forKey:(nonnull NSString *)key;

/**
 Adds a given key-value pair to the parameters.

 @note @c object must be JSON encodable object

 @attention Raises an @c NSInvalidArgumentException if object is not JSON encodable.
 @attention Raises an @c NSInvalidArgumentException if object is nil.

 @param object JSON encodable object
 @param key The key for @c object
 */
- (void)setObject:(nonnull id)object forKey:(nonnull NSString *)key;

@end

NS_ASSUME_NONNULL_END

/**
 Represents custom parameters that may be added to tracked events.
 */

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(TrackerParams)
@interface SNRTrackerParams : NSObject

- (nullable instancetype)init __unavailable __attribute__((unavailable("Use [SNTRackerParams makeWithBuilder:] instead")));

+ (nullable instancetype)new __attribute__((unavailable("Use [SNTRackerParams makeWithBuilder:] instead")));

/**
 Initializes @c SNRTrackerParams object with @c SNRTrackerParamsBuilder.

 @param buildBlock A block object with one @c SNRTrackerParamsBuilder param that acts as builder.
 @return initialized @c SNTTrackerParams object.
 */
+ (instancetype)makeWithBuilder:(void (^)(SNRTrackerParamsBuilder *builder))buildBlock;

@end

NS_ASSUME_NONNULL_END
