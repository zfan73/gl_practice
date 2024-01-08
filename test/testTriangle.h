#pragma once
#include "test.h"
#include "../vertexBuffer.h"
#include "../vertexBufferLayout.h"
#include <memory>

namespace test
{
    class testTriangle : public test
    {
        public:
            testTriangle();
            ~testTriangle();
            void onUpdate(float DeltaTime) override;
            void onRender() override;
            void onImGuiRender() override;
        private:
            std::unique_ptr<vertexArray> m_va;
            std::unique_ptr<indexBuffer> m_ib;
            std::unique_ptr<shader> m_shader;
            std::unique_ptr<vertexBuffer> m_vb;
            std::unique_ptr<vertexBufferLayout> m_layout;
    };
}