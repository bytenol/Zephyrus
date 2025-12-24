#include <zephyrus/core/Engine.h>
#include <zephyrus/platform/Platform.h>

void mainLoop() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main() {
    zpy::setMainLoop(mainLoop);
    const int win = zpy::createWindow("Window Test", 480, 640);
    return win;
}
