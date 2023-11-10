# PEPReaderSDK
人教点读SDK新仓库

### 更新记录

时间 | 版本号 | 更新内容
-|:-:|:-:
2021-11-01   | v2.7.2 | 修复已知bug
2022-09-26   | v2.7.3 | 修复已知bug
2023-03-20   | v2.8.1 | 修复已知bug
2023-04-27   | v2.8.2 | 修复已知bug
2023-05-09   | v2.8.3 | 评测模块优化,修复已知bug
2023-06-08   | v2.8.4 | 升级福昕SDK到7.4.0版本
2023-07-04   | v2.8.5 | 兼容性修复
2023-07-31   | v2.8.6 | 兼容性修复
2023-08-16   | v2.8.7 | 兼容性修复
2023-09-06   | v2.8.8 | 兼容性修复,PEPBigData升级到0.5.5版本
2023-10-07   | v2.8.9 | 修复iOS 17闪退问题
2023-11-03   | v2.8.10| 修复闪退问题
2023-11-10   | v2.8.11| 修复iOS 17闪退问题,优化评测模块录音体验
## 系统要求

由于依赖的福昕RDK已经升级到`iOS10.0`+，故人教点读SDK兼容的最低版本为`iOS 10.0`。


## 使用说明

由于人教点读SDK依赖的福昕RDK文件较大，无法上传GitHub，可以[点击这里](https://rjszgsres.mypep.cn/rjdd/iOSFoxitRDK/FoxitRDK.framework.zip)下载（目前已是7.4版本），然后将解压出的`FoxitRDK.framework`导入到项目中。


### 接入

#### 方式一、Cocoapods

在`podfile`中添加如下代码，然后`pod install`:

```
pod 'PEPNetworking', :git => 'https://github.com/PEPDigitalPublishing/PEPNetworking.git'

pod 'PEPBigData', :git => 'https://github.com/PEPDigitalPublishing/PEPBigData.git'

pod 'PEPReaderSDK', :git => 'https://github.com/PEPDigitalPublishing/PEPReaderSDK.git'

# 讯飞语音SDK
pod 'PEPiFlyMSC', :git => 'https://github.com/PEPDigitalPublishing/PEPiFlyMSC.git'

pod 'SSZipArchive'

pod 'iosMath'

```


##### 指定版本号

`podfile`中可以通过如下方式指定版本号：

```
pod 'PEPReaderSDK', { :git => 'https://github.com/PEPDigitalPublishing/PEPReaderSDK.git', :tag => '2.0.0' }
```




#### 方式二、手动接入

1. 从[Releases](https://github.com/PEPDigitalPublishing/PEPReaderSDK/releases)中下载指定版本，然后将其中的`PEPReaderSDK.framework`和`PDFReaderSDKDiandu.xcassets`导入项目中。
2. 查看[PEPReaderSDK.podspec](https://github.com/PEPDigitalPublishing/PEPReaderSDK/blob/master/PEPReaderSDK.podspec)中声明的依赖库，并保证这些依赖库也同样导入到项目中



## 接口说明

详见`PEPReaderSDK.framework`Headers中代码注释。



## Demo

[这里](https://github.com/PEPDigitalPublishing/PDFReaderSample)是Demo地址。



## 更新说明

请参考：[更新日志](https://github.com/PEPDigitalPublishing/PEPReaderSDK/wiki/%E6%9B%B4%E6%96%B0%E6%97%A5%E5%BF%97)

如果想及时收到人教点读SDK更新的通知，可以点击页面右上角的`Watch`，然后在出现的下拉列表中勾选`Releases only`。这样SDK每发布一个新的release版本，你将会收到GitHub发送的邮件。

![Github_Watch](https://github.com/PEPDigitalPublishing/PEPImageHost/raw/master/PEPReaderSDK/github_watch.png)


## FAQ

#### 1. Include of non-modular header inside framework module xxxxxx

在项目的`Build Setting`中搜索“allow non-modular”，将出现的栏目中的“No”改为“Yes”

#### 2. 福昕RDK的导入位置

`FoxitRDK.framework`是动态库，应导入到`Embedded Binaries`中，而不是`Linked Frameworks And Libraries`中

#### 3. App打包上传App Store时报错(ERROR ITMS-90080、90087、90209、90125)

由于`FoxitRDK.framework`合并了真机和模拟器编译出的二进制文件，即在真机和模拟器上都能运行，且是动态库，以嵌入的方式（Embedded Binaries）导入项目的，故而Xcode在打包时无法自动去除x86_64和i386的二进制文件，需要增加脚本。

解决方案: `TARGETS` -> `Build Phases` -> 点击左上角加号选择`New Run Script Phase`-> 然后复制粘贴下面代码:

```
APP_PATH="${TARGET_BUILD_DIR}/${WRAPPER_NAME}"

# This script loops through the frameworks embedded in the application and

# removes unused architectures.

find "$APP_PATH" -name '*.framework' -type d | while read -r FRAMEWORK

do

FRAMEWORK_EXECUTABLE_NAME=$(defaults read "$FRAMEWORK/Info.plist" CFBundleExecutable)

FRAMEWORK_EXECUTABLE_PATH="$FRAMEWORK/$FRAMEWORK_EXECUTABLE_NAME"

echo "Executable is $FRAMEWORK_EXECUTABLE_PATH"

EXTRACTED_ARCHS=()

for ARCH in $ARCHS

do

echo "Extracting $ARCH from $FRAMEWORK_EXECUTABLE_NAME"

lipo -extract "$ARCH" "$FRAMEWORK_EXECUTABLE_PATH" -o "$FRAMEWORK_EXECUTABLE_PATH-$ARCH"

EXTRACTED_ARCHS+=("$FRAMEWORK_EXECUTABLE_PATH-$ARCH")

done

echo "Merging extracted architectures: ${ARCHS}"

lipo -o "$FRAMEWORK_EXECUTABLE_PATH-merged" -create "${EXTRACTED_ARCHS[@]}"

rm "${EXTRACTED_ARCHS[@]}"

echo "Replacing original executable with thinned version"

rm "$FRAMEWORK_EXECUTABLE_PATH"

mv "$FRAMEWORK_EXECUTABLE_PATH-merged" "$FRAMEWORK_EXECUTABLE_PATH"

done

```

操作如下图：

![Run Script](https://github.com/PEPDigitalPublishing/PEPImageHost/raw/master/PEPReaderSDK/run_script.png)

#### 4. 新版Xcode 12编译时报错"/Users/xxx.xcodeproj Building for iOS, but the linked and embedded framework 'FoxitRDK.framework' was built for iOS + iOS Simulator."

操作如图：
![Run Script](https://github.com/PEPDigitalPublishing/PEPImageHost/raw/master/PEPReaderSDK/Validate_Workspace.jpg)


#### 5. 正在完善中...

对接中出现的任何问题，欢迎随时反馈（hanhf@pep.com.cn），或者提[Issues](https://github.com/PEPDigitalPublishing/PEPReaderSDK/issues).


