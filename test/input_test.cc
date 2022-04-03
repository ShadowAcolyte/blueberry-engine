#include <iostream>

#include <blueberry/application.hh>
#include <blueberry/graphics/shader.hh>
#include <blueberry/input/mouse_input.hh>
#include <blueberry/input/keyboard_input.hh>

class Sandbox : public blueberry::Application
{
public:
    Sandbox()
    {
    }

    void update(float delta_time)
    {
        if (blueberry::input::mouse::isButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
            std::cout << "Left mouse button pressed!\n";
        if (blueberry::input::mouse::isButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
            std::cout << "Right mouse button pressed\n";
        std::cout << "Mouse current position: (" << blueberry::input::mouse::getPosX() << ", " << blueberry::input::mouse::getPosY() << ")\n";
        std::cout << "Mouse last position:    (" << blueberry::input::mouse::getLastX() << ", " << blueberry::input::mouse::getLastY() << ")\n";
        std::cout << "Mouse position change:  (" << blueberry::input::mouse::getOffsetX() << ", " << blueberry::input::mouse::getOffsetY() << ")\n";

        if (blueberry::input::keyboard::isKeyPressed(GLFW_KEY_A))
            std::cout << "A key pressed!\n";
        if (blueberry::input::keyboard::isKeyPressed(GLFW_KEY_ESCAPE))
            close();

        std::cout << "Delta time: " << delta_time << std::endl;
    }

    void render()
    {

    }
};

int main()
{
    Sandbox* app = new Sandbox();
    app->setVsync(false);
    app->run();
}
