#include <stdio.h>

struct fract_t
{
    int num;
    int denum;
};


void swap(int *i, int *j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

void swap_struct(struct fract_t *a, struct fract_t *b)
{
    struct fract_t tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int i = 5;
    int j = 2;

    int *ptr_i = &i;
    int *ptr_j = &j;

    swap(ptr_i, ptr_j);

    printf("*ptr_i = %d, ptr_j = %d\n", *ptr_i, *ptr_j); // *ptr_i = 2, *ptr_j = 5


    struct fract_t struct_i = {5, 2};
    struct fract_t struct_j = {1, 7};

    struct fract_t *ptr_struct_i = &struct_i;
    struct fract_t *ptr_struct_j = &struct_j;

    swap_struct(ptr_struct_i, ptr_struct_j);

    printf("*ptr_struct_i = %d, ptr_struct_j = %d\n", ptr_struct_i->num, ptr_struct_j->num); // *ptr_struct_i = 1, *ptr_struct_j = 5

    return 0;
}