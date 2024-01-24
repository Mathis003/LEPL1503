#include <stdlib.h>

/*
* Node has a value, @value, and two children, @left and @right.
* All the children of @left and itself have a smaller value than the node and all the children of @right and itself have a larger value than node
*/
typedef struct node
{
    int value;
    struct node *left; // to smaller values
    struct node *right; // to larger values
} node_t;

typedef struct bt
{
    struct node *root;
} bt_t;

/*
* Return 1 if there is a node containing @value in @tree and 0 otherwise.
*/
int contains(bt_t *tree, int value) { return (tree == NULL) ? 0 : searchBT_Value(tree->root, value); }

int searchBT_Value(node_t *node, int value)
{
    if (node == NULL)         { return 0; }
    if (node->value == value) { return 1; }
    if (node->value < value)  { return searchBT_Value(node->right, value); }

    return searchBT_Value(node->left, value);
}

int main() { return 0; }