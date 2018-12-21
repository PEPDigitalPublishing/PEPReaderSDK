//
//  PRWordInfoManager.h
//  PDFReaderSDKDiandu
//
//  Created by 李沛倬 on 2018/5/23.
//  Copyright © 2018年 pep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PREvaluateResult.h"


@class PRWordInfoModel;


// MARK: - PRWordInfoManager


/**
 统计用户的阅读信息，可在书本关闭后获取到本次阅读的信息。
 注意：每次打开书的时候都会将上一次的阅读信息清除
 */
@interface PRWordInfoManager : NSObject

/** 句子点读信息统计列表 */
@property (nonatomic, strong) NSMutableArray<PRWordInfoModel *> *wordInfoList;

/** 教材ID */
@property (nonatomic, copy) NSString *bookID;

/** 阅读页码进度 */
@property (nonatomic, assign) NSInteger pageNumber;

/** 阅读进度章节名 */
@property (nonatomic, copy) NSString *unit;

/** 阅读进度章节ID */
@property (nonatomic, copy) NSString *unitID;

/** 标题名 */
@property (nonatomic, copy) NSString *title;

/** 书本打开时间: 每次赋值都会重置所有的统计信息 */
@property (nonatomic, strong) NSDate *bookOpenDate;

/** 书本关闭时间 */
@property (nonatomic, strong) NSDate *bookCloseDate;


/** 构造单例 */
+ (instancetype)shareManager;

/** 重置统计信息 */
- (void)resetStatistics;




@end




// MARK: - PRWordInfoModel

/**
 获取此类中的属性不会得到nil
 */
@interface PRWordInfoModel : NSObject

/** 教材ID */
@property (nonatomic, copy) NSString *bookID;

/** 句子ID */
@property (nonatomic, copy) NSString *wordID;

/** 句子内容 */
@property (nonatomic, copy) NSString *wordContent;

/** 句子所属章节名 */
@property (nonatomic, copy) NSString *unit;

/** 句子所属章节ID */
@property (nonatomic, copy) NSString *unitID;

/** 句子所属页码 */
@property (nonatomic, assign) NSInteger pageIndex;

/** 句子内容在音频文件中的开始时间 */
@property (nonatomic, assign) NSTimeInterval beginTime;

/** 句子内容在音频文件中的结束时间 */
@property (nonatomic, assign) NSTimeInterval endTime;

/** 音频文件路径：相对路径 */
@property (nonatomic, copy) NSString *filePath;

/** 每次播放时长列表 */
@property (nonatomic, strong) NSMutableArray<NSNumber *> *durations;



// MARK: - 测评页面中的句子包含以下属性

/** 录音文件地址：绝对路径 */
@property (nonatomic, copy) NSString *recordPath;

/** 每次测评得分数组 */
@property (nonatomic, strong) NSMutableArray<PREvaluateResult *> *scores;


/** 测评句子所属测评组的ID：每一个对话场景或一篇课文为一个测评组 */
@property (nonatomic, copy) NSString *groupID;

/** 测评组名 */
@property (nonatomic, copy) NSString *group;


@end






















