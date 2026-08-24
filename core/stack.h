#ifndef STACK_H
#define STACK_H

#include "token.h"

struct stack 
{
    struct token* top;
    struct token *bottom;
    size_t size;
};


/* init a stack for tokens */
struct stack* stack_init();

/* destroy the given stack and their content */
void stack_destroy(struct stack *s);


/* push a token into the stack */
void stack_push(struct stack* s, struct token* t);

/* pop a token from the stackm returns NULL if empty */
struct token *stack_pop(struct stack *s);


/* peek the value of the token on the top, returns 0 if empty */
double *stack_peek_value(struct stack *s);

/* peek the type of the token on the top, returns NONE if empty */
enum token_type *stack_peek_type(struct stack *s);

#endif /* ! STACK_H */
