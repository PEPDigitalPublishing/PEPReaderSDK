//
//  PREvaluateResult.h
//  PDFReaderSDK
//
//  Created by 李沛倬 on 2018/12/10.
//  Copyright © 2018 pep. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PREvaluateSentenceResult, PREvaluateWordResult;


@interface PREvaluateResult : NSObject

/** 评测语言 */
@property (nonatomic, copy) NSString *language;

/** 评测文本内容 */
@property (nonatomic, copy) NSString *content;

/** 语音引擎识别出的内容 */
@property (nonatomic, copy) NSString *usertext;

/** 百分制分数 */
@property (nonatomic, assign) CGFloat score;

/** ⽤户朗读开始时间，单位“秒” */
@property (nonatomic, assign) CGFloat begin;

/** ⽤户朗读结束时间，单位“秒” */
@property (nonatomic, assign) CGFloat end;

/** 句子的评测结果 */
@property (nonatomic, strong) NSArray<PREvaluateSentenceResult *> *sentences;

/** 状态码：0为正常 */
@property (nonatomic, assign) NSInteger code;

/** 错误信息 */
@property (nonatomic, copy) NSString *message;


@end




@interface PREvaluateSentenceResult : NSObject


/** 句子内容 */
@property (nonatomic, copy) NSString *content;

/** 百分制分数 */
@property (nonatomic, assign) CGFloat score;

/** ⽤户朗读开始时间，单位“秒” */
@property (nonatomic, assign) CGFloat begin;

/** ⽤户朗读结束时间，单位“秒” */
@property (nonatomic, assign) CGFloat end;

/** 单词或汉字的评测结果 */
@property (nonatomic, strong) NSArray<PREvaluateWordResult *> *words;


// MARK: - 一起作业SDK包含以下参数

/** ⽤户朗读识别内容 */
@property (nonatomic, copy) NSString *usertext;

/** 流利度得分，【0，100】之间的浮点数 */
@property (nonatomic, assign) CGFloat fluency;

/** 完整度得分，【0，100】之间的浮点数 */
@property (nonatomic, assign) CGFloat integrity;

/** 发⾳准确度，【0，100】之间的浮点数 */
@property (nonatomic, assign) CGFloat pronunciation;

/** 升调降调，0和1 */
@property (nonatomic, assign) NSInteger tone;




@end




@interface PREvaluateWordResult : NSObject

/** 单词或者汉字内容 */
@property (nonatomic, copy) NSString *content;

/** 百分制分数 */
@property (nonatomic, assign) CGFloat score;

/** ⽤户朗读开始时间，单位“秒” */
@property (nonatomic, assign) CGFloat begin;

/** ⽤户朗读结束时间，单位“秒” */
@property (nonatomic, assign) CGFloat end;

/**
 #### 讯飞
 0:正确，16: 未发音，32: 重复发音，64: 回读，128: 替换
 
 #### 一起作业
 0:多词，1:漏词，2:正常词，3:错误词，4:静⾳，5:重复词, 7:空格和标点, 8:⽣词
 */
@property (nonatomic, assign) NSInteger type;



@end




NS_ASSUME_NONNULL_END
