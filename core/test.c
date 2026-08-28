#include "stack.h"
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 64

/* simple lookup table for enum to char* */
char* lookup_table(struct token *t)
{
    char* res = calloc(BUFFER_SIZE,sizeof(char));
    switch (t -> type)
    {
        case MUL :
            res[0] = '*';
            break;
        case DIV :
            res[0] = '/';
            break;
        case PLUS :
            res[0] = '+';
            break;
        case MINUS :
            res[0] =  '-';
            break;
        case VALUE :
            snprintf(res,BUFFER_SIZE,"%f",t->value);
            break;
        default :
            res[0] = 'N';
            res[1] = 'O';
            res[2] = 'N';
            res[3] = 'E';

    }
    return res;
}

/* recursive funtion of token_print */
void token_print_rec(struct token *t)
{
    if (t != NULL)
    {
        printf("[");
        char *tmp = lookup_table(t);
        printf("%s",tmp);
        free(tmp);
        printf("]");
        token_print_rec(t->next);
    }

}

/* print tokens pointed by t separated by "[]" */
void token_print(struct token *t)
{
    fflush(stdout);
    printf("token :");
    token_print_rec(t);
    puts("");
    fflush(stdout);
}

int main(void)
{
    struct token *t = token_init(VALUE,1.0);
    struct token *t1 = token_init(VALUE,2.0);
    struct token *t2 = token_init(VALUE,3.0);

    t -> next = t1;
    t1 -> next = t2;

    token_print(t);

    t -> next = NULL;
    t1 -> next = NULL;

    /* stack tests */
    printf("stack tests :\n");
    struct stack *s = stack_init();

    stack_push(s,t);
    stack_push(s,t1);
    stack_push(s,t2);
    token_print(stack_pop(s));
    token_print(stack_pop(s));
    token_print(stack_pop(s));

    stack_destroy(s);
    
    /* queue tests */
    printf("queue tests :\n");
    struct queue *q = queue_init();
    queue_push(q,t);
    queue_push(q,t1);
    queue_push(q,t2);

    token_print(queue_pop(q));
    token_print(queue_pop(q));
    token_print(queue_pop(q));

    queue_destroy(q);
   
    

    token_destroy(t);
    token_destroy(t1);
    token_destroy(t2);
    return 0;
}
