
#include "vertexArray.h"
#include "vertexBufferLayout.h"
#include "render.h"


vertexArray :: vertexArray()
{
    callBack(glGenVertexArrays(1, &render_id));
}

vertexArray :: ~vertexArray()
{
    callBack(glDeleteVertexArrays(1,&render_id));
}

void vertexArray :: addBuffer(const vertexBuffer &vb, const vertexBufferLayout &layout)
{
    bind();
    vb.bind();
    const std::vector<glElements> elements = layout.getElement();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size() ; i++)
    {
        const glElements element = elements[i];
        callBack( glEnableVertexAttribArray(i) );
        callBack( glVertexAttribPointer(i, element.count, element.type, element.normalized,layout.getStride(), (void*)(uintptr_t)(offset)));
        offset += element.count * glElements::getSizeOfType(element.type);
    }

}

void vertexArray ::bind() const
{
    callBack(glBindVertexArray(render_id));
}
        
void vertexArray ::unbind() const
{
    callBack(glBindVertexArray(0));
}