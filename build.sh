cd deps/CTranslate2/build/
cmake .. -DWITH_MKL=OFF -DOPENMP_RUNTIME=NONE -DWITH_DNNL=ON
make -j4
cd ../../../

cd deps/Tokenizer/build/
cmake ..
make
cd ../../..

mkdir -p build
cd build
export LD_LIBRARY_PATH=/usr/local/lib/
g++ ../src/metaltranslate.cpp ../deps/CTranslate2/build/libctranslate2.so -o metaltranslate
cd ..
