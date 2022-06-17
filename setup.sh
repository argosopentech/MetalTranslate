# Setup CTranslate2
git clone --recursive https://github.com/OpenNMT/CTranslate2.git deps/CTranslate2/
sudo apt-get install -y cmake
sudo apt-get install -y libdnnl-dev
mkdir deps/CTranslate2/build

# Setup OpenNMT Tokenizer
git clone --recursive https://github.com/OpenNMT/Tokenizer.git deps/Tokenizer
sudo apt-get install -y libicu-dev
mkdir deps/Tokenizer/build
