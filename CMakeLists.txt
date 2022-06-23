cmake_minimum_required(VERSION 3.10)

project(MetalTranslate)

add_executable(metaltranslate src/MetalTranslate.cpp)

set(TARGET_H
    src/MetalTranslate.h)

add_subdirectory(deps/CTranslate2/)
target_link_libraries(metaltranslate ctranslate2)

add_subdirectory(deps/Tokenizer/)
target_link_libraries(metaltranslate OpenNMTTokenizer)
