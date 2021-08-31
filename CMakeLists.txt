cmake_minimum_required(VERSION 3.11)
project(libra LANGUAGES CXX)



############### compiler ###############
##### standard #####
set(CMAKE_CXX_STANDARD 17) # STDC++ 17
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

##### build type #####
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#   # debug build
#   # add_definitions(-Werror)
# elseif(CMAKE_BUILD_TYPE STRQUAL "Test")
#   # test build
# endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

##### compiler setting #####
add_definitions(-Wall -Wextra)
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # using Clang
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 8.1)
    message(FATAL_ERROR "GCC VERSION MUST GREATER EQUAL THAN 8.1")
  endif(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 8.1)
endif()



############### project libra ###############
file(GLOB_RECURSE CxxFiles
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/thrift/*.cpp
  )
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cc ${CxxFiles})
target_include_directories(${PROJECT_NAME} PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/thrift
  )



############### link library ###############
# find_package(CLI11 REQUIRED)
# find_package(spdlog REQUIRED)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # using Clang
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.1)
    target_link_libraries(${PROJECT_NAME} PRIVATE
      stdc++fs
      )
  endif(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.1)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
  amqpcpp
  event
  pthread
  seccomp
  thrift
  uuid
  )

# target_link_libraries(${PROJECT_NAME} PRIVATE
#   CLI11::CLI11
#   spdlog::spdlog)

# find_package(Boost 1.66 REQUIRED COMPONENTS system)
# target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})
