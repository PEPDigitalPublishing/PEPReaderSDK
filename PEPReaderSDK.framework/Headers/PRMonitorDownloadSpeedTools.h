//
//  PRMonitorDownloadSpeedTools.h
//  PDFReaderSDK
//
//  Created by 韩帅 on 2021/12/20.
//  Copyright © 2021 pep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface PRMonitorDownloadSpeedTools : NSObject

@property(nonatomic,strong)NSDate *date;/**<  时间*/
@property(nonatomic,assign)CGFloat avgSpeed;/**<  平均速度*/
@property(nonatomic,assign)NSString *speedStr;/**<  */

@property(nonatomic,assign)long long currentUnitCount;/**<  当前存贮的数据量*/

@end

NS_ASSUME_NONNULL_END
