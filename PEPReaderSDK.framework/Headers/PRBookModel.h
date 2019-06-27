//
//  PRBookModel.h
//  PDFReaderSDKDiandu
//
//  Created by 李沛倬 on 2018/4/28.
//  Copyright © 2018年 pep. All rights reserved.
//

#import <Foundation/Foundation.h>

/** 学科 */
typedef NS_ENUM(NSUInteger, PRBookSubject) {
    /// 未知。默认
    PRBookSubjectUnknow         = 0,
    /// 语文
    PRBookSubjectChinese        = 11,
    /// 英语
    PRBookSubjectEnglish        = 12,
    /// 数学
    PRBookSubjectMath           = 21,
};

// MARK: - PRBookModel

@interface PRBookModel : NSObject

/** 资源+教材PDF包（离线包）下载地址 */
@property (nonatomic, copy) NSString *download_url;
/** 高清版资源+教材PDF包（离线包）下载地址 */
@property (nonatomic, copy) NSString *download_url_hd;

/** 教材版本 */
@property (nonatomic, copy) NSString *version;

/** 目录地址 */
@property (nonatomic, copy) NSString *catalog_url;

/** 教材大小 */
@property (nonatomic, assign) double size;
/** 高清版教材大小 */
@property (nonatomic, assign) double size_hd;

/** 教材封面缩略图地址 */
@property (nonatomic, copy) NSString *icon_url;

/** 缩略图相对路径 */
@property (nonatomic, copy) NSString *preview_url;

/** 教材ID */
@property (nonatomic, copy) NSString *book_id;

/** 是否支持评测 */
@property (nonatomic, assign) BOOL evaluation_support;

/** 学期 */
@property (nonatomic, copy) NSString *term;

/** 教材名称：只包含学科和版本，不包含年级和学期 */
@property (nonatomic, copy) NSString *book_name;

/** 年级 */
@property (nonatomic, copy) NSString *grade;

/** 教材PDF下载地址 */
@property (nonatomic, copy) NSString *book_url;
/** 高清版教材PDF下载地址（iPad会自动使用该参数） */
@property (nonatomic, copy) NSString *book_url_hd;

/** 正文开始页码 */
@property (nonatomic, assign) NSUInteger ex_pages;

/** 修改时间 */
@property (nonatomic, copy) NSString *modify_time;

/** 是否有练习 */
@property (nonatomic, assign) BOOL is_practise;

/** 扉页中特殊前缀开头的页面的数量 */
@property (nonatomic, assign) NSInteger titlePages;

/** 扉页中特殊页面的前缀 */
@property (nonatomic, copy) NSString *titlePrefix;

/** 扉页中特殊前缀开头页面是从第几页开始的（相对于100x页面的页码偏移，比如若S1的页码为1005，那么该参数的值就为5） */
@property (nonatomic, assign) NSInteger titleOffset;

/** 学科 */
@property (nonatomic, assign) PRBookSubject subject_id;

/** 教材中一共有多少个音频锚点 */
@property (nonatomic, assign) NSInteger total_words;




// MARK: - Readonly

/** 完整教材名称，如：语文（统编版）一年级上册 */
@property (nonatomic, copy, readonly) NSString *fullName;

/** 是否已购买 */
@property (nonatomic, assign, readonly, getter=isPurchase) BOOL purchase;

/** 是否已下载 */
@property (nonatomic, assign, readonly, getter=isDownloaded) BOOL downloaded;

/** 是否在下载中 */
@property (nonatomic, assign, readonly, getter=isDownloading) BOOL downloading;

/** 已下载教材的PDF路径，未下载时该属性为nil */
@property (nonatomic, copy, readonly) NSString *downloadedPDFPath;


@end



// MARK: - PRBookTermModel

@interface PRBookTermModel : NSObject

/** 学期名：上、下 */
@property (nonatomic, copy) NSString *term;

/** 教材数组 */
@property (nonatomic, strong) NSArray<PRBookModel *> *textbooks;


@end



// MARK: - PRBookGradeModel

@interface PRBookGradeModel: NSObject

/** 年级名 */
@property (nonatomic, copy) NSString *gradename;

/** 学期数组 */
@property (nonatomic, strong) NSArray<PRBookTermModel *> *grade;


@end


// MARK: - PRBooklistModel

@interface PRBooklistModel : NSObject

@property (nonatomic, strong) NSArray<PRBookGradeModel *> *booklist;

@property (nonatomic, assign) NSInteger errcode;

@property (nonatomic, copy) NSString *errmsg;

@end


















