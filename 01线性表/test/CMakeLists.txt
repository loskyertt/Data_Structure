# for each "test/x.cpp", generate target "x"
message("CMakeLists.txt for test directory")

set(UTILS_LIBS
  utils
)

# 所有测试文件
file(GLOB_RECURSE TESTS ./*.cpp)

foreach(v ${TESTS})
  message("Processing: ${v}")
  file(RELATIVE_PATH relative_path ${PROJECT_SOURCE_DIR}/test ${v})
  string(REPLACE "/" "_" target_name ${relative_path})
  get_filename_component(target_name ${target_name} NAME_WE)

  add_executable(${target_name} ${v})

  # 头文件路径
  target_include_directories(${target_name} PUBLIC ${PROJECT_SOURCE_DIR}/include)

  # 链接所有 graph 库
  target_link_libraries(${target_name} PUBLIC ${UTILS_LIBS})
endforeach()


message("\n--------------------------------------------")
