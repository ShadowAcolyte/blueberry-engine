#pragma once

struct GLFWwindow;

namespace blueberry
{
    namespace input
    {
        namespace mouse
        {
            void init(GLFWwindow* window);

            float get_xpos();
            float get_ypos();

            float get_lastx();
            float get_lasty();

            float get_offsetx();
            float get_offsety();

            float get_scrollx();
            float get_scrolly();

            bool is_button_pressed(int btn_code);
        }
    }
}
