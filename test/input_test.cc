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
        if (blueberry::input::mouse::is_button_pressed(GLFW_MOUSE_BUTTON_LEFT))
            std::cout << "Left mouse button pressed!\n";
        if (blueberry::input::mouse::is_button_pressed(GLFW_MOUSE_BUTTON_RIGHT))
            std::cout << "Right mouse button pressed\n";
        std::cout << "Mouse current position: (" << blueberry::input::mouse::get_pos_x() << ", " << blueberry::input::mouse::get_pos_y() << ")\n";
        std::cout << "Mouse last position:    (" << blueberry::input::mouse::get_last_x() << ", " << blueberry::input::mouse::get_last_y() << ")\n";
        std::cout << "Mouse position change:  (" << blueberry::input::mouse::get_offset_x() << ", " << blueberry::input::mouse::get_offset_y() << ")\n";

        if (blueberry::input::keyboard::is_key_pressed(GLFW_KEY_A))
            std::cout << "A key pressed!\n";
        if (blueberry::input::keyboard::is_key_pressed(GLFW_KEY_ESCAPE))
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
    app->set_vsync(false);
    app->run();
}
