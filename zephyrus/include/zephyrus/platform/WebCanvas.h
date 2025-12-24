//
// Created by bytenol on 12/23/25.
//

#ifndef ZEPHYRUS_WEBCANVAS_H
#define ZEPHYRUS_WEBCANVAS_H

#include <string>

#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include <GLES3/gl3.h>

#include "../core/Engine.h"

namespace zpy {

    int webMain(const std::string& canvasId, const int& w, const int& h);

}

#endif //ZEPHYRUS_WEBCANVAS_H