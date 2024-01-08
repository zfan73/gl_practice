#include "indexBuffer.h"
#include "render.h"

indexBuffer :: indexBuffer(const unsigned int *data, unsigned int count)
:index_count(count)
{
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    callBack( glGenBuffers(1, &m_render_id) );
    callBack( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_render_id) );
    callBack( glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW) );
}

indexBuffer :: ~indexBuffer()
{
    callBack(glDeleteBuffers(1, &m_render_id));
}

void indexBuffer:: bind() const
{
    callBack(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_render_id));
}

void indexBuffer:: unbind() const
{
    callBack(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0));
}

