#pragma once
#include "test.h"
#include "../vertexBuffer.h"
#include "../vertexBufferLayout.h"
#include "../texture.h"
#include <memory>

namespace test
{
    class testTexture2D : public test
    {
        public:
            testTexture2D();
            ~testTexture2D();
            void onUpdate(float DeltaTime) override;
            void onRender() override;
            void onImGuiRender() override;
        private:
            std::unique_ptr<vertexArray> m_va;
            std::unique_ptr<indexBuffer> m_ib;
            std::unique_ptr<shader> m_shader;
            std::unique_ptr<texture> m_texture;
            std::unique_ptr<vertexBuffer> m_vb;
            std::unique_ptr<vertexBufferLayout> m_layout;
            glm::vec3 m_translationA, m_translationB;
            glm::mat4 m_proj, m_view;
    };
}