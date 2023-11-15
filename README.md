# MetalTranslate
Customizable machine translation in C++

MetalTranslate downloads and runs a pretrained [CTranslate2](https://github.com/OpenNMT/CTranslate2) translation model and [SentencePiece](https://github.com/google/sentencepiece) tokenizer model to translate locally with C++.

## Quickstart
### Linux
Tested on Ubuntu 22.04

```
git clone --recursive https://github.com/argosopentech/MetalTranslate.git
cd MetalTranslate
./init
./build.sh
./build/metaltranslate "Hello world" en es


```

### Windows
The [as-shura/MetalTranslate fork](https://github.com/as-shura/MetalTranslate/) works on Windows.

## Usage
MetalTranslate is designed to be experimental and used as a template for doing machine translation in C++. You will need to modify the [source code](https://github.com/argosopentech/MetalTranslate/blob/main/src/MetalTranslate.cpp) for most use cases.
