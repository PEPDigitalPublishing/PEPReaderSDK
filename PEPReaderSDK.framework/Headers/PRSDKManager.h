//
//  PRSDKManager.h
//  PDFReaderSDKDiandu
//
//  Created by 李沛倬 on 2018/3/12.
//  Copyright © 2018年 pep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PRUtilHeader.h"
#import "PRBookModel.h"

@interface PRSDKManager : NSObject


/**
 配置正式或者测试环境。此方法需要在setAppKey:之前调用。
 人教点读SDK目前对外只提供一个域名，以AppKey来区分正式环境和测试环境，故而此接口只需传入true即可。
 
 @param isRelease true为正式环境，false为测试环境
 */
+ (void)configServerMode:(BOOL)isRelease;


/**
 SDK认证: 建议在AppDelegate中配置。
 SDK中有网络请求的接口均需要AppKey参数，因此此方法请务必调用并传入正确参数，否则其他接口可能无法正常获取数据

@param appKey 对接时分配的appKey，用于区别不同的对接平台
*/
+ (void)setAppKey:(NSString *)appKey;



/**
 设置评测引擎类型：默认在线讯飞
 
 @param type 详见 PREvaluateEngineType 枚举
 */
+ (void)setEvaluateEngineType:(PREvaluateEngineType)type;

/**
 设置讯飞SDK的AppID。格式形如：appid=xxxxxx
 如果不设置或者传空，SDK内部将会设置默认的AppID。
 注意：目前版本的讯飞SDK不支持一个App中使用两个不同的AppID，而且AppID跟讯飞SDK的静态库文件绑定，不同的AppID无法正常初始化讯飞SDK。
 如果对接平台的App中已经使用了讯飞SDK，请务必在此处传入讯飞给你们分配的AppID，并且将Pods中的iflyMSC.framework替换为你们从讯飞开放平台下载的iflyMSC.framework，以保证不会跟人教点读SDK中依赖的讯飞SDK产生冲突
 
 @param appID AppID
 */
+ (void)setiFlyMSCAppID:(NSString *)appID;


/**
 配置日志打印开关

 @param on 设置为true时将会打印日志
 */
+ (void)setLogSwitch:(BOOL)on;


/**
 配置震动触感反馈开关。

 @param on 设置为true时阅读器页面某些事件将会有震动反馈：仅iPhone 7及以上具有线性马达的手机有此功能
 */
+ (void)setShakeFeedbackSwitch:(BOOL)on;


/**
 对接平台 用户鉴权、绑定设备.
 对接平台 应在【APP启动】和【用户订单状态发生变化】时调用该方法
 
 @param userID 对接平台用户ID
 @param successBlock 网络请求成功后回调的block（包括当前用户购买过的书本和绑定的设备列表）
 @param failBlock 网络请求失败后回调的block
 */
+ (void)userAuthWithUserID:(NSString *)userID
              successBlock:(void(^)(id response))successBlock
                 failBlock:(void(^)(NSError *error))failBlock;


/**
 对接平台在用户退出登录后调用此方法，以清除SDK内部存储的用户相关信息。
 */
+ (void)userLogout;


/**
 解绑设备.
 一个用户只能在最多6台设备上登录，如果超过这个上限，可在其他已绑定的设备上调用该方法解绑指定的设备。
 注意：当前设备不能将自己解绑
 
 @param userID 用户ID
 @param deviceIDs 需要解绑的设备ID数组
 @param successBlock 网络请求结束后回调的block（errcode == 110 为解绑成功）
 @param failBlock 网络请求失败后回调的block
 */
+ (void)unbindDeviceWithUserID:(NSString *)userID
                     deviceIDs:(NSArray<NSString *> *)deviceIDs
                  successBlock:(void(^)(id response))successBlock
                     failBlock:(void(^)(NSError *error))failBlock;

/**
 当前设备的UUID.
 取值为：UIDevice.currentDevice.identifierForVendor.UUIDString。取值会存入keyChain，不会随App卸载而丢失。
 */
+ (NSString *)currentDeviceUUID;


/**
 获取教材列表. 此接口的必要参数AppKey已在内部处理，若在配置AppKey之前调用了该接口，将返回错误信息

 @param successBlock 网络请求结束后回调的block
 @param failBlock 网络请求失败后回调的block
 */
+ (void)getBookListWithSuccessBlock:(void(^)(PRBooklistModel *booklist))successBlock
                          failBlock:(void(^)(NSError *error))failBlock;

/**
 从本地缓存中获取教材列表：SDK初始化的时候，内部会自动调用「getBookListWithSuccessBlock:failBlock:」方法，并将请求结果缓存到沙盒
 此方法可能会返回nil
 
 @return 教材列表
 */
+ (NSArray<PRBookGradeModel *> *)getBooklist;

/**
 通过bookID获取book对象(异步。可能会进行网络请求)
 
 @param bookID 教材ID
 @param successBlock 网络请求结束后回调的block
 @param failBlock 网络请求失败后回调的block
 */
+ (void)getBookItemWithBookID:(NSString *)bookID
                 successBlock:(void(^)(PRBookModel *bookModel))successBlock
                    failBlock:(void(^)(NSError *error))failBlock;



/**
 通过bookID获取book对象(同步。不会进行网络请求)

 @param bookID 教材ID
 @return book模型
 */
+ (PRBookModel *)getBookItemWithBookID:(NSString *)bookID;


/**
 根据传入的bookID获取该教材的购买状态
 
 @param bookID bookID
 @return return 购买状态，详见PRBookAuth枚举
 */
+ (PRBookAuth)checkAuthStateWithBookID:(NSString *)bookID;

@end












