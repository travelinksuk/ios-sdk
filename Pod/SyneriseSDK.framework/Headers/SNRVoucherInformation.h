// 
//  SNRVoucherInformation.h
//  SyneriseSDK
//
//  Created by Synerise
//  Copyright (c) 2018 Synerise. All rights reserved.
//

#import "SNRBaseModel.h"

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(VoucherInformation)
@interface SNRVoucherInformation : SNRBaseModel

@property (copy, nonatomic, nullable, readonly) NSString *code;
@property (copy, nonatomic, nullable, readonly) NSDate *expireIn;
@property (copy, nonatomic, nullable, readonly) NSDate *redeemAt;
@property (copy, nonatomic, nullable, readonly) NSDate *assignedAt;
@property (copy, nonatomic, nullable, readonly) NSDate *createdAt;
@property (copy, nonatomic, nullable, readonly) NSDate *updatedAt;

@end

NS_ASSUME_NONNULL_END