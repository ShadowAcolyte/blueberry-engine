#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <blueberry/input/mouse_input.hh>

static float _xpos, _ypos;
static float _lastx, _lasty;
static float _offsetx, _offsety;
static float _scrollx, _scrolly;
static int _btn_state[GLFW_MOUSE_BUTTON_LAST + 1];

static void _scroll_callback(GLFWwindow* window, double  xoffset, double yoffset)
{
    _scrollx = xoffset;
    _scrolly = yoffset;
}

static void _cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
{
    _lastx = _xpos;
    _lasty = _ypos;
    _xpos = xpos;
    _ypos = ypos;
    _offsetx = _xpos - _lastx;
    _offsety = _ypos - _lasty;
}

static void _mouse_button_callback(GLFWwindow* window, int btn, int action, int mods)
{
    if (action == GLFW_PRESS)
        _btn_state[btn] = true;
    else
        _btn_state[btn] = false;
}

void blueberry::input::mouse::init(GLFWwindow* window)
{
    _xpos = _ypos = 0;
    _lastx = _lasty = 0;
    _scrollx = _scrolly = 0;
    for (int i = 0; i <= GLFW_MOUSE_BUTTON_LAST; i++)
        _btn_state[i] = GLFW_RELEASE;

    glfwSetScrollCallback(window, _scroll_callback);
    glfwSetCursorPosCallback(window, _cursor_pos_callback);
    glfwSetMouseButtonCallback(window, _mouse_button_callback);
}

/* Function to reset static variables as they only get updated when the mouse moves, clicks or scolls
   and results in the engine thinking the mouse has moved even though it has not (as _lastx and _lasty
   do not equal _xpos and _ypos). To only be called from within the enigne, and not the client. */
namespace blueberry::input::mouse
{
    void reset();
}
void blueberry::input::mouse::reset()
{
    _lastx = _xpos;
    _lasty = _ypos;
    _offsetx = _offsety = 0;
    _scrollx = _scrolly = 0;
}

float blueberry::input::mouse::get_xpos()
{
    return _xpos;
}

float blueberry::input::mouse::get_ypos()
{
    return _ypos;
}

float blueberry::input::mouse::get_lastx()
{
    return _lastx;
}

float blueberry::input::mouse::get_lasty()
{
    return _lasty;
}

float blueberry::input::mouse::get_offsetx()
{
    return _offsetx;
}

float blueberry::input::mouse::get_offsety()
{
    return _offsety;
}

float blueberry::input::mouse::get_scrollx()
{
    return _scrollx;
}

float blueberry::input::mouse::get_scrolly()
{
    return _scrolly;
}

bool blueberry::input::mouse::is_button_pressed(int btn_code)
{
    return _btn_state[btn_code];
}
