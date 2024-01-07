#pragma once
#include "test.h"

namespace test
{
    class testClearColor : public test
    {
        public:
            testClearColor();
            ~testClearColor();
            void onUpdate(float DeltaTime) override;
            void onRender() override;
            void onImGuiRender() override;
        private:
            float m_colors[4];
    };
}