#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glad/glad.h>

#include <blueberry/graphics/texture.hh>
#include <blueberry/log.hh>

blueberry::Texture2D::Texture2D()
{
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    // Texture wrapping/filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    m_textureUnit = GL_TEXTURE0;
    m_width = m_height = m_channels = 0;
}

void blueberry::Texture2D::bind()
{
    glActiveTexture(m_textureUnit);
    glBindTexture(GL_TEXTURE_2D, m_id);
}

void blueberry::Texture2D::unbind()
{
    glActiveTexture(m_textureUnit);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void blueberry::Texture2D::load_from_file(const std::string& path)
{
    unsigned char* data = stbi_load(path.c_str() , &m_width, &m_height, &m_channels, 0);
    if (!data)
        blueberry::logger::error("Failed to read texture file: {}", path);
    // check png seperately as it has alpha channel apart from rgb channels
    if (path.substr(path.size() - 4) == ".png")
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    else if (path.substr(path.size() - 4) == ".jpg" || path.substr(path.size() - 5) == ".jpeg")
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    else
        blueberry::logger::error("File format not supported for texture: {}", path);
}

void blueberry::Texture2D::set_texture_unit(unsigned int unit)
{
    m_textureUnit = unit;
}

int blueberry::Texture2D::get_width()
{
    return m_width;
}

int blueberry::Texture2D::get_height()
{
    return m_height;
}

int blueberry::Texture2D::get_channels()
{
    return m_channels;
}
