#include <iostream>
#include <cmath>

void Wave();

int main()
{
    Wave();
    return 0;
}

void Wave()
{
    double x = 0;
    int y;
    for (double i = 0; i < 40; i++)
    {

        std::cout << std::endl;
        for (double j = 0; j < 80; j+=0.5, x+=0.5)
        {
                y = (sin(x) * 50)+30;
               //std::cout << y << std::endl;
                if ( i == y || i == y /  6 || i == y / 5|| i == y / 3  || i == y / 2 || i == y / 4)
                {
                    std::cout << "*\n";
                }
                else
                {
                    std::cout << " ";
                }
        }
    }
}
