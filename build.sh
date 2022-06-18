mkdir -p deps/CTranslate2/build
cd deps/CTranslate2/build/
cmake .. -DWITH_MKL=OFF -DOPENMP_RUNTIME=NONE -DWITH_DNNL=ON
make -j4
sudo make install
cd ../../../

mkdir -p deps/Tokenizer/build
cd deps/Tokenizer/build/
cmake ..
make
sudo make install
cd ../../..

mkdir -p build
cd build
export LD_LIBRARY_PATH=/usr/local/lib/
g++ ../src/metaltranslate.cpp ../deps/CTranslate2/build/libctranslate2.so ../deps/Tokenizer/build/libOpenNMTTokenizer.so -o metaltranslate
cd ..
