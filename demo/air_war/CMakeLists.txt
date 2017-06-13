
# debug
# 生成sourcemap
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -cheerp-sourcemap=air_war.js.map")
# 切除sourcemap中源文件路径前缀
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -cheerp-sourcemap-prefix=/vagrant/cheerp/hello_world")

file(GLOB_RECURSE SRC src/*.h src/*.cpp)
add_executable(air_war ${SRC})
target_link_libraries(air_war html5cpp)
