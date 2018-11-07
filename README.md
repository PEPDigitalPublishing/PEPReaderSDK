# PEPReaderSDK
人教点读SDK新仓库


## 系统要求

由于依赖的福昕SDK已经升级到iOS9.0+，故人教点读SDK兼容的最低版本为iOS 9.0。


## 使用说明

由于人教点读SDK依赖的福昕SDK文件较大，无法上传GitHub，故而需要联系我们单独发送文件。


### 接入

#### 一、Cocoapods

在`podfile`中添加如下代码，然后`pod install`:

```
pod 'PEPReaderSDK', :git => 'https://github.com/PEPDigitalPublishing/PEPReaderSDK.git'

pod 'PEPNetworking', :git => 'https://github.com/PEPDigitalPublishing/PEPNetworking.git'

pod 'PEPBigData', :git => 'https://github.com/PEPDigitalPublishing/PEPBigData.git'

pod 'SSZipArchive'

```


##### 指定版本号

`podfile`中可以通过如下方式指定版本号：

```
pod 'PEPReaderSDK', { :git => 'https://github.com/PEPDigitalPublishing/PEPReaderSDK.git', :tag => '2.0.0' }
```




#### 二、手动接入

1. 从[Releases](https://github.com/PEPDigitalPublishing/PEPReaderSDK/releases)中下载指定版本，然后将其中的`PEPReaderSDK.framework`和`PDFReaderSDKDiandu.xcassets`导入项目中。
2. 查看[PEPReaderSDK.podspec](https://github.com/PEPDigitalPublishing/PEPReaderSDK/blob/master/PEPReaderSDK.podspec)中声明的依赖库，并保证这些依赖库也同样导入到项目中



## 接口说明

详见`PEPReaderSDK.framework`Headers中代码注释。



## Demo

[这里](https://github.com/PEPDigitalPublishing/PDFReaderSample)是Demo地址。



## 更新日志

~~请参考：[更新说明]()~~

*暂无*






## FAQ

#### 1. Include of non-modular header inside framework module xxxxxx

在项目的`Build Setting`中搜索“allow non-modular”，将出现的栏目中的“No”改为“Yes”

#### 2. 福昕SDK的导入位置

FoxitRDK.framework应导入到`Embedded Binaries`中，而不是`Linked Frameworks And Libraries`中

#### 3. App打包上传App Store时报错

由于福昕SDK合并了真机和模拟器的二进制文件，即在真机和模拟器上都能运行，且是以嵌入的方式（Embedded Binaries）导入项目的，故而Xcode在打包时无法自动去除x86_64和i386的二进制文件，需要增加脚本。

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

操作如下如：

![Run Script](https://github.com/PEPDigitalPublishing/PEPImageHost/raw/master/PEPReaderSDK/run_script.png)


#### 4. 正在完善中...


