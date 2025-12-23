cmake_minimum_required(VERSION 3.19)

project(Zephyrus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

include_directories(external/include)

FILE(GLOB SRC_CONTENTS "engine/src/*.cpp")

add_library(zephyrus STATIC ${SRC_CONTENTS})

if(EMSCRIPTEN)
    if(NOT CMAKE_CXX_COMPILER)
        set(CMAKE_CXX_COMPILER em++)
    endif()
else ()
    find_package(X11 REQUIRED)
    find_package(PkgConfig REQUIRED)

    pkg_check_modules(EGL REQUIRED egl)
    pkg_check_modules(GLES2 REQUIRED glesv2)
    pkg_check_modules(GLES REQUIRED glesv2)

    add_executable(gles3 native/main.cpp)
    target_include_directories(gles3 PRIVATE ${X11_INCLUDE_DIR} ${EGL_INCLUDE_DIRS} ${GLES_INCLUDE_DIRS})
    target_link_libraries(gles3 PRIVATE X11::X11 ${EGL_LIBRARIES} ${GLES_LIBRARIES} )

    message(STATUS "EGL libs: ${EGL_LIBRARIES}")
    message(STATUS "GLES libs: ${GLES_LIBRARIES}")

endif()


add_executable(zeph_lib "bindings/engine_c_api.h" "bindings/engine_c_api.cpp")

set(EXPORTED_RUNTIME_METHODS "[\
    ccall, cwrap
]")

if(EMSCRIPTEN)
    target_link_libraries(zeph_lib PRIVATE zephyrus)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s EXPORTED_FUNCTIONS='[_main, _sum]'")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s EXPORTED_RUNTIME_METHODS='[ccall, cwrap]'")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -03 -s USE_WEBGL2=1 -s FULL_ES3=1 -s MODULARIZE=1 -s EXPORT_NAME='Zephyrus'")
#    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file ../assets")
endif()



# HIGH-LEVEL SUGGESTION
#option(BUILD_WEB "Build WebAssembly" OFF)
#
#if(BUILD_WEB)
#    add_subdirectory(engine)
#else()
#    add_subdirectory(engine)
#endif()
