#include <stdint.h>

int cmp_func(uint8_t func1(uint8_t), uint8_t func2(uint8_t))
{
    for (int i = 0; i <= 255; i++)
    {
        if (func1(i) != func2(i)) { return 0; }
    }

    return 1;
}

int main() { return 0; }