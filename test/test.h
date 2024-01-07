#pragma once
#include <functional>
#include <string>
#include <iostream>
#include <vector>

namespace test
{
    class test
    {
        public:
            test() {}
            virtual ~test() {}
            virtual void onUpdate(float deltaTime) {}
            virtual void onRender() {}
            virtual void onImGuiRender() {}
    };

    class testMenu : public test
    {
        public:
            testMenu(test *&current_test_ptr);
            ~testMenu();
            void onImGuiRender() override;

            template <typename T>
            void register_test(const std::string &name)
            {
                std::cout << "test registered: " << name << "\n";
                m_test.push_back(std::make_pair(name, []()  {return new T();}));
            }
        private:
            test *&current_test;
            std::vector<std::pair<std::string, std::function<test*()>>> m_test;
    };
}