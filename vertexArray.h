#pragma once 

#include "vertexBuffer.h"

class vertexBufferLayout;

class vertexArray
{
    private:
        unsigned int render_id;
    public:
        vertexArray();
        ~vertexArray();

        void addBuffer(const vertexBuffer &buffer, const vertexBufferLayout &layout);
        
        void bind() const;
        void unbind() const;
};