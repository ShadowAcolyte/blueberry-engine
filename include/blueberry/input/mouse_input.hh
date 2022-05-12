#pragma once

struct GLFWwindow;

namespace blueberry
{
    namespace input
    {
        namespace mouse
        {
            void init(GLFWwindow* window);

            float get_pos_x();
            float get_pos_y();

            float get_last_x();
            float get_last_y();

            float get_offset_x();
            float get_offset_y();

            float get_scroll_x();
            float get_scroll_y();

            bool is_button_pressed(int btn_code);
        }
    }
}
