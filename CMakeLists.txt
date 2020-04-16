cmake_minimum_required(VERSION 3.5)

project(QtXQueryTester LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Xml XmlPatterns REQUIRED)

if(ANDROID)
  add_library(QtXQueryTester SHARED
    main.cpp
    qtquerytesterwindow.cpp
    qtquerytesterwindow.h
    qtquerytesterwindow.ui
  )
else()
  add_executable(QtXQueryTester
    main.cpp
    qtquerytesterwindow.cpp
    qtquerytesterwindow.h
    qtquerytesterwindow.ui
  )
endif()

target_link_libraries(QtXQueryTester
    PRIVATE
    Qt5::Widgets
    Qt5::Xml
    Qt5::XmlPatterns)
