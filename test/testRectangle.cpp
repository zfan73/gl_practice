#include <GL/glew.h>
#include "testRectangle.h"
#include "../vendor/imgui/imgui.h"
#include "../render.h"
#include "../vendor/glm/gtc/matrix_transform.hpp"

namespace test
{
    testRectangle::testRectangle()
    :
    m_translationA(200,200,0),
    m_proj(glm::ortho(0.0f,960.0f,0.0f,540.0f,-1.0f,1.0f)),
    m_view(glm::translate(glm::mat4(1.0f),glm::vec3(-50.0f,0.0f,0.0f)))
    {
        float positions[] = 
        {
            -50.0f,-50.0f, 0.0f, 0.18f, 0.6f, 0.96f, 1.0f, 0.0f, 0.0f, 0.0f,// 0
            50.0f,-50.0f, 0.0f, 0.18f, 0.6f, 0.96f, 1.0f, 1.0f, 0.0f, 0.0f,// 1
            50.0f,50.0f, 0.0f, 0.18f, 0.6f, 0.96f, 1.0f, 1.0f, 1.0f, 0.0f,// 2
            -50.0f,50.0f, 0.0f, 0.18f, 0.6f, 0.96f, 1.0f, 0.0f, 1.0f, 0.0f,// 3

            50.0f,50.0f, 0.0f, 1.0f, 0.93f, 0.24f, 1.0f, 0.0f, 0.0f, 1.0f,// 4
            150.0f,50.0f, 0.0f, 1.0f, 0.93f, 0.24f, 1.0f, 1.0f, 0.0f, 1.0f,// 5
            150.0f,150.0f, 0.0f, 1.0f, 0.93f, 0.24f, 1.0f, 1.0f, 1.0f, 1.0f,// 6
            50.0f,150.0f, 0.0f, 1.0f, 0.93f, 0.24f, 1.0f, 0.0f, 1.0f, 1.0f// 7
        };

        unsigned int indices[] = 
        {
            0, 1, 2,
            2, 3, 0,

            4, 5, 6,
            6, 7, 4
        };

        callBack( glEnable(GL_BLEND) );
        callBack( glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) );
     
        m_va = std::make_unique<vertexArray>();
        m_ib = std::make_unique<indexBuffer>(indices, 12);
        m_vb = std::make_unique<vertexBuffer>(positions, 8 * 10 * sizeof(float));
        m_layout = std::make_unique<vertexBufferLayout>();
        m_layout->AddFloat(3);
        m_layout->AddFloat(4);
        m_layout->AddFloat(2);
        m_layout->AddFloat(1);
        m_va->addBuffer(*m_vb, *m_layout);    
        m_shader = std::make_unique<shader>("res/shader/rectangle.shader");
        m_shader->bind();

        m_texture1 =  std::make_unique<texture>("res/texture/liquid_texture.png");
        m_texture2 =  std::make_unique<texture>("res/texture/t1.png");
        glBindTextureUnit(0, m_texture1->getID());
        glBindTextureUnit(1, m_texture2->getID());
        int sample[2] = {0,1};
        m_shader->setUniform1iv("u_Texure",2,sample);
    }

    testRectangle::~testRectangle()
    {

    }

    void testRectangle::onUpdate(float DeltaTime) 
    {
             
    }

    void testRectangle::onRender() 
    {
        callBack(glClearColor(0.0f,0.0f,1.0f,1.0f));
        callBack(glClear(GL_COLOR_BUFFER_BIT));

        render renderer;
        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f),m_translationA);
            glm::mat4 mvp = m_proj * m_view * model;
            m_shader->setUniformMat4f("u_MVP",mvp);
            renderer.draw(*m_va, *m_ib, *m_shader);
        }   

    }

    void testRectangle::onImGuiRender() 
    {   
        ImGui::SliderFloat3("Translation", &m_translationA.x, 0.0f, 960.0f);    
    }
}