# PEPReaderSDK
人教点读SDK新仓库



## 使用说明

由于人教点读SDK依赖的福昕SDK文件较大，无法上传GitHub，故而需要联系我们单独发送文件。


### 接入

#### Cocoapods

在`podfile`中添加如下代码，然后`pod install`:

```Objective-C
pod 'PEPReaderSDK', :git => 'https://github.com/PEPDigitalPublishing/PEPReaderSDK.git'

pod 'PEPNetworking', :git => 'https://github.com/PEPDigitalPublishing/PEPNetworking.git'

pod 'PEPBigData', :git => 'https://github.com/PEPDigitalPublishing/PEPBigData.git'

pod 'SSZipArchive'

```


**指定版本号**

`podfile`中可以通过如下方式指定版本号：

```
pod 'PEPReaderSDK', { :git => 'https://github.com/PEPDigitalPublishing/PEPReaderSDK.git', :tag => '2.0.0' }
```




#### 手动接入

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

#### 2. 正在完善中...


