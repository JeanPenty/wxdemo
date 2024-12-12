# Install script for directory: E:/soui_demos/soui/third-part

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "E:/soui_demos/soui/output_64")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("E:/soui_demos/soui/build/third-part/zlib/cmake_install.cmake")
  include("E:/soui_demos/soui/build/third-part/png/cmake_install.cmake")
  include("E:/soui_demos/soui/build/third-part/lua-54/cmake_install.cmake")
  include("E:/soui_demos/soui/build/third-part/sqlite3/cmake_install.cmake")
  include("E:/soui_demos/soui/build/third-part/jsoncpp/cmake_install.cmake")
  include("E:/soui_demos/soui/build/third-part/gtest/cmake_install.cmake")
  include("E:/soui_demos/soui/build/third-part/mhook/cmake_install.cmake")
  include("E:/soui_demos/soui/build/third-part/smiley/cmake_install.cmake")
  include("E:/soui_demos/soui/build/third-part/7z/cmake_install.cmake")
  include("E:/soui_demos/soui/build/third-part/Scintilla/cmake_install.cmake")
  include("E:/soui_demos/soui/build/third-part/skia/cmake_install.cmake")
  include("E:/soui_demos/soui/build/third-part/richedit41/cmake_install.cmake")

endif()

