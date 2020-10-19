//
//  PRUtilHeader.h
//  PDFReaderSDKDiandu
//
//  Created by 李沛倬 on 2018/3/13.
//  Copyright © 2018年 pep. All rights reserved.
//

#ifndef PRUtilHeader_h
#define PRUtilHeader_h

/** 书本授权状态 */
typedef NS_ENUM(NSUInteger, PRBookAuth) {
    PRBookAuthExperience,                  /// 未授权：体验模式
    PRBookAuthPass,                        /// 验证通过
    PRBookAuthExpired,                     /// 授权过期
};


/** 评测引擎类型 */
typedef NS_ENUM(NSUInteger, PREvaluateEngineType) {
    PREvaluateEngineTypeXunFei,             /// 默认讯飞引擎
    PREvaluateEngineTypeYiQi,               /// 一起作业语音引擎
    PREvaluateEngineTypeOther               /// 其他测评引擎
};



/**
 播放类型

 - PRPlayingTypeDefault: 点读
 - PRPlayingTypeContinue: 连读
 - PRPlayingTypeEvaluate: 评测
 - PRPlayingTypeRepeat: 复读
 */
typedef NS_ENUM(NSUInteger, PRPlayingType) {
    PRPlayingTypeDefault,
    PRPlayingTypeContinue,
    PRPlayingTypeEvaluate,
    PRPlayingTypeRepeat,
};



/**
 工具栏按钮类型

 - PRToolBarItemTypeBack: 返回
 - PRToolBarItemTypeCatalog: 目录
 - PRToolBarItemTypeRepeat: 复读
 - PRToolBarItemTypeContinue: 连读
 - PRToolBarItemTypeEvaluate: 评测
 - PRToolBarItemTypeSetting: 设置
 - PRToolBarItemTypeKnowledge: 知识讲解
 - PRToolBarItemTypeSkip: 跳转（仅iPad有此项）
 */
typedef NS_ENUM(NSUInteger, PRToolBarItemType) {
    PRToolBarItemTypeBack           = 1000,
    PRToolBarItemTypeCatalog,
    PRToolBarItemTypeRepeat,
    PRToolBarItemTypeContinue,
    PRToolBarItemTypeEvaluate,
    PRToolBarItemTypeSetting,
    PRToolBarItemTypeKnowledge,
    PRToolBarItemTypeSkip,
};


typedef NS_ENUM(NSUInteger, PRRecordOptionsType) {
    PRRecordOptionsTypeSaveBetter   = 200,
    PRRecordOptionsTypeSaveLast,
};




/**
 工具栏按钮上设置Item展开后的功能类型

 - PRSettingItemTypeSpeed: 语速调节
 - PRSettingItemTypeTranslate: 翻译显示开关
 - PRSettingItemTypeHotspot: 可点读热区显示开关
 - PRSettingItemTypeReadingTimeCountdown：定时停止连续复读时间倒计时
 - PRSettingItemTypeSaveScore：设置保留的成绩类型（最高/最新）
 - PRSettingItemTypeFeedback: 反馈(仅自营点读有此功能入口)
 - PRSettingItemTypeHelp: 帮助
 */
typedef NS_ENUM(NSUInteger, PRSettingItemType) {
    PRSettingItemTypeSpeed,
    PRSettingItemTypeTranslate,
    PRSettingItemTypeHotspot,
//    PRSettingItemTypeReadingTimeCountdown,
    PRSettingItemTypeSaveScore,
    PRSettingItemTypeFeedback,
    PRSettingItemTypeHelp,
};


#endif /* PRUtilHeader.h_h */






















