#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace blueberry
{
    struct Window
    {
        GLFWwindow* m_handle;
        int m_width, m_height;
        const char* m_title;

        Window() = default;
    };
}
