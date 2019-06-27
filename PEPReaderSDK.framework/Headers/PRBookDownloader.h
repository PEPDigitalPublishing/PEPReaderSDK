//
//  PRBookDownloader.h.h
//  PDFReaderSDK
//
//  Created by 李沛倬 on 2018/3/14.
//  Copyright © 2018年 pep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PEPNetworking/PEPNetworking.h>

@interface PRBookDownloader : NSObject

/**
 下载教材

 @param bookID 教材ID
 @param progressBlock 下载进度block
 @param successBlock 下载完成block
 @param failBlock 下载失败block
 @return 下载实例
 */
+ (PEPDownloadOperation *)downloadBookWithBookID:(NSString *)bookID
                                        progress:(void(^)(NSProgress *downloadProgress))progressBlock
                                         success:(void(^)(NSURL *filePath))successBlock
                                            fail:(void(^)(NSError *error))failBlock;


/**
 通过bookID从下载队列中获取下载实例

 @param bookID bookID
 @return 下载实例，如果下载队列中不存在该书，则返回nil
 */
+ (PEPDownloadOperation *)downloadOperationWithBookID:(NSString *)bookID;


/**
 获取下载队列中的所有下载实例
 */
+ (NSArray<PEPDownloadOperation *> *)downloadedBookList;


/**
 暂停下载任务

 @param bookID bookID
 @return 下载实例
 */
+ (PEPDownloadOperation *)pauseDownloadOfBookID:(NSString *)bookID;



/**
 继续下载任务

 @param bookID bookID
 @return 下载实例
 */
+ (PEPDownloadOperation *)continueDownloadOfBookID:(NSString *)bookID;


/**
 停止下载任务

 @param bookID bookID
 @return 下载实例
 */
+ (PEPDownloadOperation *)stopDownloadOfBookID:(NSString *)bookID;


/**
 从下载队列中删除下载任务。删除已下载书的时候需要同时调用该方法

 @param bookID bookID
 */
+ (void)deleteDownloadOperationOfBookID:(NSString *)bookID;


/**
 检查教材更新(异步，可能会进行网络请求)。已下载的教材调用此接口才会有效

 @param bookID bookID
 @param successBlock hasUpdate为YES时说明教材有更新
 @param failBlock 检查失败后回调的block
 */
+ (void)checkBookUpdateWithBookID:(NSString *)bookID
                          success:(void(^)(BOOL hasUpdate))successBlock
                             fail:(void(^)(NSError *error))failBlock;

/**
 检查教材更新(同步，不会进行网络请求)。已下载的教材调用此接口才会有效

 @param bookID bookID
 @param error error
 @return 为YES时说明教材有更新
 */
+ (BOOL)checkBookUpdateWithBookID:(NSString *)bookID error:(NSError **)error;


@end


























