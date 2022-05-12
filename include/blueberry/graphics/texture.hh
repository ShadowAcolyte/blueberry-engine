#pragma once

#include <string>

namespace blueberry
{
    class Texture2D
    {
    public:
        Texture2D();

        void bind();
        void unbind();

        void load_from_file(const std::string& path);
        void set_texture_unit(unsigned int unit);

        int get_width();
        int get_height();
        int get_channels();
    private:
        unsigned int m_id;
        unsigned int m_textureUnit;
        int m_width, m_height, m_channels;
    };
}
