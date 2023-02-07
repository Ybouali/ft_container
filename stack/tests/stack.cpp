#include "../stack.hpp"

void    TEST_CMOP_EQ(void)
{
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        if (v1 == v2)
            std::cout << "Equal" << std::endl;
    }
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        for (size_t i = 0; i < 5; i++)
            v1.push(0);

        if (v1 == v2)
            std::cout << "Equal." << std::endl;
    }
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v1.push(0);
            if (i < 8)
                v2.push(0);
        }

        if (v1 == v2)
            std::cout << "Equal.." << std::endl;
    }
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v1.push(0);
            if (i < 8)
                v2.push(0);
        }

        if (v1 == v2)
            std::cout << "Equal..." << std::endl;
    }
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        for (size_t i = 0; i < 64; i++)
        {
            v1.push(0);
            if (i < 64)
                v2.push(0);
        }

        if (v1 == v2)
            std::cout << "Equal...." << std::endl;
    }
}

void    TEST_COMP_GE(void)
{
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        if (v1 <= v2)
            std::cout << "Greater Eq" << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 5; i++)
            v1.push(0);

        if (v1 <= v2)
            std::cout << "Greater Eq." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 64; i++)
            v1.push(0);

        if (v1 <= v2)
            std::cout << "Greater Eq.." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 64; i++)
        {
            v1.push(0);
            if (i < 63)
                v2.push(0);
        }

        if (v1 <= v2)
            std::cout << "Greater Eq..." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 64; i++)
        {
            v2.push(0);
            if (i < 63)
                v1.push(0);
        }

        if (v1 <= v2)
            std::cout << "Greater Eq...." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 64; i++)
        {
            v2.push(1024);
            if (i < 63)
                v1.push(1024);
        }

        if (v1 <= v2)
            std::cout << "Greater Eq....." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 64; i++)
        {
            v1.push(1024);
            if (i < 63)
                v2.push(1024);
        }

        if (v1 <= v2)
            std::cout << "Greater Eq......" << std::endl;
    }
}

void    TEST_COMP_GT(void)
{
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        if (v1 < v2)
            std::cout << "Greater" << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
            v1.push(0);

        if (v1 < v2)
            std::cout << "Greater." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
            v2.push(0);

        if (v1 < v2)
            std::cout << "Greater.." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v1.push(0);
            if (i < 8)
                v2.push(0);
        }

        if (v1 < v2)
            std::cout << "Greater..." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v2.push(0);
            if (i < 8)
                v1.push(0);
        }

        if (v1 < v2)
            std::cout << "Greater...." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v1.push(1010);
            if (i < 8)
                v2.push(1010);
        }

        if (v1 < v2)
            std::cout << "Greater......" << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v1.push(1010);
            v2.push(1010);
        }

        v1.top() = 1;

        if (v1 < v2)
            std::cout << "Greater......." << std::endl;
    }
}

void    TEST_COMP_LE(void)
{
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        if (v1 <= v2)
            std::cout << "Less Eq" << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
            v1.push(0);
        

        if (v1 <= v2)
            std::cout << "Less Eq." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
            v2.push(0);

        if (v1 <= v2)
            std::cout << "Less Eq.." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v1.push(0);
            if (i < 8)
                v2.push(0);
        }

        if (v1 <= v2)
            std::cout << "Less Eq..." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v2.push(0);
            if (i < 8)
                v1.push(0);
        }

        if (v1 <= v2)
            std::cout << "Less Eq...." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v1.push(1010);
            if (i < 8)
                v2.push(1010);
        }

        if (v1 <= v2)
            std::cout << "Less Eq....." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v2.push(1010);
            if (i < 8)
                v1.push(1010);
        }

        if (v1 <= v2)
            std::cout << "Less Eq......" << std::endl;
    }
}

