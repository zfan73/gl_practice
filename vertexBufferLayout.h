#pragma once 

#include <GL/glew.h>
#include "render.h"
#include <vector>

struct glElements
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int getSizeOfType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT         : return sizeof(GLfloat);
            case GL_UNSIGNED_INT  : return sizeof(GLuint);
            case GL_UNSIGNED_BYTE : return sizeof(GLbyte);
        }
        ASSERT(false);
        return 0;
    }
};

class vertexBufferLayout
{
    private:
        unsigned int m_Stride;
        std::vector<glElements> m_Elements;
    public:
        vertexBufferLayout() :
            m_Stride(0) { }

        void AddFloat(unsigned int count)        { Push(GL_FLOAT, count, GL_FALSE);        }
        void AddUnsignedInt(unsigned int count)  { Push(GL_UNSIGNED_INT, count, GL_FALSE); }
        void AddUnsignedByte(unsigned int count) { Push(GL_UNSIGNED_BYTE, count, GL_TRUE); }

        inline const std::vector<glElements> getElement() const { return m_Elements; };
        inline unsigned int getStride() const { return m_Stride; };

    private:
        void Push(unsigned int type, unsigned int count, unsigned char normalized)
        {
            struct glElements vbe = {type, count, normalized};
            m_Elements.push_back(vbe);
            m_Stride += count * glElements::getSizeOfType(type);
        };
};