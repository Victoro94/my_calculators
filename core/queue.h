#ifndef QUEUE_H
#define QUEUE_H

#include "token.h"

struct queue 
{
    struct token *head;
    struct token *tail;
    size_t size;
};

/* init a queue for tokens */
struct queue *queue_init();

/* destroy the given queue and their content */
void queue_destroy(struct queue *q);


/* push a token into the queue */
void queue_push(struct queue *q, struct token *t);

/* pop a token from the queue, returns NULL if empty */
struct token *queue_pop(struct queue *q);


/* peek the type of the token at the head of the queuem returns NONE if empty */
enum token_type queue_peek_type(struct queue *q);

/* peek the value of the token at the head of the queue, returns 0 if empty */
double queue_peek_value(struct queue *q);

#endif /* ! QUEUE_H */
