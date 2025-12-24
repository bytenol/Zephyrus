//
// Created by bytenol on 12/23/25.
//

#ifndef ZEPHYRUS_ENGINE_H
#define ZEPHYRUS_ENGINE_H

#include <string>
#include "Vec2.h"

namespace zpy {
    inline std::string _error;
    inline Vec2 _windowSize;

    void setWindowSize(const int& width, const int& height);
    Vec2 getWindowSize();

    void setError(const std::string& err);
    std::string& getError();

}

#endif //ZEPHYRUS_ENGINE_H