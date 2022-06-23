# Download M2M-100 model
wget -P models/ https://cdn.argosopentech.io/translate-fairseq_m2m_100_418M.argosmodel
unzip models/translate-fairseq_m2m_100_418M.argosmodel -d models/

# Setup CTranslate2
git clone --recursive https://github.com/OpenNMT/CTranslate2.git deps/CTranslate2/
sudo apt-get install -y cmake
sudo apt-get install -y libdnnl-dev

# Setup OpenNMT Tokenizer
git clone --recursive https://github.com/OpenNMT/Tokenizer.git deps/Tokenizer
sudo apt-get install -y libicu-dev
