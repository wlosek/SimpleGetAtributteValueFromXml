cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(SimpleGetAttributeValueFromXml)
add_executable(${PROJECT_NAME} "src/main.cpp")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)
