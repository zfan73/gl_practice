#pragma once
#include "test.h"
#include "../vertexBuffer.h"
#include "../vertexBufferLayout.h"
#include "../lib.h"
#include <memory>

namespace test
{
    class testRectangle : public test
    {
        public:
            testRectangle();
            ~testRectangle();
            void onUpdate(float DeltaTime) override;
            void onRender() override;
            void onImGuiRender() override;
        private:
            std::unique_ptr<vertexArray> m_va;
            std::unique_ptr<indexBuffer> m_ib;
            std::unique_ptr<shader> m_shader;
            std::unique_ptr<vertexBuffer> m_vb;
            std::unique_ptr<vertexBufferLayout> m_layout;
            std::unique_ptr<texture> m_texture1;
            std::unique_ptr<texture> m_texture2;
            glm::vec3 m_translationA;
            glm::mat4 m_proj, m_view;
    };
}