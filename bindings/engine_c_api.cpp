//
// Created by bytenol on 12/23/25.
//
#include "engine_c_api.h"
#include "../zephyrus/include/zephyrus/core/Vec2.h"
#include <emscripten/bind.h>
#include <iostream>


EMSCRIPTEN_BINDINGS(zeph_module) {
    emscripten::function("main", &zpy::webMain);
    emscripten::function("setClearColor", &glClearColor);
    emscripten::function("setViewport", &glViewport);
    emscripten::function("clear", &glClear);

    emscripten::constant("COLOR_BUFFER_BIT", GL_COLOR_BUFFER_BIT);

    // emscripten::

    // emscripten::class_<zpy::MyClass>("Zeph_MyClass")   // JS name, can drop namespace here
    //     .constructor<int>()
    //     .function("setValue", &zpy::MyClass::setValue)
    //     .function("getValue", &zpy::MyClass::getValue)
    //     ;
}