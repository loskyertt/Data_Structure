# for each "src/x.cpp", generate target "x"
message("CMakeLists.txt for src directory")

# 所有 lib 下的实现文件
file(GLOB LIB_SOURCES ${PROJECT_SOURCE_DIR}/lib/*.cpp)

# 所有测试文件
file(GLOB_RECURSE SRCS ./*.cpp)

foreach(v ${SRCS})
  message("Processing: ${v}")
  file(RELATIVE_PATH relative_path ${PROJECT_SOURCE_DIR}/src ${v})
  string(REPLACE "/" "_" target_name ${relative_path})
  get_filename_component(target_name ${target_name} NAME_WE)

  # 把 lib 源文件也加进来
  add_executable(${target_name} ${v} ${LIB_SOURCES})

  # 头文件路径
  target_include_directories(${target_name} PUBLIC ${PROJECT_SOURCE_DIR}/include)
endforeach()


message("\n--------------------------------------------")
