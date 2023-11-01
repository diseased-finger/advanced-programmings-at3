# Set Program Shit
cmake_minimum_required(VERSION 3.26)
project(advanced-programmings-at3)
set(CMAKE_CXX_STANDARD 17)

# Find all GTK4 packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM4 REQUIRED gtkmm-4.0)
include_directories(${GTKMM4_INCLUDE_DIRS})
link_directories(${GTKMM4_LIBRARY_DIRS})

# Add any compiler arguments and definitions from GTK4
add_definitions(${GTKMM4_CFLAGS_OTHER})

# Add my project to exe code
add_executable(advanced-programmings-at3 main.cpp
        views/ProgramWindow.cpp
        views/ProgramWindow.h
        routing/Router.cpp
        routing/Router.h
        routing/Route.h
        exceptions/NotFoundException.cpp
        exceptions/NotFoundException.h
        views/MainView.cpp
        views/MainView.h
)

# Then link GTKMM4 libraries
target_link_libraries(advanced-programmings-at3 ${GTKMM4_LIBRARIES})