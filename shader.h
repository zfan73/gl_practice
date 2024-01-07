#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "vendor/glm/glm.hpp"

struct resource
{
    std::string vertexShader;
    std::string fragmentShader;
};

class shader
{
    private:
        unsigned int m_render_id;
        const std::string file_path;
        std::unordered_map<std::string, int> m_UniformLocationCache;
    public:
        shader(const std::string &filepath);
        ~shader();
        void bind() const;
        void unbind() const;
        void setUniform1i(std::string name, int value);
        void setUniform4f(std::string name, float f0, float f1, float f2, float f3);
        void setUniformMat4f(std::string name, glm::mat4 &matrix);
    private:
        static resource parseShader(const std::string& filepath);
        unsigned int compileShader(const std::string& source, unsigned int type);
        unsigned int createShader(const std::string &vertexShader, const std::string &fragmentShader);
        unsigned int getUniformLocation(const std::string &name);
};