#pragma once

namespace blueberry
{
    class Shader
    {
    public:
        Shader() : m_id(0)
        {
        }
        Shader(const char* vert_path, const char* frag_path, const char* comp_path);
        Shader(const Shader& shader) = delete;
        Shader(Shader&& shader)
        {
            this->m_id = shader.m_id;
            shader.m_id = 0;
        }
        ~Shader();

        Shader& operator=(Shader&& shader)
        {
            this->m_id = shader.m_id;
            shader.m_id = 0;
            return *this;
        }

        void enable();
        void disable();
    private:
        unsigned int m_id;
    };
}
