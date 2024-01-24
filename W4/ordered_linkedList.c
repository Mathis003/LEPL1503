#include <stdio.h>

typedef struct node
{
    char val;
    struct node *next;
} node_t;

/*
* @return: 0 if equals, negative number if @b is greater,
* and positive number otherwise
*/
int compare(char a, char b) { return a - b; }

/*
* @value: value to be inserted. If the value is already in the list, no element is added and the list is not modified
* @fun: comparison function which defines the order relationship of the list
* @head: first node of the list, head != NULL
* @return: 0 if success, -1 otherwise
*/
int insert(node_t **head, char val, int (*cmp)(char,char))
{
    if (!*head)
    {
        node_t *newNode = (node_t *) malloc(sizeof(node_t));
        if (newNode == NULL) { return -1; }

        newNode->val = val;
        newNode->next = NULL;
        *head = newNode;

        return 0;
    }

    node_t *incrNode = *head;
    node_t *incrNodePrevious = *head;

    while ((incrNode != NULL) && ((*cmp)(val, incrNode->val) >= 0))
    {
        if ((*cmp)(val, incrNode->val) == 0) { return 0; }
        incrNodePrevious = incrNode;
        incrNode = incrNode->next;
    }

    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    if (newNode == NULL) { return -1; }

    newNode->val = val;

    if (incrNodePrevious == incrNode) { newNode->next = incrNode; *head = newNode; }
    else                              { incrNodePrevious->next = newNode; newNode->next = incrNode; }

    return 0;
}

int main() { return 0; }