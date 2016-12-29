cmake_minimum_required(VERSION 3.0)
project(clockys)

set (CMAKE_CXX_STANDARD 11)
# standalone build
if (CMAKE_CURRENT_LIST_DIR STREQUAL CMAKE_SOURCE_DIR)
	option (WITH_GLOG "build with glog" ON)
	if (WITH_GLOG)
		set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake_modules/")
		find_package(Glog REQUIRED)
	endif()
endif ()

option (WITH_EXAMPLE "build with example" OFF)

add_library(${PROJECT_NAME} ./src/clockys.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
	$<INSTALL_INTERFACE:include>)

if (GLOG_FOUND)
	target_include_directories(${PROJECT_NAME} PUBLIC
		${GLOG_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME} PUBLIC
		${GLOG_LIBRARY})
	target_compile_definitions(${PROJECT_NAME} PRIVATE
		USE_GLOG)
endif ()

if (WITH_EXAMPLE)
	add_executable(test_clock ./src/test.cpp)
	target_link_libraries(test_clock
		${PROJECT_NAME}
		)
endif()

install(TARGETS ${PROJECT_NAME}
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin)
install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/clockys
	DESTINATION include)
