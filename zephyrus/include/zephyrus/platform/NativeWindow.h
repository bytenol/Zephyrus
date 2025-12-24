// GLFW + GLAD
// Created by bytenol on 12/23/25.
//

#ifndef ZEPHYRUS_NATIVEWINDOW_H
#define ZEPHYRUS_NATIVEWINDOW_H

#include <string>

#include <X11/Xlib.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>

namespace zpy {

    int nativeMain(const std::string& title, const int& w, const int& h);

}

#endif //ZEPHYRUS_NATIVEWINDOW_H