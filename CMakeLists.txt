cmake_minimum_required(VERSION 3.16)

project(QtEasy VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_SHARED_LIBS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(PROJECT_SOURCES
    src/QtEasy/TitlesBars/QTitleBar.cpp
    src/QtEasy/TitlesBars/QTitleBar.hpp
    src/QtEasy/TitlesBars/QTitleBarEmpty.cpp
    src/QtEasy/TitlesBars/QTitleBarEmpty.hpp
    src/QtEasy/TitlesBars/QTitleBarTempInfo.cpp
    src/QtEasy/TitlesBars/QTitleBarTempInfo.hpp
    src/QtEasy/TitlesBars/QTitleBarFilesOperations.cpp
    src/QtEasy/TitlesBars/QTitleBarFilesOperations.hpp
    src/QtEasy/TitlesBars/QTitleBarTempInfoFilesOperations.cpp
    src/QtEasy/TitlesBars/QTitleBarTempInfoFilesOperations.hpp

    
    src/QtEasy/Widgets/QLabelTempInfo.cpp
    src/QtEasy/Widgets/QLabelTempInfo.hpp
    src/QtEasy/Widgets/QSystemsButtons.cpp
    src/QtEasy/Widgets/QSystemsButtons.hpp
    src/QtEasy/Widgets/QTempInfo.cpp
    src/QtEasy/Widgets/QTempInfo.hpp
    src/QtEasy/Widgets/QFileOperationButton.cpp
    src/QtEasy/Widgets/QFileOperationButton.hpp
    src/QtEasy/Widgets/QOpenButton.cpp
    src/QtEasy/Widgets/QOpenButton.hpp
    src/QtEasy/Widgets/QSaveButton.cpp
    src/QtEasy/Widgets/QSaveButton.hpp
    src/QtEasy/Widgets/QSaveAsButton.cpp
    src/QtEasy/Widgets/QSaveAsButton.hpp
)

add_library(QtEasy SHARED ${PROJECT_SOURCES})

target_include_directories(QtEasy PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

target_link_libraries(QtEasy PUBLIC 
    Qt6::Core
    Qt6::Widgets
)

target_compile_definitions(QtEasy PRIVATE QTEASY_LIBRARY)

include(GNUInstallDirs)

install(TARGETS QtEasy
    EXPORT QtEasyTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY src/QtEasy
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hpp"
)
