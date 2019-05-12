Pod::Spec.new do |s|
  s.name         = "vpn"
  s.version      = "1.0.0"
  s.summary      = "深信服vpn插件"
  s.homepage     = "https://github.com/hsxhsx/CJschintaVpn"
  s.license = { :type => "MIT", :file => "LICENSE" }
  s.author             = { "HuSHuangxi" => "2523121796@qq.com" }
  s.source       = { :git =>    "https://github.com/hsxhsx/CJschintaVpn.git", :tag => "#{s.version}" }
  s.requires_arc = true
  s.ios.deployment_target = "9.0"
  s.source_files  = "vpn/vpn/*.{h,m}"
end