#include <iostream>

struct closure
{
    int z;
    closure(const int &z_) : z(z_)
    {

    }
    int operator()(int a, int b)
    {
        return z + a + b;
    }
};


int main()
{
    int  z = 100;

    closure l(z);
    std::cout << l(1, 2) << std::endl;

    std::cout << closure(z)(1, 2) << std::endl;
    std::cout << [z](int a, int b) { return z + a+ b;}(1, 2) << std::endl;

    return 0;
}
