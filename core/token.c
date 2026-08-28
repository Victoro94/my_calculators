#include "token.h"

#include <stdlib.h>

/* init a token */
struct token *token_init(enum token_type type, double value)
{
    struct token *t = malloc(sizeof(struct token));
    t -> type = type;
    t -> value = value;
    t -> next = NULL;

    return t;
}

/* destroy a token and recusively destroy the next */
void token_destroy(struct token *t)
{
    if (t != NULL)
    {
        token_destroy(t -> next);
    }
    free(t);
}
