cmake_minimum_required(VERSION 3.20)
project(projekty_github CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

set(REPO ${CMAKE_CURRENT_SOURCE_DIR})

# Biblioteka — implementacje + funkcje pomocnicze z testów/przykładów
file(GLOB LIB_SOURCES
        ${REPO}/src/*.cpp
        ${REPO}/tests/test_*.cpp
        ${REPO}/tests/testy_*.cpp
        ${REPO}/examples/przyklad_*.cpp
)

add_library(numerical_lib STATIC ${LIB_SOURCES})
target_include_directories(numerical_lib PUBLIC ${REPO}/include)

# Główny executable — wszystkie_testy ma main()
add_executable(wszystkie_testy ${REPO}/tests/wszystkie_testy.cpp)
target_link_libraries(wszystkie_testy PRIVATE numerical_lib)