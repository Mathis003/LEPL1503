#include <stdlib.h>

/**
* Structure node
*
* @next: pointer to the next node in the list, NULL if last node_t
* @value: value stored in the node
*/
typedef struct node
{
  struct node *next;
  int value;
} node_t;

/**
* Structure list
*
* @first: first node of the list, NULL if list is empty
* @size: number of nodes in the list
*/
typedef struct list
{
  struct node *first;
  int size;
} list_t;

/*
* Create a new node containing the value @value.
*
* @value: value stored in the node
* @next : pointer to next node, initialised to NULL.
* @return: returns the pointer to the newly created node, or NULL if an error occured.
*/
node_t *init_node(int value)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (new_node == NULL) { return NULL; }

    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

/*
* Add a node at the head of the list @list and increment the number of nodes in the list (member `size`)
*
* @l: linked list
* @value: value to add to the list
*
* @return: 0 if success, 1 otherwise
*/
int add_node(list_t *list, int value)
{
    if (list == NULL) { return 1; }

    node_t *first = list->first;
    node_t *new_node = init_node(value);
    if (new_node == NULL) { return 1; }

    new_node->next = first;
    list->first = new_node;
    list->size++;

    return 0;
}

int main() { return 0; }