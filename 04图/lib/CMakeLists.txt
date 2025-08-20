# for each "lib/x.cpp", generate shared library or static library
message("CMakeLists.txt for lib directory")

# 邻接表
add_library(graph_linkedlist SHARED
    graphAdjLinkedList.cpp
    graphAdjLinkedListD.cpp
)

target_include_directories(graph_linkedlist PUBLIC ${PROJECT_SOURCE_DIR}/include)

# 邻接矩阵
add_library(graph_mat SHARED
    graphAdjMat.cpp
    graphAdjMatD.cpp
)

target_include_directories(graph_mat PUBLIC ${PROJECT_SOURCE_DIR}/include)


message("\n--------------------------------------------")
