#include <GL/glew.h>
#include "testTriangle.h"
#include "../vendor/imgui/imgui.h"
#include "../render.h"
#include "../vendor/glm/gtc/matrix_transform.hpp"

namespace test
{
    testTriangle::testTriangle()
    {
        float positions[] = 
        {
            0.25f, 0.0f, 0.0f, 0.18f, 0.6f, 0.96f, 1.0f,// 0
            0.0f, 0.5f, 0.0f, 0.18f, 0.6f, 0.96f, 1.0f,// 1
            -0.25f, 0.0f, 0.0f, 0.18f, 0.6f, 0.96f, 1.0f,// 2

            0.25f, -0.5f, 0.0f, 1.0f, 0.93f, 0.24f, 1.0f,// 3
            0.0f, 0.0f, 0.0f, 1.0f, 0.93f, 0.24f, 1.0f,// 4
            -0.25f, -0.5f, 0.0f, 1.0f, 0.93f, 0.24f, 1.0f,// 5
        };

        unsigned int indices[] = 
        {
            0, 1, 2,
            3, 4, 5
        };
     
        m_va = std::make_unique<vertexArray>();
        m_ib = std::make_unique<indexBuffer>(indices, 6);
        m_vb = std::make_unique<vertexBuffer>(positions, 6 * 7 * sizeof(float));
        m_layout = std::make_unique<vertexBufferLayout>();
        m_layout->AddFloat(3);
        m_layout->AddFloat(4);
        m_va->addBuffer(*m_vb, *m_layout);    
        m_shader = std::make_unique<shader>("res/shader/triangle.shader");
        m_shader->bind();
    }

    testTriangle::~testTriangle()
    {

    }

    void testTriangle::onUpdate(float DeltaTime) 
    {
             
    }

    void testTriangle::onRender() 
    {
        callBack(glClearColor(0.0f,0.0f,0.0f,1.0f));
        callBack(glClear(GL_COLOR_BUFFER_BIT));
        render renderer;
        {
            renderer.draw(*m_va, *m_ib, *m_shader);
        }

    }

    void testTriangle::onImGuiRender() 
    {   
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }
}