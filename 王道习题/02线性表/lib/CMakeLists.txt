# for each "lib/x.cpp", generate shared library or static library
message("CMakeLists.txt for lib directory")

add_library(utils SHARED
    utils.cpp
)

target_include_directories(utils PUBLIC ${PROJECT_SOURCE_DIR}/include)

message("\n--------------------------------------------")
