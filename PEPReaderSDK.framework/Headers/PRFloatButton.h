//
//  PRFloatButton.h
//  PDFReaderSDKDiandu
//
//  Created by 韩帅 on 2021/7/26.
//  Copyright © 2021 pep. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class PRFloatButton;
@protocol PRFloatButtonDelegate <NSObject>
/** 点击悬浮球的回调 */
- (void)PRFloatButtonClick:(PRFloatButton *)floatButton;
@end

typedef NS_ENUM(NSUInteger, PRFloatButtonType) {
    /** 仅可停留在左、右 */
    PRFloatButtonTypeHorizontal,
    /** 可停留在上、下、左、右 */
    PRFloatButtonTypeEachSide
};

@interface PRFloatButton : UIButton
/** 代理 */
@property (nonatomic, weak) id<PRFloatButtonDelegate> delegate;

@property (nonatomic, assign) PRFloatButtonType leanType;

@property(nonatomic,assign)CGFloat buttonSpace;/**<  */

- (instancetype)initWithFrame:(CGRect)frame delegate:(id<PRFloatButtonDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
