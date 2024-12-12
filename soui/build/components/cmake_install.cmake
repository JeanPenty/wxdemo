# Install script for directory: E:/soui_demos/soui/components

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/components" TYPE FILE FILES "E:/soui_demos/soui/components/com-cfg.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/components" TYPE FILE FILES "E:/soui_demos/soui/components/commask.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/components" TYPE FILE FILES "E:/soui_demos/soui/components/commgr2.h")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("E:/soui_demos/soui/build/components/imgdecoder-png/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/imgdecoder-stb/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/translator/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/log4z/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/TaskLoop/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/imgdecoder-wic/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/imgdecoder-gdip/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/resprovider-7zip/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/render-d2d/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/ScriptModule-LUA/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/httpclient/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/SIpcObject/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/resprovider-zip/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/render-gdi/cmake_install.cmake")
  include("E:/soui_demos/soui/build/components/render-skia/cmake_install.cmake")

endif()

