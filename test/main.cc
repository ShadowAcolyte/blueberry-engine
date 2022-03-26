#include <blueberry/application.hh>

class Sandbox : public blueberry::Application
{
public:
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