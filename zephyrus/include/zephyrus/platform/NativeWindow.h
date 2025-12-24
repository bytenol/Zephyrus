// GLFW + GLAD
// Created by bytenol on 12/23/25.
//

#ifndef ZEPHYRUS_NATIVEWINDOW_H
#define ZEPHYRUS_NATIVEWINDOW_H

#include <string>

#include <X11/Xlib.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>

#include <zephyrus/core/Engine.h>

namespace zpy {
    inline Display* display;
    inline EGLDisplay eglDisplay;
    inline EGLSurface surface;

    int _nativeMain(const std::string& title, const int& w, const int& h);

    void _nativeMainLoop();

}

#endif //ZEPHYRUS_NATIVEWINDOW_H