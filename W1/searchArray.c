#include <stdio.h>

/* This program searches for an element in an array of int.
@tab : an array of int
@len : the number of int in tab
@elem : the elem looked for
@return : return the index at which elem is found, else returns -1 if not found.
*/
int tab_find(int tab[], int len, int elem)
{
    for(int i = 0; i < len; i++)
    {
        if (tab[i] == elem) { return i; }
    }
    return -1;
}

int main()
{
    int array[] = {1, 2, -3, 4, 5, 6, -7, 3};

    printf("tab_find(%d) = %d\n", 5, tab_find(array, 8, 5));  // 4
    printf("tab_find(%d) = %d\n", -7, tab_find(array, 8, -7)); // 6
    printf("tab_find(%d) = %d\n", 8, tab_find(array, 8, 8));   // -1

    return 0;
}