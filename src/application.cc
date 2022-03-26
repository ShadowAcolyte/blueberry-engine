#include <glad/glad.h>
#include <string>

#include <blueberry/application.hh>
#include <blueberry/log.hh>

void APIENTRY _GLDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
    GLsizei length, const GLchar* message, const void* userParam)
{
    if (severity == GL_DEBUG_SEVERITY_NOTIFICATION)
        blueberry::logger::info("[OpenGL] {}", message);
    else if (severity == GL_DEBUG_SEVERITY_MEDIUM || severity == GL_DEBUG_SEVERITY_LOW)
        blueberry::logger::warn("[OpenGL] {}", message);
    else
        blueberry::logger::error("[OpenGL] {}", message);
}

blueberry::Application::Application(const std::string& title, int width, int height)
{
    // Initialize logger
    logger::init();
    logger::info("Blueberry Engine v0.1");

    // Initialize GLFW/OpenGL and create window
    logger::info("Initializing GLFW...");
    if (!glfwInit())
    {
        logger::critical("Failed to initialize GLFW!");
        std::exit(-1);
    }
    logger::info("Creating window...");
    m_window.m_width = width;
    m_window.m_height = height;
    m_window.m_title = title.c_str();
    m_window.m_handle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!m_window.m_handle)
    {
        logger::critical("Failed to create Window!");
        glfwTerminate();
        std::exit(-1);
    }
    glfwMakeContextCurrent(m_window.m_handle);
    // Initialize GLAD
    logger::info("Initializing OpenGL loader...");
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        logger::critical("Failed to intialize OpenGL function loader (GLAD)!");
        exit(-1);
    }
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(_GLDebugCallback, nullptr);

    logger::info("Initialization complete!");
}

blueberry::Application::~Application()
{
    glfwTerminate();
}

void blueberry::Application::run()
{
    glClearColor(0.3098f, 0.5255f, 0.9686f, 1);
    while (!glfwWindowShouldClose(m_window.m_handle))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // this->Update();
        this->render();

        glfwSwapBuffers(m_window.m_handle);
        glfwPollEvents();
    }
}
