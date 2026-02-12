cmake_minimum_required(VERSION 3.10)
project(AddressBook)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 源文件
set(SOURCES
    main.cpp
    Contact.cpp
    AddressBook.cpp
)

# 头文件
set(HEADERS
    Contact.h
    AddressBook.h
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
