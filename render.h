#pragma once

#include <GL/glew.h>
#include <cassert>
#include "vertexArray.h"
#include "indexBuffer.h"
#include "shader.h"

bool displayError(const char *function, const char *file, int line);

#define ASSERT(x) assert(x);
#define callBack(x) x;\
    ASSERT(displayError(#x, __FILE__,__LINE__));

class render
{
    public:
        void clear() const;
        void draw(const vertexArray &va, const indexBuffer &ib, const shader &ss) const;
};