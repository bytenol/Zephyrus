cmake_minimum_required(VERSION 3.19)

project(Zephyrus)

option(ENGINE_WEB "Enable web(Emscripten) platform" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

include_directories(external/include)
include_directories(zephyrus/include)

add_library(zephyrus STATIC
        zephyrus/src/Engine.cpp
        zephyrus/src/Log.cpp
        zephyrus/src/Node.cpp
        zephyrus/src/Vec2.cpp
        zephyrus/src/Platform.cpp
)

if(EMSCRIPTEN)
    if(NOT CMAKE_CXX_COMPILER)
        set(CMAKE_CXX_COMPILER em++)
    endif()
    add_executable(zeph_lib zephyrus/src/WebCanvas.cpp "bindings/engine_c_api.h" "bindings/engine_c_api.cpp")

    set(EXPORTED_RUNTIME_METHODS "[\
        ccall, cwrap
    ]")

    target_link_libraries(zeph_lib PRIVATE zephyrus)
    #    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s EXPORTED_FUNCTIONS='[_main, _sum]'")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s EXPORTED_RUNTIME_METHODS='[ccall, cwrap]'")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --bind -03 -s USE_WEBGL2=1 -s FULL_ES3=1 -s MODULARIZE=1 -s EXPORT_NAME='Zephyrus'")
    #    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file ../assets")

else ()
    find_package(X11 REQUIRED)
    find_package(PkgConfig REQUIRED)

    pkg_check_modules(EGL REQUIRED egl)
    pkg_check_modules(GLES2 REQUIRED glesv2)
    pkg_check_modules(GLES REQUIRED glesv2)

    add_executable(gles3 zephyrus/src/NativeWindow.cpp native/main.cpp)
    target_include_directories(gles3 PRIVATE ${X11_INCLUDE_DIR} ${EGL_INCLUDE_DIRS} ${GLES_INCLUDE_DIRS})
    target_link_libraries(gles3 PRIVATE X11::X11 ${EGL_LIBRARIES} ${GLES_LIBRARIES} zephyrus)

endif()