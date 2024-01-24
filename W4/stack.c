#include <stdlib.h>

struct node
{
    struct node *next;
    char *name;
};

/**
* Remove the top element of the stack and return its content.
*
* @head : pointer to the top of the stack
* @result : pointer to store the popped element
*
* @return 0 if no error, 1 otherwise
*
* pre : @result contains a null-terminated correct string
* post : @result contains the string @name from the element at the top of the stack
*/

int pop(struct node **head, char *result)
{
    if (result == NULL) { return 1; }

    if (head == NULL || *head == NULL) { return 0; }

    struct node *first = *head;
    *head = first->next;

    int i = 0;
    while (first->name[i] != '\0')
    {
        result[i] = first->name[i];
        i++;
    }
    result[i] = first->name[i];

    free(first->name);
    free(first);

    return 0;
}

/**
* Add @name at the "top" of the stack.
*
* @head : pointer to the top of the stack
* @name : the string to be placed in the element at the top of the stack
*
* @return 0 if no error, 1 otherwise
*/

int push(struct node **head, const char *value)
{
    if ((value == NULL) || (head == NULL)) { return 1; }

    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {  return 1; }
    new_node->next = NULL;

    int length_value = strlen(value);
    new_node->name = (char *) malloc((length_value + 1) * sizeof(char));
    if (new_node->name == NULL) { return 1; }

    for(int i = 0; i <= length_value; i++) { new_node->name[i] = value[i]; }

    if (*head == NULL) { *head = new_node;}
    else
    {
        new_node->next = *head;
        *head = new_node;
    }
    
    return 0;
}

int main() { return 0; }