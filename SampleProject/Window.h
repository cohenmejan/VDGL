#pragma once

#include "VDGL/Core.h"
#if defined(VDGL_PLATFORM_WINDOWS)

#include <Windows.h>

class Window {
public:
    static LRESULT CALLBACK WindowProc(HWND handle, UINT message, WPARAM w, LPARAM l) {
        Window* window = (Window*)GetPropA(handle, "VDGLSampleWindow");

        switch(message) {
            case WM_CLOSE: {
                window->isOpen = false;
                return 0;
            }
            default: {
                return DefWindowProcA(handle, message, w, l);
            }
        }
    }

    Window(const char* title) {

        // Create and register window class

        windowClass.cbSize = sizeof(windowClass);
        windowClass.lpfnWndProc = WindowProc;
        windowClass.hInstance = GetModuleHandleA(0);
        windowClass.lpszClassName = "WindowClass";
        windowClass.hCursor = LoadCursorA(0, LPCSTR(IDC_ARROW));
        RegisterClassExA(&windowClass);

        // Create and show the window

        handle = CreateWindowExA(
            0, "WindowClass",
            title,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            CW_USEDEFAULT, CW_USEDEFAULT,
            0, 0, windowClass.hInstance, 0);

        SetPropA(handle, "VDGLSampleWindow", this);

        // Set pixel format

        deviceContext = GetDC(handle);

        PIXELFORMATDESCRIPTOR pixelFormat {};
        pixelFormat.nSize = sizeof(pixelFormat);
        pixelFormat.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pixelFormat.iPixelType = PFD_TYPE_RGBA;
        pixelFormat.cColorBits = 32;

        SetPixelFormat(deviceContext, ChoosePixelFormat(deviceContext, &pixelFormat), &pixelFormat);

        // Show

        ShowWindow(handle, SW_SHOW);
        isOpen = true;
    }

    ~Window() {

        // Destroy the window

        RemovePropA(handle, "VDGLSampleWindow");
        DestroyWindow(handle);
        deviceContext = 0;
        handle = 0;

        // Unregister the class

        UnregisterClassA(windowClass.lpszClassName, windowClass.hInstance);
        windowClass = WNDCLASSEXA();
    }

    HDC GetDeviceContext() const {
        return deviceContext;
    }

    bool IsOpen() const {
        return isOpen;
    }

    void PollEvents() const {
        MSG msg = {};
        while(PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
    }

    void Render() const {
        SwapBuffers(deviceContext);
    }

private:
    WNDCLASSEXA windowClass {};
    HWND handle = 0;
    HDC deviceContext = 0;

    bool isOpen = false;
    int width = 0;
    int height = 0;
};

#endif // VDGL_PLATFORM_WINDOWS