#pragma once

#include <string>

#include <blueberry/window.hh>

namespace blueberry
{
    class Application
    {
    public:
        Application(const std::string& title, int width, int height);
        Application()
        : Application("Blueberry Engine v0.1", 1280, 720)
        {
        }
        virtual ~Application();

        void run();
        void set_vsync(bool vsync);
        void close();

        // To be implemented in subclass
        // --------------------------------
        virtual void update(float delta_time) = 0;  // Use for game logic
        virtual void render() = 0;                  // Use for rendering
        // --------------------------------
    private:
        Window m_window;
    };
}
