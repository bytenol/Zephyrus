#ifndef ZEPHYRUS_PLATFORM_H
#define ZEPHYRUS_PLATFORM_H

#include <string>

#ifdef __EMSCRIPTEN__
    #include "WebCanvas.h"
#else
    #include "NativeWindow.h"
#endif

namespace zpy {

    int createWindow(const std::string& id, int width, int height);

}

#endif //ZEPHYRUS_PLATFORM_H