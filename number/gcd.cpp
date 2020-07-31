#include <iostream>

int gcd(int a, int b);

int main(void)
{
    int a, b;

    std::cout << "number a : ";
    std::cin >> a;

    std::cout << "number b : ";
    std::cin >> b;

    std::cout << "gcd(a, b) : " << gcd(a, b) << std::endl;
}

int gcd(int a, int b)
{
    if(a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}