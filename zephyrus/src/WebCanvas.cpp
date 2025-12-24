#include "../include/zephyrus/platform/WebCanvas.h"
#include <iostream>


int zpy::_webMain(const std::string &canvasId, const int &w, const int &h) {

    const char* _canvasId = canvasId.c_str();
    EmscriptenWebGLContextAttributes attr;
    emscripten_webgl_init_context_attributes(&attr);
    attr.majorVersion = 2;

    const EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context = emscripten_webgl_create_context(_canvasId, &attr);
    if(context <= 0) {
        setError("Failed to create a webgl2 context");
        std::cerr << "Failed to create context" << std::endl;
        return -1;
    }
    emscripten_set_canvas_element_size(_canvasId, w, h);
    emscripten_webgl_make_context_current(context);
    glViewport(0, 0, w, h);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    return 0;
}

void zpy::_webMainLoop() {
    emscripten_set_main_loop(_user_mainLoop, 0, 1);
}
