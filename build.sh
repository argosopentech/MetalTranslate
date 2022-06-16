cd deps/CTranslate2/build/
cmake .. -DWITH_MKL=OFF -DOPENMP_RUNTIME=NONE
make -j4
