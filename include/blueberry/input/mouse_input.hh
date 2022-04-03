#pragma once

struct GLFWwindow;

namespace blueberry
{
    namespace input
    {
        namespace mouse
        {
            void init(GLFWwindow* window);

            float getPosX();
            float getPosY();

            float getLastX();
            float getLastY();

            float getOffsetX();
            float getOffsetY();

            float getScrollX();
            float getScrollY();

            bool isButtonPressed(int btn_code);
        }
    }
}
