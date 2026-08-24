#ifndef TOKEN_H
#define TOKEN_H

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
};

/* init a token */
struct token *token_init(enum token_type, double value);

/* destroy a token */
void token_destroy*(struct token *t);

#endif /* ! TOKEN_H */
