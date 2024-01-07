#pragma once 

class vertexBuffer
{
    private:
        unsigned int render_id;
    public:
        vertexBuffer(const void *data, unsigned int size);
        ~vertexBuffer();
        void bind() const;
        void unbind() const;
};