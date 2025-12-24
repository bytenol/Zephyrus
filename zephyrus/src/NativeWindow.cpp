#include "../include/zephyrus/platform/NativeWindow.h"

int zpy::nativeMain(const std::string &title, const int &w, const int &h) {
    Display* display = XOpenDisplay(nullptr);
    const Window root = DefaultRootWindow(display);

    XSetWindowAttributes swa{};
    swa.event_mask = ExposureMask | KeyPressMask;

    const Window win = XCreateWindow(display, root,0, 0, w, h, 0,CopyFromParent, InputOutput,CopyFromParent, CWEventMask, &swa);

    XMapWindow(display, win);
    XStoreName(display, win, title.c_str());

    const EGLDisplay eglDisplay = eglGetDisplay(display);
    eglInitialize(eglDisplay, nullptr, nullptr);

    const EGLint configAttribs[] = { EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT, EGL_SURFACE_TYPE, EGL_WINDOW_BIT, EGL_NONE};

    EGLConfig config;
    EGLint numConfigs;
    eglChooseConfig(eglDisplay, configAttribs, &config, 1, &numConfigs);

    const EGLSurface surface = eglCreateWindowSurface(eglDisplay, config, win, nullptr);

    constexpr EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};

    const EGLContext context = eglCreateContext(eglDisplay, config, EGL_NO_CONTEXT, contextAttribs);

    eglMakeCurrent(eglDisplay, surface, surface, context);

    bool running = true;
    while (running) {
        while (XPending(display)) {
            XEvent e;
            XNextEvent(display, &e);
            if (e.type == KeyPress)
                running = false;
        }

        glViewport(0, 0, w, h);
        glClearColor(0.1f, 0.2f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        eglSwapBuffers(eglDisplay, surface);
    }

    eglTerminate(eglDisplay);
    XCloseDisplay(display);
    return 0;
}
