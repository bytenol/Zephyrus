#include <X11/Xlib.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <cstdio>

int main() {
    // 1. Create X11 window
    Display* display = XOpenDisplay(nullptr);
    Window root = DefaultRootWindow(display);

    XSetWindowAttributes swa{};
    swa.event_mask = ExposureMask | KeyPressMask;

    Window win = XCreateWindow(
        display, root,
        0, 0, 800, 600, 0,
        CopyFromParent, InputOutput,
        CopyFromParent,
        CWEventMask, &swa
    );

    XMapWindow(display, win);
    XStoreName(display, win, "Native GLES Window");

    // 2. EGL setup
    EGLDisplay eglDisplay = eglGetDisplay(display);
    eglInitialize(eglDisplay, nullptr, nullptr);

    EGLint configAttribs[] = {
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_NONE
    };

    EGLConfig config;
    EGLint numConfigs;
    eglChooseConfig(eglDisplay, configAttribs, &config, 1, &numConfigs);

    EGLSurface surface = eglCreateWindowSurface(
        eglDisplay, config, win, nullptr
    );

    EGLint contextAttribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 3,
        EGL_NONE
    };

    EGLContext context = eglCreateContext(
        eglDisplay, config, EGL_NO_CONTEXT, contextAttribs
    );

    eglMakeCurrent(eglDisplay, surface, surface, context);

    // 3. Render loop
    bool running = true;
    while (running) {
        while (XPending(display)) {
            XEvent e;
            XNextEvent(display, &e);
            if (e.type == KeyPress)
                running = false;
        }

        glViewport(0, 0, 800, 600);
        glClearColor(0.1f, 0.2f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        eglSwapBuffers(eglDisplay, surface);
    }

    eglTerminate(eglDisplay);
    XCloseDisplay(display);
    return 0;
}
