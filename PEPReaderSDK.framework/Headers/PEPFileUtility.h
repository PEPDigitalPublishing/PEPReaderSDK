//
//  PEPFileUtility.h
//  PDFReaderSDK
//
//  Created by 李沛倬 on 2018/3/12.
//  Copyright © 2018年 pep. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PEPFileUtility : NSObject

+ (BOOL)fileExists:(NSString *)filePath;

+ (BOOL)fileDelete:(NSString *)filePath;

+ (BOOL)fileClearDirectory:(NSString *)filePath;

+ (BOOL)fileCreateDirectory:(NSString *)filePath;
/// 创建文件
+ (BOOL)fileCreateFile:(NSString *)filePath;

+ (long long)sizeOfPath:(NSString *)filePath;

+ (BOOL)fileMoveAtPath:(NSString *)atPath toPath:(NSString *)toPath;

+ (BOOL)fileCopyAtPath:(NSString *)atPath toPath:(NSString *)toPath;

+ (int)fileSize:(NSString *)filePath;

@end
