#include "queue.h"

#include <stdlib.h>

/* init a queue for tokens */ 
struct queue *queue_init()
{
    struct queue *q = malloc(sizeof(struct queue));

    q -> head = NULL;
    q -> tail = NULL;
    q -> size = 0;

    return q;
}

/* destroy the given queue and their content */
void queue_destroy(struct queue *q)
{
    if (q -> size > 0)
    {
        struct token *t;
        while (q -> size > 1)
        {
            t = q -> head;
            q -> head = t -> next;
            token_destroy(t);
            q -> size -= 1;
        }

        t = q -> head;

        q -> head = NULL;
        q -> tail = NULL;
        q -> size = 0;

        token_destroy(t);
    }
    free(q);
}
 
/* push a token into the queue */
void queue_push(struct queue *q, struct token *t)
{
    if (q == NULL || t == NULL)
    {
        return;
    }
    q -> size += 1;
    if (q -> head == NULL)
    {
        q -> head = t;
    }
    else
    {
        q -> tail -> next = t;
    }
    q -> tail = t;
    t -> next = NULL;
}
  
/* pop a token from the queue, returns NULL if empty */
struct token *queue_pop(struct queue *q)
{
    if (q == NULL || q -> size == 0)
    {
        return NULL;
    }

    struct token *t = q -> head;
    q -> head = t -> next;
    q -> size -= 1;
    t -> next = NULL;

    return t;
}
  
  
/* peek the type of the token at the head of the queue, returns NONE if empty */
enum token_type queue_peek_type(struct queue *q)
{
    if (q == NULL || q -> size == 0)
    {
        return NONE;
    }

    return (q -> head) -> type;
}

/* peek the value of the token at the head of the queue, returns 0 if empty */
double queue_peek_value(struct queue *q)
{
    if (q == NULL || q -> size == 0)
    {
        return 0;
    }

    return (q -> head) -> value;
}
