//
//  PRStandardViewController.h
//  PDFReaderSDKDiandu
//
//  Created by 李沛倬 on 2018/4/10.
//  Copyright © 2018年 pep. All rights reserved.
//

#import "PRViewController.h"

@interface PRStandardViewController : PRViewController

/** 工具栏上的“设置”按钮展开之后的功能类型数组，元素为PRSettingItemType枚举类型 */
@property (nonatomic, strong) NSArray<NSNumber *> *settingItemTypes;

/**
 工具栏上的按钮被点击的时候将回调该block.
 其中，selected只有点读区域、翻译这两个个有开关概念的item会为true，表示开，其余按钮均只有false一种状态.
 */
@property (nonatomic, copy) void(^toolBarItemDidSelected)(PRToolBarItemType type, BOOL selected);



@end
