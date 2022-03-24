#pragma once

#include <blueberry/window.hh>

namespace Blueberry
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

        void Run();

        // To be implemented in subclass
        // --------------------------------
        virtual void Update(float delta_time) = 0;  // Use for game logic
        virtual void Render() = 0;                  // Use for rendering
        // --------------------------------
    private:
        Window window;
    };
}
