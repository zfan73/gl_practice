#include <GL/glew.h>
#include "testTexture2D.h"
#include "../vendor/imgui/imgui.h"
#include "../render.h"
#include "../vendor/glm/gtc/matrix_transform.hpp"

namespace test
{
    testTexture2D::testTexture2D()
    :  
    m_translationA(200,200,0),
    m_translationB(400,200,0),
    m_proj(glm::ortho(0.0f,960.0f,0.0f,540.0f,-1.0f,1.0f)),
    m_view(glm::translate(glm::mat4(1.0f),glm::vec3(-50.0f,0.0f,0.0f)))
    {
        float positions[] = 
        {
            -50.0f,-50.0f, 0.0f, 0.0f, // 0
            50.0f,-50.0f, 1.0f, 0.0f, // 1
            50.0f,50.0f, 1.0f, 1.0f, // 2
            -50.0f,50.0f, 0.0f, 1.0f  // 3
        };

        unsigned int indices[] = 
        {
            0, 1, 2,
            2, 3, 0
        };

        callBack( glEnable(GL_BLEND) );
        callBack( glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) );
     
        m_va = std::make_unique<vertexArray>();
        m_ib = std::make_unique<indexBuffer>(indices, 6);
        m_vb = std::make_unique<vertexBuffer>(positions, 4 * 4 * sizeof(float));
        m_layout = std::make_unique<vertexBufferLayout>();
        m_layout->AddFloat(2);
        m_layout->AddFloat(2);
        m_va->addBuffer(*m_vb, *m_layout);

        m_shader = std::make_unique<shader>("res/shader/basic.shader");
        m_shader->bind();
        m_shader->setUniform4f("u_Color", 0.8f,0.3f,0.8f,1.0f);

        m_texture =  std::make_unique<texture>("res/texture/liquid_texture.png");
        m_shader->setUniform1i("u_Texture", 0);
    }

    testTexture2D::~testTexture2D()
    {

    }

    void testTexture2D::onUpdate(float DeltaTime) 
    {

    }

    void testTexture2D::onRender() 
    {
        callBack(glClearColor(0.0f,0.0f,0.0f,1.0f));
        callBack(glClear(GL_COLOR_BUFFER_BIT));

        m_texture->bind();

        render renderer;
        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f),m_translationA);
            glm::mat4 mvp = m_proj * m_view * model;
            m_shader->setUniform4f("u_Color", 1.0,1.0f,1.0f,1.0f);
            m_shader->setUniformMat4f("u_MVP",mvp);
            renderer.draw(*m_va, *m_ib, *m_shader);
        }
                
        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f),m_translationB);
            glm::mat4 mvp = m_proj * m_view * model;
            m_shader->setUniform4f("u_Color", 1.0,1.0f,1.0f,1.0f);
            m_shader->setUniformMat4f("u_MVP",mvp);
            renderer.draw(*m_va, *m_ib, *m_shader);
        }
    }

    void testTexture2D::onImGuiRender() 
    {   
        ImGui::SliderFloat3("Translation", &m_translationA.x, 0.0f, 960.0f);
        ImGui::SliderFloat3("Translation2", &m_translationB.x, 0.0f, 960.0f);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }
}