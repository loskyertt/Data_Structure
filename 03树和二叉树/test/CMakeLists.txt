# for each "test/x.cpp", generate target "x"
message("CMakeLists.txt for test directory")

# 所有 lib 下的实现文件
set(TREE_LIBS
  traverse
  tree_array
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

  target_link_libraries(${target_name} PRIVATE ${TREE_LIBS})
endforeach()


message("\n--------------------------------------------")
