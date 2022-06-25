cmake_minimum_required(VERSION 3.10)

project(MetalTranslate)

add_executable(metaltranslate src/main.cpp)

set(TARGET_H
    src/MetalTranslate.h
    src/MetalTranslateConfig.h)

target_sources(metaltranslate PRIVATE src/MetalTranslate.cpp)

add_subdirectory(third_party/CTranslate2/)
target_link_libraries(metaltranslate ctranslate2)

add_subdirectory(third_party/Tokenizer/)
target_link_libraries(metaltranslate OpenNMTTokenizer)
