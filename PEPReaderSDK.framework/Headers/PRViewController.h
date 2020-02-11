//
//  PRViewController.h
//  PDFReaderSDKDiandu
//
//  Created by 李沛倬 on 2018/3/19.
//  Copyright © 2018年 pep. All rights reserved.
//

#import "PEPBaseViewController.h"
#import <FoxitRDK/FSPDFObjC.h>
#import "PRUtilHeader.h"
#import "PRBookModel.h"
#import "PRWordInfoManager.h"

@class RJRFileManager, PRViewController;

// MARK: - PRViewControllerDelegate

@protocol PRViewControllerDelegate<NSObject>

//@required
@optional

/**
 体验模式结束，用户点击了“立即购买”按钮后将回调该代理方法
 
 @param bookModel 书本模型
 */
- (void)needPayWithBookModel:(PRBookModel *)bookModel;

/**
 体验模式结束时，将首先回调该方法。
 若对接方实现了该方法，则需要自己定制体验模式结束、引导用户购买的弹窗，「- (void)needPayWithBookModel:(PRBookModel *)bookModel」方法将不再回调；
 若对接方未实现该方法，则使用SDK内部默认的提示用户购买弹窗，「- (void)needPayWithBookModel:(PRBookModel *)bookModel」将会被回调。
 */
- (void)experienceDidEnded:(PRViewController *)vc bookModel:(PRBookModel *)bookModel;

/**
 播放类型已经改变时将会回调该代理方法
 
 @param playingType 播放类型，详见 PRPlayingType 枚举
 */
- (void)playingTypeDidChanged:(PRPlayingType)playingType;


/**
 当前音频已经播放结束：每个可点击区域是一个单独的音频
 */
- (void)currentAudioPlayingDidFinished;


/**
 阅读器将要关闭时回调该代理方法：用户点击了工具栏上的返回按钮
 */
- (void)readerWillClose:(PRViewController *)readerVC;

/**
 阅读器已经关闭后将回调该代理方法：dealloc
 */
- (void)readerDidClosed;

@end



// MARK: - PRViewController

@interface PRViewController : PEPBaseViewController

// MARK: - Readonly Property

/** 书本ID */
@property (nonatomic, copy, readonly) NSString *bookID;

/** 书本模型 */
@property (nonatomic, strong, readonly) PRBookModel *bookModel;

/** 播放类型 */
@property (nonatomic, assign, readonly) PRPlayingType playingType;

/** 记录阅读信息的单例 */
@property (nonatomic, weak, readonly) PRWordInfoManager *wordInfoManager;

/** 当前页码 */
@property (nonatomic, assign, readonly) NSInteger currentPage;

/** 当前页码所在目录节点ID。英语教材目录只有一级，此参数即为unitID；语文教材目录有多级，此参数为目录最深一层级的ID */
@property (nonatomic, copy, readonly) NSString *currentUnitID;


// MARK: - Readwrite Property

/** 主题色 */
@property (nonatomic, strong) UIColor *themeColor;

/** 代理 */
@property (nonatomic, weak) id<PRViewControllerDelegate> delegate;



// MARK: - init

/**
 初始化方法
 
 @param bookID 教材ID
 @param pageIndex 需要跳转的页码: 传0或者使用不包含该参数的方法，阅读器将会自动根据记录的阅读进度进行跳转(仅已购买教材会记录阅读进度)
 @param purchase 是否已购买：true为已购买，阅读无限制；false为体验模式，仅可阅读前5页。默认为false
 @return return value description
 */
- (instancetype)initWithBookID:(NSString *)bookID pageIndex:(NSInteger)pageIndex purchase:(BOOL)purchase;

- (instancetype)initWithBookID:(NSString *)bookID pageIndex:(NSInteger)pageIndex;

- (instancetype)initWithBookID:(NSString *)bookID purchase:(BOOL)purchase;

- (instancetype)initWithBookID:(NSString *)bookID;

/**
绕过教材鉴权初始化方法。
该方法内部不进行教材授权校验，直接以已购买状态打开教材。仅用于线上紧急处理已购买用户仍提示需购买的情况，正常情况下请勿调用此方法，内部会进行AppKey校验，需双方许可后开放该方法调用。
对于不符合该接口调用条件的（AppKey匹配且有userID存在），内部将会调用「initWithBookID:(NSString *)bookID pageIndex:(NSInteger)pageIndex purchase:(BOOL)purchase」方法进行初始化
 
@param bookID 教材ID
@param pageIndex 需要跳转的页码: 传0时阅读器将会自动根据记录的阅读进度进行跳转(仅已购买教材会记录阅读进度)
@return return value description
*/
- (instancetype)initBreakWithBookID:(NSString *)bookID pageIndex:(NSInteger)pageIndex;


// MARK: - Public Method

/**
 更新教材的购买状态。如需在阅读器打开的过程中更改书本状态（如已购买），则可调用此方法修改。
 
 @param purchase 是否已购买：true为已购买，阅读无限制；false为体验模式，仅可阅读前5页
 */
- (void)updateBookPurchaseState:(BOOL)purchase;


// MARK: - Components

/**
 跳转到指定页
 
 @param page 页码
 @param animated 是否需要动画
 */
- (void)scrollToPage:(NSInteger)page animated:(BOOL)animated;


/**
 隐藏组件视图: 缩略图
 */
- (void)hideComponentView;


/**
 显示组件视图：缩略图
 */
- (void)showComponentView;

/**
 停止播放
 */
- (void)stopPlaying;



// MARK: - About ToolBar

/**
 阅读器需要关闭时（如pop按钮被点击）请务必调用此方法，否则controller将无法被释放。
 此方法调用后会自动关闭阅读器。
 
 @param animated 是否需要动画
 */
- (void)cleanupAndCloseForReaderWithAnimated:(BOOL)animated;


/**
 显示目录
 
 @param show 为true时显示目录，false隐藏
 */
- (void)needShowCatalogView:(BOOL)show;


/**
 可点读热区开关
 
 @param on 为true时显示热区，false时不主动显示（点读过程中会显示当前播放句子的热区）
 */
- (void)needShowHotspots:(BOOL)on;


/**
 在点读时显示翻译内容：仅英语课本有效
 
 @param on 为true时显示翻译内容
 */
- (void)needShowTranslateOnReading:(BOOL)on;



/**
 设置点读音频的播放速度（语速）
 
 @param rate 播放速度，默认1.0。速度范围：0.5 ~ 2.0
 */
- (void)setPlayingRate:(CGFloat)rate;


/**
 改变播放类型
 
 @param type 支持的类型：详见 PRPlayingType 枚举类型
 */
- (BOOL)changePlayingType:(PRPlayingType)type;


/**
 显示引导帮助视图：在安装App后第一次进入阅读器，会自动显示引导帮助视图，之后不会主动显示，可手动调用该方法
 */
- (void)showGuideView;


@end





















