#include "render.h"
#include <iostream>

bool displayError(const char *function, const char *file, int line)
{
    int error = glGetError();
    if (error != GL_NO_ERROR)
    {
        std::cout<<"GL ERROR: " << error << std::endl;
        while (glGetError() != GL_NO_ERROR);
        return false;
    }
    return true;
}

void render::clear() const
{
     callBack(glClear( GL_COLOR_BUFFER_BIT));
}

void render::draw(const vertexArray &va, const indexBuffer &ib, const shader &ss) const
 {
    callBack(ss.bind());
    callBack(va.bind());
    callBack(ib.bind());

    callBack(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
 }
