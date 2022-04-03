#pragma once

struct GLFWwindow;

namespace blueberry
{
    namespace input
    {
        namespace keyboard
        {
            void init(GLFWwindow* window);

            void handleKeyboardInput();
            bool isKeyPressed(int key_code);
        }
    }
}
