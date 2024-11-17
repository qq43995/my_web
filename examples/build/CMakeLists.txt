cmake_minimum_required(VERSION 3.10)

project(ClientExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# 查找 zlib
find_package(ZLIB REQUIRED)
include_directories(${ZLIB_INCLUDE_DIRS})

# 查找 OpenSSL
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

# 设置 uWebSockets 的路径
set(uWebSockets_DIR /home/ubuntu/uWebSockets/)
include_directories(${uWebSockets_DIR}/src)
link_directories(${uSockets_DIR})

# 添加源文件
add_executable(Client ../Client.cpp)

# 链接库
target_link_libraries(Client PRIVATE ${OPENSSL_LIBRARIES} ${ZLIB_LIBRARIES} ${uWebSockets_DIR}/uSockets/uSockets.a)
