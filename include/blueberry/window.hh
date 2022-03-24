#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace Blueberry
{
    struct Window
    {
        GLFWwindow* handle;
        int width, height;
        const char* title;

        Window() = default;
    };
}
