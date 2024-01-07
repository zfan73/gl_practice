#include <GL/glew.h>
#include "testClearColor.h"
#include "../vendor/imgui/imgui.h"
#include "../render.h"

namespace test
{
    testClearColor::testClearColor()
    : m_colors{0.2f,0.3f,0.8f,1.0f}
    {

    }

    testClearColor::~testClearColor()
    {

    }

    void testClearColor::onUpdate(float DeltaTime) 
    {

    }

    void testClearColor::onRender() 
    {
        callBack(glClearColor(m_colors[0],m_colors[1],m_colors[2],m_colors[3]));
        callBack(glClear(GL_COLOR_BUFFER_BIT));
    }

    void testClearColor::onImGuiRender() 
    {   
        ImGui::ColorEdit4("Clear Color", m_colors);
    }
}