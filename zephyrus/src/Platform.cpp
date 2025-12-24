#include <zephyrus/platform/Platform.h>


int zpy::createWindow(const std::string& id, int width, int height) {
    setWindowSize(width, height);
    #ifdef __EMSCRIPTEN__
        return winMain(id, width, height);
    #else
        return _nativeMain(id, width, height);
    #endif
}

int zpy::mainLoop() {
#ifdef __EMSCRIPTEN__
    // _webMainLoop();
#else
    // _nativeMainLoop();
#endif
}
