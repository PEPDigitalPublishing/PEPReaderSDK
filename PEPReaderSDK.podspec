

Pod::Spec.new do |s|

  s.name         = 'PEPReaderSDK'

  s.version      = '2.0.3'

  s.summary      = '人教点读新SDK'

  s.author       = { 'PEP' => 'lipz@pep.com.cn' }

  s.platform     =  :ios, '9.0'

  s.homepage     = 'https://github.com/PEPDigitalPublishing/PEPReaderSDK'

  s.source       = { :git => 'https://github.com/PEPDigitalPublishing/PEPReaderSDK.git', :tag => s.version }

  s.vendored_frameworks = 'PEPReaderSDK.framework'

  s.resource = 'PDFReaderSDKDiandu.xcassets'

  s.frameworks   = 'MobileCoreServices', 'Security', 'CoreTelephony', 'AudioToolbox', 'CoreGraphics', 'QuartzCore', 'SystemConfiguration', 'AddressBook', 'CoreLocation'

  s.dependency 'YYModel'
  s.dependency 'Masonry'
  s.dependency 'SAMKeychain'

# SSZipArchive库为强依赖，此处经对接方项目特殊要求才注释掉
#  s.dependency 'SSZipArchive'

#   s.dependency 'PEPBigData', :git => 'https://github.com/PEPDigitalPublishing/PEPBigData.git'
#   s.dependency 'PEPNetworking', :git => 'https://github.com/PEPDigitalPublishing/PEPNetworking.git'

#  此处为讯飞语音SDK，可以不从该地址下载，但是必须保证项目中存在iflyMSC.framework
#  s.dependency 'PEPiFlyMSC', :git => 'https://github.com/PEPDigitalPublishing/PEPiFlyMSC.git'

#  此处为一起作业语音SDK，仅提供给一起作业使用，其他对接方请勿使用此SDK
#  s.dependency 'YIQISpeechEngine', :git => 'https://gitee.com/guxiong/YIQISpeechEngine.git'


  s.requires_arc = true

end



















