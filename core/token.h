#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>

enum token_type
{
    MUL,
    DIV,
    PLUS,
    MINUS,
    VALUE,
    NONE,
};

struct token 
{
    enum token_type type;
    double value;
    struct token *next;
};

/* init a token */
struct token *token_init(enum token_type, double value);

/* destroy a token and destroy recusively the next */
void token_destroy(struct token *t);

#endif /* ! TOKEN_H */
