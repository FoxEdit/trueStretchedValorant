cmake_minimum_required(VERSION 3.27.0)
project(GCCsandbox VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

# add_compile_options(-Wall)

set(LIBMEM_LIBRARY "C:/repos/libmem/lib/libmem.lib")
set(LIBMEM_INCLUDE_DIR "C:/repos/libmem/include")

include_directories(GCCsandbox
       ${LIBMEM_INCLUDE_DIR}
)

add_executable(GCCsandbox main.cpp)

target_link_libraries(GCCsandbox ${LIBMEM_LIBRARY})

