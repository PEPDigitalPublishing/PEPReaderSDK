//
//  PREvaluationEngine.h
//  PDFReaderSDKDiandu
//
//  Created by hanhf on 2020/9/24.
//  Copyright © 2020年 pep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "PREvaluateResult.h"


/* Checks to see if calling process has permission to record audio.  The 'response' block will be called
 immediately if permission has already been granted or denied.  Otherwise, it presents a dialog to notify
 the user and allow them to choose, and calls the block once the UI has been dismissed.  'granted'
 indicates whether permission has been granted. Note that the block may be called in a different thread context.
 */
typedef void (^PermissionBlock)(BOOL granted);


// MARK: - Enum

/**
 评测语言类型
 
 - PREvaluationEngineLanguageUnknown: 未知类型
 - PREvaluationEngineLanguageEnglish: 英文
 - PREvaluationEngineLanguageChinese: 中文
 */
typedef NS_ENUM(NSUInteger, PREvaluationEngineLanguage) {
    PREvaluationEngineLanguageUnknown,
    PREvaluationEngineLanguageEnglish,
    PREvaluationEngineLanguageChinese,
};


/**
 评测语速
 
 - PREvaluationEngineSpeedSlow: 慢
 - PREvaluationEngineSpeedModerate: 适中
 - PREvaluationEngineSpeedFast: 快
 */
typedef NS_ENUM(NSUInteger, PREvaluationEngineSpeed) {
    PREvaluationEngineSpeedSlow,
    PREvaluationEngineSpeedModerate,
    PREvaluationEngineSpeedFast,
};


/**
 评测类型：中文评测内容不能超过180字节，英文评测内容不能超过300字节
 
 - PREvaluationEngineCategorySyllable: 单字（仅中文有单字，英文单词为Word）
 - PREvaluationEngineCategoryWord: 词组（中文） / 单词（英文）
 - PREvaluationEngineCategorySentence: 句子
 - PREvaluationEngineCategoryChapter: 篇章
 */
typedef NS_ENUM(NSUInteger, PREvaluationEngineCategory) {
    PREvaluationEngineCategorySyllable,
    PREvaluationEngineCategoryWord,
    PREvaluationEngineCategorySentence,
    PREvaluationEngineCategoryChapter,
};



// MARK: - PREvaluationEngineDelegate


// 第三方测评引擎需遵守该协议
@protocol PRThirdSpeechEvaluationEngineDelegate <NSObject>


/** 开始录音 */
- (void)startRecordWithText:(NSString *)textString savePath:(NSString *)wavPath;

/** 停止录音 */
- (void)stopRecord;

/** 取消录音 */
- (void)cancelRecord;

@end





@protocol PREvaluationEngineDelegate <NSObject>

@optional

/** 初始化引擎 */
//- (void)engineinitSuccess:(NSError *)error;

/** 开始录音 */
- (void)onBeginOfSpeech;

/** 结束录音 */
- (void)onEndOfSpeech;

/** 取消录音 */
- (void)onCancel;

/** 出错 */
- (void)onError:(NSString *)msg;

/// 评测出错回调
/// @param errorCode 错误码
/// @param errorType 错误类型：仅讯飞SDK有此参数
/// @param message 错误信息
- (void)onErrorWithErrorCode:(NSInteger)errorCode errorType:(NSInteger)errorType errorMessage:(NSString *)message;

/** 音量大小 */
- (void)recordVolume:(CGFloat)volume;

/** 评测结果 */
- (void)followResult:(PREvaluateResult *)result;

/** 在线评测语音 */
- (void)onlineWavUrl:(NSString *)url;

/** 本地录音文件地址 */
- (void)offlinePath:(NSString *)path;

@end




@interface PREvaluationEngine : NSObject

/* 评测语言类型：默认英文 */
@property (nonatomic, assign) PREvaluationEngineLanguage language;

/* 评测类型：默认句子类型 */
@property (nonatomic, assign) PREvaluationEngineCategory engineCategory;

/* 评测语速：默认适中 */
@property (nonatomic, assign) PREvaluationEngineSpeed speed;

/* 评测引擎代理 */
@property (nonatomic, weak) id<PREvaluationEngineDelegate> delegate;


/// 第三方测评引擎代理
@property (nonatomic, weak) id<PRThirdSpeechEvaluationEngineDelegate> thirdSpeechEvaluatorDelegate;

/* 需要评测的文本 */
@property (nonatomic, copy) NSString *text;


+ (instancetype)shareInstance;


+ (NSString *)translatePhoneticNotationWithString:(NSString *)string;

/** 获取麦克风的授权状态 */
+ (void)requestRecordPermission:(PermissionBlock)response;

/** 开始录音 */
- (void)startRecord;

/** 停止录音 */
- (void)stopRecord;

/** 取消录音 */
- (void)cancelRecord;


@end










