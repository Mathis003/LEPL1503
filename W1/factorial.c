#include <stdio.h>

int factorial(int n) { return (n <= 1) ? 1 : factorial(n-1) * n; }

int main()
{
    printf("factorial(%d) = %d\n", 5, factorial(5));   // 120
    printf("factorial(%d) = %d\n", 2, factorial(9));   // 362880

    return 0;
}