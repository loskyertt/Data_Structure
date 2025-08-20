# for each "lib/x.cpp", generate shared library or static library
message("CMakeLists.txt for lib directory")

file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS *.cpp)

foreach(v ${LIB_SOURCES})
    message("Processing: ${v}")
    file(RELATIVE_PATH relative_path ${PROJECT_SOURCE_DIR}/lib ${v})
    string(REPLACE "/" "_" target_name ${relative_path})
    get_filename_component(target_name ${target_name} NAME_WE)
    message("Relative path: ${relative_path}")
    message("Target name: ${target_name}")

    if(NOT target_name)
        message(WARNING "Skipping invalid target name for file: ${v}")
        continue()
    endif()

    # 生成动态库
    add_library(${target_name} SHARED ${v})

    target_include_directories(${target_name} PUBLIC ${PROJECT_SOURCE_DIR}/include)
endforeach()

message("\n--------------------------------------------")