void    TEST_CMOP_LT(void)
{
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        if (v1 < v2)
            std::cout << "Less" << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
            v1.push(0);
        

        if (v1 < v2)
            std::cout << "Less." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
            v2.push(0);

        if (v1 < v2)
            std::cout << "Less.." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v1.push(0);
            if (i < 8)
                v2.push(0);
        }

        if (v1 < v2)
            std::cout << "Less..." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v2.push(0);
            if (i < 8)
                v1.push(0);
        }

        if (v1 < v2)
            std::cout << "Less...." << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v1.push(10101);
            if (i < 8)
                v2.push(10101);
        }

        if (v1 < v2)
            std::cout << "Less......" << std::endl;
    }
    {
        ft::stack<int> v1;
        ft::stack<int> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v2.push(10101);
            if (i < 8)
                v1.push(10101);
        }

        v1.top() = 1;

        if (v1 < v2)
            std::cout << "Less......." << std::endl;
    }
}

void    TEST_CMOP_NE(void)
{
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        if (v1 != v2)
            std::cout << "Not Equal" << std::endl;
    }
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        for (size_t i = 0; i < 9; i++)
            v1.push(0);

        if (v1 != v2)
            std::cout << "Not Equal." << std::endl;
    }
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v1.push(0);
            if (i < 8)
                v2.push(0);
        }

        if (v1 != v2)
            std::cout << "Not Equal.." << std::endl;
    }
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v2.push(0);
            if (i < 8)
                v1.push(0);
        }

        if (v1 != v2)
            std::cout << "Not Equal..." << std::endl;
    }
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        for (size_t i = 0; i < 9; i++)
        {
            v1.push(101010);
            v2.push(101010);
        }

        if (v1 != v2)
            std::cout << "Not Equal...." << std::endl;
    }
}

void    TEST_MIXED(void)
{
        ft::stack<int, ft::vector<int, std::allocator<int> > > st;

        std::cout << "Empty: " << (st.empty() ? "true" : "false") << std::endl;

        st.push(34);

        std::cout << "Size: " << st.size() << std::endl;
        std::cout << "Empty: " << (st.empty() ? "true" : "false") << std::endl;
        std::cout << "Top: " << st.top() << std::endl;

        st.push(64);

        std::cout << "Size: " << st.size() << std::endl;
        std::cout << "Empty: " << (st.empty() ? "true" : "false") << std::endl;
        std::cout << "Top: " << st.top() << std::endl;

        st.top() = 1;

        std::cout << "Size: " << st.size() << std::endl;
        std::cout << "Empty: " << (st.empty() ? "true" : "false") << std::endl;
        std::cout << "Top: " << st.top() << std::endl;

        st.push(128);

        std::cout << "Size: " << st.size() << std::endl;
        std::cout << "Top: " << st.top() << std::endl;

        const ft::stack<int, ft::vector<int, std::allocator<int> > > st1(st);

        std::cout << "Size: " << st.size() << std::endl;
        std::cout << "Empty: " << (st.empty() ? "true" : "false") << std::endl;
        std::cout << "Top: " << st.top() << std::endl;

        st.pop();
        st.pop();

        std::cout << "Size: " << st.size() << std::endl;
        std::cout << "Empty: " << (st.empty() ? "true" : "false") << std::endl;
        std::cout << "Top: " << st.top() << std::endl;

        st.pop();

        std::cout << "Size: " << st.size() << std::endl;
        std::cout << "Top: " << st.top() << std::endl;

        st = st1;

        std::cout << "Size: " << st.size() << std::endl;
        std::cout << "Empty: " << (st.empty() ? "true" : "false") << std::endl;
        std::cout << "Top: " << st.top() << std::endl;
}

void    stack_tests(void)
{
    std::cout << "Loading stack..." << std::endl;
    TEST_CMOP_EQ();
    TEST_COMP_GE();
    TEST_COMP_GT();
    TEST_COMP_LE();
    TEST_CMOP_LT();
    TEST_CMOP_NE();
    TEST_MIXED();
}