cmake_minimum_required(VERSION 2.8)

# 自定义工具链
if(UNIX)
	set(CMAKE_TOOLCHAIN_FILE /opt/cheerp/share/cmake/Modules/CheerpToolchain.cmake)
else()
	# windows 未测试通关
	set(CMAKE_TOOLCHAIN_FILE C:/cheerp/share/cmake/Modules/CheerpToolchain.cmake)
	include_directories(
		C:/cheerp/include/client
		C:/cheerp/lib/clang/3.7.0/include
	)
endif()

project(html5cpp)

 
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/js)  

include_directories(
	${CMAKE_SOURCE_DIR}/html5cpp-lib/include
)

link_directories(
	${LIBRARY_OUTPUT_PATH}
)

# 调试版才需要以下这连续的几行
# 生成调试信息，生成可读格式的代码
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -cheerp-pretty-code")

add_subdirectory(html5cpp-lib)

add_subdirectory(demo/hello_world)

