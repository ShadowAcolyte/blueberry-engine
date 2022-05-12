#pragma once

struct GLFWwindow;

namespace blueberry
{
    namespace input
    {
        namespace keyboard
        {
            void init(GLFWwindow* window);

            void handle_keyboard_input();
            bool is_key_pressed(int key_code);
        }
    }
}
