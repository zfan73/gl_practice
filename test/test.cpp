#include "test.h"
#include "../vendor/imgui/imgui.h"

namespace test
{
    testMenu::testMenu(test *&current_test_ptr)
    :current_test(current_test_ptr)
    {
        
    }
    testMenu::~testMenu()
    {
        
    }

    void testMenu::onImGuiRender()
    {
        for (auto& test : m_test)
        {
            if(ImGui::Button(test.first.c_str()))
            {
                current_test = test.second();
            }
        }
    } 
}