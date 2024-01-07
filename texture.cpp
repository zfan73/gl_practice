#include "texture.h"

#include "./vendor/stb_image/stb_image.h"

texture::texture(const std::string &filepath)
: m_filepath(filepath), m_local_buffer(nullptr), m_width(0), m_height(0),m_BPP(0)
{
    stbi_set_flip_vertically_on_load(1);
    m_local_buffer = stbi_load(filepath.c_str(), &m_width, &m_height, &m_BPP, 4);

    callBack(glGenTextures(1, &m_render_id));
    callBack(glBindTexture(GL_TEXTURE_2D, m_render_id));

    callBack(glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR));
    callBack(glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR));
    callBack(glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE));
    callBack(glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE));
    callBack(glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,m_width,m_height,0,GL_RGBA, GL_UNSIGNED_BYTE,m_local_buffer));

    callBack(glBindTexture(GL_TEXTURE_2D, m_render_id));
    if (m_local_buffer)
        stbi_image_free(m_local_buffer);
}

texture::~texture()
{
   callBack(glDeleteTextures(1,&m_render_id));
}

void texture::bind(unsigned int slot) const
{
    callBack(glActiveTexture(GL_TEXTURE0 + slot));
    callBack(glBindTexture(GL_TEXTURE_2D, m_render_id));
}

void texture::unbind() const
{
    callBack(glBindTexture(GL_TEXTURE_2D, 0));
}
