#include <iostream>

int main(void)
{
    int myArray[][3] = { {1,2,3}, {5,6,7} };
    int width = 4, height = 2;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << myArray[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}