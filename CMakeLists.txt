cmake_minimum_required(VERSION 3.31)

project(crpdfcpp VERSION 1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Add *.c .cpp for all dir
#subdirs(src/model_c)
#add_subdirectory(src/model_c)
set(DIR_MODEL_FILES_CPP 
"src/model/point.cpp"
"src/model/limit.cpp"
"src/model/base_ct.cpp"
#"src/model/controls/draw_pdf.cpp" #dont need only .hpp
"src/model/controls/create_pdf.cpp"
"src/model/controls/text.cpp"
"src/model/wrapper/point_wrapper.cpp"
"src/model/wrapper/limit_wrapper.cpp"
"src/model/wrapper/text_wrapper.cpp"
"src/model/wrapper/base_ct_wrapper.cpp"
"src/model/wrapper/create_pdf_wrapper.cpp"
)

#C native
#set(DIR_MODEL_FILES_C "src/model/ext/crpdf_c.c")

find_package(PkgConfig REQUIRED)
pkg_check_modules(CAIRO REQUIRED IMPORTED_TARGET cairo cairo-pdf)

# OBJECTS FIRST
#add_library(${PROJECT_NAME}_objects OBJECT ${DIR_MODEL_FILES_CPP})
#PIC STATIC WORK.
#set_property(TARGET ${PROJECT_NAME}_objects PROPERTY POSITION_INDEPENDENT_CODE ON)
#STATIC
#add_library(${PROJECT_NAME}_static STATIC $<TARGET_OBJECTS:${PROJECT_NAME}_objects>)
#set_target_properties(${PROJECT_NAME}_static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

#add_library(${PROJECT_NAME}_shared SHARED $<TARGET_OBJECTS:${PROJECT_NAME}_objects>)
#set_target_properties(${PROJECT_NAME}_shared PROPERTIES
#    OUTPUT_NAME ${PROJECT_NAME}
#)

add_library(${PROJECT_NAME}_lib ${DIR_MODEL_FILES_CPP})
set_target_properties(${PROJECT_NAME}_lib PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# here C native
#add_library(${PROJECT_NAME}_lib_c ${DIR_MODEL_FILES_C})
#set_target_properties(${PROJECT_NAME}_lib_c PROPERTIES OUTPUT_NAME ${PROJECT_NAME}_c)
#target_include_directories(${PROJECT_NAME}_lib_c PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

#*** exe
add_executable(${PROJECT_NAME} src/main.cpp)
# En el CMakeLists.txt donde creas o importas crpdfcpp:

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib PkgConfig::CAIRO)
#***

#install name lib_ name bin automatic
install(TARGETS ${PROJECT_NAME}_lib ${PROJECT_NAME} ARCHIVE DESTINATION lib RUNTIME DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)


# Debe ir al final del CMakeLists.txt
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