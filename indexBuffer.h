#pragma once 

class indexBuffer
{
    private:
        unsigned int m_render_id;
        unsigned int index_count;
    public:
        indexBuffer(const unsigned int *data, unsigned int count);
        ~indexBuffer();
        void bind() const;
        void unbind() const;
        inline int getCount() const {return index_count;};
};