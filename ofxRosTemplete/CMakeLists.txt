cmake_minimum_required(VERSION 3.0.2)
project(ofxRosTemplete)

# add_compile_options(-std=c++11)

find_package(catkin REQUIRED)
add_custom_target(make_of ALL COMMAND "make" "-j3"
                    WORKING_DIRECTORY ../../src/ofxRosTemplete/of/)
add_custom_target(make_of_wo ALL COMMAND "make" "-j3"
                    WORKING_DIRECTORY ../../src/ofxRosTemplete/of_wo_ros/)
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

# generate_messages(
#   DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
# )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ros_pkg_template
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

include_directories(
# include
# ${catkin_INCLUDE_DIRS}
)

# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/ros_pkg_template.cpp
# )

# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

# add_executable(${PROJECT_NAME}_node src/ros_pkg_template_node.cpp)

## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )
