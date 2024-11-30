cmake_minimum_required(VERSION 3.10)
project(Matrix CXX)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES 
	src/main.cpp
	src/matrix.cpp
	src/square_matrix.cpp
)
set(HEADERS
	include/matrix.h
	include/square_matrix.h
)

include_directories("include/")


add_executable(Matrix 
	${SOURCES}
	${HEDERS}
)
