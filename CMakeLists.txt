cmake_minimum_required(VERSION 3.10)

project(MetalTranslate)

add_executable(metaltranslate src/metaltranslate.cpp)

add_subdirectory(deps/CTranslate2/)

target_link_libraries(metaltranslate ctranslate2)

