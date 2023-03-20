

Pod::Spec.new do |s|

  s.name         = 'PEPReaderSDK'

  s.version      = '2.8.0'

  s.summary      = '人教点读新SDK'

  s.author       = { 'PEP' => 'han_zero@163.com' }

  s.platform     =  :ios, '10.0'

  s.homepage     = 'https://github.com/PEPDigitalPublishing/PEPReaderSDK'

  s.source       = { :git => 'https://github.com/PEPDigitalPublishing/PEPReaderSDK.git'}

  s.vendored_frameworks = 'PEPReaderSDK.framework'
  
  s.static_framework = true

  s.resource = 'PDFReaderSDKDiandu.xcassets'

  s.frameworks   = 'MobileCoreServices', 'Security', 'CoreTelephony', 'AudioToolbox', 'CoreGraphics', 'QuartzCore', 'SystemConfiguration', 'AddressBook', 'CoreLocation'

  s.dependency 'YYModel'
  s.dependency 'Masonry'
  s.dependency 'SAMKeychain'
  s.dependency 'iosMath'

# SSZipArchive库为强依赖，此处经对接方项目特殊要求才注释掉
#  s.dependency 'SSZipArchive'

#   s.dependency 'PEPBigData', :git => 'https://github.com/PEPDigitalPublishing/PEPBigData.git'
#   s.dependency 'PEPNetworking', :git => 'https://github.com/PEPDigitalPublishing/PEPNetworking.git'

   s.dependency 'PEPBigData', '>= 0.4.4'
   s.dependency 'PEPNetworking', '>= 0.4.1'
   s.dependency 'MZTimerLabel'
#  此处为讯飞语音SDK，可以不从该地址下载，但是必须保证项目中存在iflyMSC.framework
#  s.dependency 'PEPiFlyMSC', :git => 'https://github.com/PEPDigitalPublishing/PEPiFlyMSC.git'

#  此处为一起作业语音SDK，仅提供给一起作业使用，其他对接方请勿使用此SDK
#  s.dependency 'YIQISpeechEngine', :git => 'https://gitee.com/guxiong/YIQISpeechEngine.git'

   s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
   s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }


  s.requires_arc = true

end



















