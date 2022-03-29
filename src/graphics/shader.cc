#include <fstream>
#include <sstream>

#include <glad/glad.h>

#include <blueberry/graphics/shader.hh>
#include <blueberry/log.hh>

static int _check_compile_errors(unsigned int shader)
{
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (success != GL_TRUE)
    {
        int length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        char* info = new char[length];
        glGetShaderInfoLog(shader, length, NULL, info);
        blueberry::logger::error("Shader compilation failed! \n {}", info);
        delete[] info;
    }
    return success;
}

static unsigned int _compile_shader(const std::string& type, const std::string& path)
{
    std::ifstream file(path);
    std::string code;

    if (file.fail())
    {
        blueberry::logger::error("Failed to read shader file: '{}'!", path.c_str());
        return 0;
    }
    else
    {
        std::stringstream ss;
        ss << file.rdbuf();
        file.close();
        code = ss.str();
    }

    blueberry::logger::info("Compiling shader '{}' of type '{}'.", path.c_str(), type.c_str());
    unsigned int shader = NULL;
    const char* _code = code.c_str();

    if (type == "VERTEX")           shader = glCreateShader(GL_VERTEX_SHADER);
    else if (type == "FRAGMENT")    shader = glCreateShader(GL_FRAGMENT_SHADER);
    else if (type == "COMPUTE")     shader = glCreateShader(GL_COMPUTE_SHADER);
    else {
        blueberry::logger::error("Unknow shader type passed in _compile_shader(): '{}'!", type.c_str());
        return 0;
    }

    glShaderSource(shader, 1, &_code, NULL);
    glCompileShader(shader);
    if (_check_compile_errors(shader) != GL_TRUE)
        return 0;
    return shader;
}

static int _check_link_errors(unsigned int program)
{
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (success != GL_TRUE)
    {
        int length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
        char* info = new char[length];
        glGetProgramInfoLog(program, length, NULL, info);
        blueberry::logger::error("Shader program linking error!\n{}", 1, info);
        delete[] info;
    }
    return success;
}

blueberry::Shader::Shader(const char* vert_path, const char* frag_path, const char* comp_path)
{
    unsigned int vs, fs, cs;
    vs = fs = cs = 0;
    if (vert_path != nullptr)
    {
        vs = _compile_shader("VERTEX", vert_path);
        if (!vs)
        {
            m_id = 0;
            return;
        }
    }
    if (frag_path != nullptr)
    {
        fs = _compile_shader("FRAGMENT", frag_path);
        if (!fs)
        {
            m_id = 0;
            return;
        }
    }
    if (comp_path != nullptr)
    {
        cs = _compile_shader("COMPUTE", comp_path);
        if (!cs)
        {
            m_id = 0;
            return;
        }
    }

    blueberry::logger::info("Creating shader program.");
    m_id = glCreateProgram();
    if (vs)  glAttachShader(m_id, vs);
    if (fs)  glAttachShader(m_id, fs);
    if (cs)  glAttachShader(m_id, cs);
    glLinkProgram(m_id);

    if (_check_link_errors(m_id) != GL_TRUE)
    {
        glDeleteProgram(m_id);
        m_id = 0;
    }
}

blueberry::Shader::~Shader()
{
    glDeleteProgram(m_id);
}

void blueberry::Shader::enable()
{
    glUseProgram(m_id);
}

void blueberry::Shader::disable()
{
    glUseProgram(0);
}
