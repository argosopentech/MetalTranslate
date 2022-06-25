# MetalTranslate
Customizable machine translation in C++

MetalTranslate downloads and runs a pretrained [CTranslate2](https://github.com/OpenNMT/CTranslate2) model to translate locally with C++.

## Quickstart
Tested on Ubuntu 22.04

```
git clone --recursive https://github.com/argosopentech/MetalTranslate.git
cd MetalTranslate
./setup.sh
./build.sh
./build/metaltranslate "Hello world, translating from MetalTranslate" en es


```

