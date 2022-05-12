#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <map>
#include <queue>

#include <blueberry/input/keyboard_input.hh>

struct _KeyEvent
{
    int m_key, m_scancode, m_action, m_mods;
    _KeyEvent(int key, int scancode, int action, int mods)
        : m_key(key), m_scancode(scancode), m_action(action), m_mods(mods) {}
};

static std::map<int, bool> _keys;
static std::queue<_KeyEvent> _unhandledKeys;

void _key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    _unhandledKeys.emplace(key, scancode, action, mods);
}

void blueberry::input::keyboard::init(GLFWwindow* window)
{
    glfwSetKeyCallback(window, _key_callback);
}

void blueberry::input::keyboard::handle_keyboard_input()
{
    while (!_unhandledKeys.empty())
    {
        _KeyEvent event = _unhandledKeys.front();
        _unhandledKeys.pop();
        bool pressed = event.m_action == GLFW_PRESS || event.m_action == GLFW_REPEAT;
        _keys[event.m_key] = pressed;
    }
}

bool blueberry::input::keyboard::is_key_pressed(int key_code)
{
    return _keys[key_code];
}
