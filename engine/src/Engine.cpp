#include "../include/engine/core/Engine.h"

void zpy::setWindowSize(const int &width, const int &height) {
    _windowSize.x = static_cast<float>(width);
    _windowSize.y = static_cast<float>(height);
}

zpy::Vec2 zpy::getWindowSize() {
    return _windowSize;
}

void zpy::setError(const std::string &err) {
    _error = err;
}

std::string & zpy::getError() {
    return _error;
}
