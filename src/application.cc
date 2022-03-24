#include <glad/glad.h>
#include <string>

#include <blueberry/application.hh>
#include <blueberry/log.hh>

void APIENTRY _GLDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
    GLsizei length, const GLchar* message, const void* userParam)
{
    if (severity == GL_DEBUG_SEVERITY_NOTIFICATION)
        Blueberry::Logger::Info("[OpenGL] {}", message);
    else if (severity == GL_DEBUG_SEVERITY_MEDIUM || severity == GL_DEBUG_SEVERITY_LOW)
        Blueberry::Logger::Warn("[OpenGL] {}", message);
    else
        Blueberry::Logger::Error("[OpenGL] {}", message);
}

Blueberry::Application::Application(const std::string& title, int width, int height)
{
    // Initialize logger
    Logger::Init();
    Logger::Info("Blueberry Engine v0.1");

    // Initialize GLFW/OpenGL and create window
    Logger::Info("Initializing GLFW...");
    if (!glfwInit())
    {
        Logger::Critical("Failed to initialize GLFW!");
        std::exit(-1);
    }
    Logger::Info("Creating window...");
    window.width = width;
    window.height = height;
    window.title = title.c_str();
    window.handle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!window.handle)
    {
        Logger::Critical("Failed to create Window!");
        glfwTerminate();
        std::exit(-1);
    }
    glfwMakeContextCurrent(window.handle);
    // Initialize GLAD
    Logger::Info("Initializing OpenGL loader...");
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Logger::Critical("Failed to intialize OpenGL function loader (GLAD)!");
        exit(-1);
    }
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(_GLDebugCallback, nullptr);

    Logger::Info("Initialization complete!");
}

Blueberry::Application::~Application()
{
    glfwTerminate();
}

void Blueberry::Application::Run()
{
    glClearColor(1, 0, 0, 1);
    while (!glfwWindowShouldClose(window.handle))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // this->Update();
        this->Render();

        glfwSwapBuffers(window.handle);
        glfwPollEvents();
    }
}
