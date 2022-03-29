#include <iostream>

#include <blueberry/application.hh>
#include <blueberry/graphics/shader.hh>
#include <blueberry/input/mouse_input.hh>

class Sandbox : public blueberry::Application
{
public:
    Sandbox()
    {
    }

    void update(float delta_time)
    {
        
    }

    void render()
    {
        if (blueberry::input::mouse::is_button_pressed(GLFW_MOUSE_BUTTON_LEFT))
            std::cout << "Left mouse button pressed!\n";
        if (blueberry::input::mouse::is_button_pressed(GLFW_MOUSE_BUTTON_RIGHT))
            std::cout << "Right mouse button pressed\n";
        std::cout << "Mouse current position: (" << blueberry::input::mouse::get_xpos() << ", " << blueberry::input::mouse::get_ypos() << ")\n";
        std::cout << "Mouse last position:    (" << blueberry::input::mouse::get_lastx() << ", " << blueberry::input::mouse::get_lasty() << ")\n";
        std::cout << "Mouse position change:  (" << blueberry::input::mouse::get_offsetx() << ", " << blueberry::input::mouse::get_offsety() << ")\n";
    }
};

int main()
{
    Sandbox* app = new Sandbox();
    app->run();
}
