cmake_minimum_required(VERSION 3.21)
project(Tanks_Game1)

set(CMAKE_CXX_STANDARD 14)




set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic")
set(SOURCE_FILES main.cpp )

add_executable(Tanks_Game1 main.cpp)

target_link_libraries(Tanks_Game1 ${CMAKE_EXE_LINKER_FLAGS})
