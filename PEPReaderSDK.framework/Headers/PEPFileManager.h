//
//  PEPFileManager.h
//  PDFReaderSDK
//
//  Created by 李沛倬 on 2018/3/9.
//  Copyright © 2018年 pep. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface PEPFileManager : NSObject


// MARK: - Readonly Property

/** SDK工作目录 */
@property (nonatomic, copy, readonly) NSString *SDKWorkspace;

/** 已下载书目录 */
@property (nonatomic, copy, readonly) NSString *downloadBookDir;

/** 下载资源目录 */
@property (nonatomic, copy, readonly) NSString *downloadResourceDir;

/** 下载缩略图目录 */
@property (nonatomic, copy, readonly) NSString *downloadThumbDir;

/** 在线书目录 */
@property (nonatomic, copy, readonly) NSString *onlineBookDir;

/** 缓存目录 */
@property (nonatomic, copy, readonly) NSString *cacheDir;

/** 录音文件目录 */
@property (nonatomic, copy, readonly) NSString *recordDir;





// MARK: - Methods

/** 构造单例 */
+ (instancetype)shareManager;


/**
 配置SDK工作目录，如果不设置或传入不正确的路径：
 点读SDK将设置为Documents/RJReadSDK
 数字教材SDK将设置为Documents/RJTextbookSDK
 
 @return return 是否配置成功
 */
- (BOOL)configSDKWorkspace:(NSString *)workspace;



// MARK: - 已下载教材

/**
 获取所有已下载书列表
 
 @return return bookID数组
 */
- (NSArray<NSString*> *)getDownloadedBooklist;

/**
 删除所有已下载书

 @return return value description
 */
- (BOOL)deleteAllDownlodedBook;


/**
 删除指定已下载书

 @param bookID 教材ID
 @return 是否删除成功。只有删除失败时返回false，删除成功和教材不存在都会返回true
 */
- (BOOL)deleteDownlodedBookWithBookID:(NSString *)bookID;


/**
 计算所有已下载书的大小

 @return size(byte)
 */
- (long long)sizeOfDownloadedBooks;


// MARK: - 在线阅读

/**
 计算所有在线阅读教材缓存大小

 @return size(byte)
 */
- (long long)sizeOfOnlineBookCaches;


/**
 计算指定书的在线阅读缓存大小

 @param bookID 教材ID
 @return size(byte)
 */
- (long long)sizeOfOnlineBookCacheWithBookID:(NSString *)bookID;


/**
 清除所有在线阅读教材缓存

 @return 是否清除成功
 */
- (BOOL)clearOnlineBookCaches;


/**
 清除指定教材在线阅读缓存

 @param bookID 教材ID
 @return 是否清除成功
 */
- (BOOL)clearOnlineBookCacheWithBookID:(NSString *)bookID;

/**
 计算缓存目录大小

 @return size(byte)
 */
- (long long)sizeOfCacheDirectory;


/**
 计算录音目录大小

 @return size(byte)
 */
- (long long)sizeOfRecordDirectory;


/**
 清除缓存目录所有文件

 @return 是否清除成功
 */
- (BOOL)clearCacheDirectory;


/**
 清除录音目录所有文件

 @return 是否清除成功
 */
- (BOOL)clearRecordDirectory;


@end























