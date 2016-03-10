cmake_minimum_required(VERSION 3.3)
project(tes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    tes/main.cpp
    tes/window.cpp
    tes/window.h
    tes.xcodeproj/project.xcworkspace/xcuserdata/xiaoweiwu.xcuserdatad/UserInterfaceState.xcuserstate
    tes.xcodeproj/project.xcworkspace/contents.xcworkspacedata
    tes.xcodeproj/xcuserdata/xiaoweiwu.xcuserdatad/xcdebugger/Breakpoints_v2.xcbkptlist
    tes.xcodeproj/xcuserdata/xiaoweiwu.xcuserdatad/xcschemes/tes.xcscheme
    tes.xcodeproj/xcuserdata/xiaoweiwu.xcuserdatad/xcschemes/xcschememanagement.plist
    tes.xcodeproj/project.pbxproj)

add_executable(tes ${SOURCE_FILES})