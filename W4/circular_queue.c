#include <stdlib.h>

typedef struct node
{
  struct node* next;
  int value;
} node_t;

typedef struct queue
{
  struct node* tail;
  int size;
} queue_t  ;

/*
* Add @val value at the head of the @q queue
*
* @val : the value to enqueue
* @q   : the queue
*
* @return 0 if no error, -1 otherwise
*
* pre : The queue q will always be valid, you don't need to handle the NULL case.
*/
int enqueue(queue_t* q, int val)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (new_node == NULL) { return -1; }

    new_node->value = val;

    if (q->size == 0)
    {
        new_node->next = new_node;
        q->tail = new_node;
    } else
    {
        node_t *tail = q->tail;
        new_node->next = tail->next;
        tail->next = new_node;
    }

    (q->size)++;
    return 0;
}

/*
* Remove the node at the tail of the @q queue and return the value of this node
* @q       : the queue
* @return  : the value at the tail
*
* pre      : The given queue will always be valid, you do not need to handle the NULL case.
*/
int dequeue(queue_t* q)
{
    int returned_value = (q->tail)->value;

    if (q->size > 1)
    {
        node_t *new_tail = q->tail;
        for (int i = 0; i < q->size - 1; i++) { new_tail = new_tail->next; }

        new_tail->next = (q->tail)->next;
        (q->tail)->next = NULL;

        free(q->tail);
        q->tail = new_tail;
    } else
    {
        (q->tail)->next = NULL;

        free(q->tail);
        q->tail = NULL;
    }

    (q->size)--;
    return returned_value;
}

int main() { return 0; }