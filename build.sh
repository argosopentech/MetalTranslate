mkdir -p build
cd build
cmake .. -DWITH_MKL=OFF -DOPENMP_RUNTIME=NONE -DWITH_DNNL=ON
make

