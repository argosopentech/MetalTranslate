cmake_minimum_required(VERSION 3.10)

project(MetalTranslate)

include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(CTranslate2
    GIT_REPOSITORY https://github.com/OpenNMT/CTranslate2
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} -DWITH_MKL=OFF -DWITH_DNNL=ON
)

ExternalProject_Add(Tokenizer
    GIT_REPOSITORY https://github.com/OpenNMT/Tokenizer
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

add_executable(metaltranslate src/main.cpp)

set(TARGET_H
    src/MetalTranslate.h
    src/MetalTranslateConfig.h)

target_sources(metaltranslate PRIVATE src/MetalTranslate.cpp)

#add_subdirectory(third_party/CTranslate2/)
target_link_libraries(metaltranslate ctranslate2)

##add_subdirectory(third_party/Tokenizer/)
target_link_libraries(metaltranslate OpenNMTTokenizer)

#target_link_libraries(metaltranslate cpu_features)

