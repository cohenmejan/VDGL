#include "VDGL/VDGL.h"
#include "Window.h"

int main() {
    // Initialize VDGL before using any GL functions
    VDGL::Initialize();

    Window window = Window("Sample Window");

    // Create a render context

    HGLRC renderContext = wglCreateContext(window.GetDeviceContext());
    wglMakeCurrent(window.GetDeviceContext(), renderContext);

    // Window loop

    while(window.IsOpen()) {
        window.PollEvents();

        // Call some GL functions

        glClearColor(0.4f, 0.5f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.Render();
    }

    // Delete context before closing VDGL

    wglMakeCurrent(0, 0);
    wglDeleteContext(renderContext);
    renderContext = 0;

	VDGL::Close();
}