#include "shader.h"
#include "render.h"


shader :: shader(const std::string &filepath):
m_render_id(0), file_path(filepath)
{
    struct resource ss = parseShader(filepath);

    std::cout << "VERTEX" << std::endl << ss.vertexShader << std::endl;
    std::cout << "FRAGMENT" << std::endl << ss.fragmentShader << std::endl;

    m_render_id = createShader(ss.vertexShader, ss.fragmentShader); 
}

shader :: ~shader()
{
    callBack(glDeleteProgram(m_render_id));
}

void shader :: bind() const
{
    callBack(glUseProgram(m_render_id));
}

void shader :: unbind() const
{
    callBack(glUseProgram(0));
}

void shader :: setUniform1i(std::string name, int value)
{
    callBack(glUniform1i(getUniformLocation(name),value));
}

void shader :: setUniform4f(std::string name, float v0, float v1, float v2, float v3)
{
    callBack(glUniform4f(getUniformLocation(name),v0,v1,v2,v3));
}

void shader :: setUniformMat4f(std::string name, glm::mat4 &matrix)
{
    callBack(glUniformMatrix4fv(getUniformLocation(name),1, GL_FALSE, &matrix[0][0]));
}

resource shader :: parseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);
    std::stringstream ss[2];
    std::string line;
    
    int option = 0;
    while (getline(stream, line))
    {
        if (line.find("shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                option = 1;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                option = 2;
            }
        }
        else
        {
            ss[option-1] << line << "\n";
        }
    }
  
    return {ss[0].str(), ss[1].str()};
}

unsigned int shader :: compileShader(const std::string& source, unsigned int type)
{
    callBack( unsigned int id = glCreateShader(type) );
    const char* src = source.c_str();
    callBack( glShaderSource(id, 1, &src, nullptr) );
    callBack( glCompileShader(id) );

    // Error handling
    int result;
    callBack( glGetShaderiv(id, GL_COMPILE_STATUS, &result) );
    std::cout << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader compile status: " << result << std::endl;
    if ( result == GL_FALSE )
    {
        int length;
        callBack( glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length) );
        char* message = (char*) alloca(length * sizeof(char));
        callBack( glGetShaderInfoLog(id, length, &length, message) );
        std::cout 
            << "Failed to compile "
            << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
            << "shader"
            << std::endl;
        std::cout << message << std::endl;
        callBack( glDeleteShader(id) );
        return 0;
    }

    return id;
}

unsigned int shader :: createShader(const std::string &vertexShader, const std::string &fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(vertexShader, GL_VERTEX_SHADER);
    unsigned int fs = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

    callBack( glAttachShader(program, vs) );
    callBack( glAttachShader(program, fs) );

    callBack( glLinkProgram(program) );

    GLint program_linked;

    callBack( glGetProgramiv(program, GL_LINK_STATUS, &program_linked) );
    std::cout << "Program link status: " << program_linked << std::endl;
    if (program_linked != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        callBack( glGetProgramInfoLog(program, 1024, &log_length, message) );
        std::cout << "Failed to link program" << std::endl;
        std::cout << message << std::endl;
    }

    callBack( glValidateProgram(program) );

    callBack( glDeleteShader(vs) );
    callBack( glDeleteShader(fs) );

    return program;
}

unsigned int shader :: getUniformLocation(const std::string &name)
{
    int location;
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
        return m_UniformLocationCache[name];
    callBack(location = glGetUniformLocation(m_render_id, name.c_str()));
    if (location == -1)
    {
        std::cout << "Warning! " << name << " does not exist!" << std::endl;
    }
    m_UniformLocationCache[name] = location;
    return location;
}