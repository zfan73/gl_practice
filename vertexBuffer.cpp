#include "vertexBuffer.h"
#include "render.h"

vertexBuffer :: vertexBuffer(const void *data, unsigned int size)
{
    callBack(glGenBuffers(1, &render_id));
    callBack(glBindBuffer(GL_ARRAY_BUFFER,render_id));
    callBack(glBufferData(GL_ARRAY_BUFFER, size, data,GL_STATIC_DRAW));
}

vertexBuffer :: ~vertexBuffer()
{
      callBack(glDeleteBuffers(1, &render_id));
}

void vertexBuffer ::bind() const
{
    callBack(glBindBuffer(GL_ARRAY_BUFFER,render_id));
}

void vertexBuffer ::unbind() const
{
    callBack(glBindBuffer(GL_ARRAY_BUFFER,0));
}