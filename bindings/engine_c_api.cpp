//
// Created by bytenol on 12/23/25.
//
#include "engine_c_api.h"
#include "../zephyrus/include/zephyrus/core/Vec2.h"
#include <emscripten/bind.h>
#include <iostream>


EMSCRIPTEN_BINDINGS(zeph_module) {
    emscripten::function("main", &zpy::webMain);

    // emscripten::class_<zpy::MyClass>("Zeph_MyClass")   // JS name, can drop namespace here
    //     .constructor<int>()
    //     .function("setValue", &zpy::MyClass::setValue)
    //     .function("getValue", &zpy::MyClass::getValue)
    //     ;
}