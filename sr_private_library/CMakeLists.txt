cmake_minimum_required(VERSION 2.8.3)
project(sr_private_library)

find_package(catkin REQUIRED roscpp sr_public_library)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS sr_public_library
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS})

add_library(sr_private_library
  src/private_class.cpp
  src/string_utils.cpp
)

target_link_libraries(sr_private_library
  ${catkin_LIBRARIES}
)

######################################
## Inject library to public package ##
######################################

add_custom_command(TARGET sr_private_library POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libsr_private_library.so"
        "${sr_public_library_SOURCE_DIR}/lib/libsr_private_library.so")

#############
## Install ##
#############

install(TARGETS sr_private_library
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

