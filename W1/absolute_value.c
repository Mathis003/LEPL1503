#include <stdio.h>

int absval(int i) { return (i >= 0) ? i : -i; }

int main()
{
    printf("absval(%d) = %d\n", 5, absval(5));   // 5
    printf("absval(%d) = %d\n", -2, absval(-2)); // 2

    return 0;
}