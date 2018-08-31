#include <iostream>

struct xray
{
    xray()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    xray(const xray &)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    ~xray()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

struct closure
{
    xray z;
    closure(const xray &z_) : z(z_)
    {

    }
    int operator()(int a, int b)
    {
        return a + b;
    }
};


int main()
{
    xray z;

    closure l(z);
    std::cout << l(1, 2) << std::endl;

    std::cout << closure(z)(1, 2) << std::endl;
    std::cout << [z](int a, int b) { return a + b;}(1, 2) << std::endl;

    return 0;
}
