#include "stack.h"

#include <stdlib.h>


/* init a stack for tokens */
struct stack* stack_init()
{
    struct stack *s = malloc(sizeof(struct stack));
    s -> top = NULL;
    s -> size = 0;
    
    return s;
}

/* destroy the given stack and their content */
void stack_destroy(struct stack *s)
{
    if (s -> size > 0)
    {
        struct token * t;
        while (s -> size > 1)
        {
            s -> size -= 1;
            t = s -> top;
            s -> top = t -> next;
            token_destroy(t);
        }

        token_destroy(s -> top);
        s -> size = 0; 
    }

    free(s);
}


/* push a token into the stack */
void stack_push(struct stack* s, struct token* t)
{
    if (s == NULL || t == NULL)
    {
        return;
    }
    s -> size += 1;
    t -> next = s -> top;
    s -> top = t;
}

/* pop a token from the stackm returns NULL if empty */
struct token *stack_pop(struct stack *s)
{
    if (s == NULL || s -> size == 0)
    {
        return NULL;
    }
    struct token *t = s -> top;
    s -> top = t -> next;
    s -> size -= 1;
    t -> next = NULL;

    return t;
}


/* peek the value of the token on the top, returns 0 if empty */
double stack_peek_value(struct stack *s)
{
    if (s == NULL || s -> size == 0)
    {
        return 0;
    }

    return (s -> top) -> value;
}

/* peek the type of the token on the top, returns NONE if empty */
enum token_type stack_peek_type(struct stack *s)
{
    if (s == NULL || s -> size == 0)
    {
        return NONE;
    }

    return (s -> top) -> type;
}

