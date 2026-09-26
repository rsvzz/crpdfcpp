cmake_minimum_required(VERSION 3.31)

project(crpdfcpp VERSION 1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DIR_MODEL_FILES_CPP 
"src/model/point.cpp"
"src/model/limit.cpp"
"src/model/base_ct.cpp"
"src/model/controls/create_pdf.cpp"
"src/model/controls/text.cpp"
"src/model/controls/line.cpp"
"src/wrapper/base_ct.cpp"
"src/wrapper/point.cpp"
"src/wrapper/limit.cpp"
"src/wrapper/text.cpp"
"src/wrapper/line.cpp"
"src/wrapper/create_pdf.cpp"
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CAIRO REQUIRED IMPORTED_TARGET cairo cairo-pdf)


add_library(${PROJECT_NAME}_lib ${DIR_MODEL_FILES_CPP})
set_target_properties(${PROJECT_NAME}_lib PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib PkgConfig::CAIRO)
#install(TARGETS ${PROJECT_NAME}_lib ${PROJECT_NAME} ARCHIVE DESTINATION lib RUNTIME DESTINATION bin)

install(TARGETS ${PROJECT_NAME}_lib ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    @ONLY
  )

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  )
endif()

#use cmake -G Ninja -B build # -DBUILD_SHARED_LIBS=on SHARED 