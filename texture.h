
#include "render.h"
#include <string>

class texture
{
    private:
        unsigned int m_render_id;
        std::string m_filepath;
        unsigned char *m_local_buffer;
        int m_width,m_height,m_BPP;
    public:
        texture(const std::string &filepath);
        ~texture();
        void bind(unsigned int slot = 0) const;
        void unbind() const;
        inline unsigned int getWidth() const {return m_width;};
        inline unsigned int getHeight() const {return m_height;};
        inline unsigned int getID() const {return m_render_id;};
};