#include <zephyrus/platform/Platform.h>

int zpy::createWindow(const std::string& id, int width, int height) {
    #ifdef __EMSCRIPTEN__
        return winMain(id, width, height);
    #else
        return nativeMain(id, width, height);
    #endif
}
