#include <blueberry/application.hh>
#include <blueberry/graphics/shader.hh>

class Sandbox : public blueberry::Application
{
    blueberry::Shader shader{};
public:
    Sandbox()
    {
    }

    void update(float delta_time)
    {

    }

    void render()
    {

    }
};

int main()
{
    Sandbox* app = new Sandbox();
    app->run();
}
