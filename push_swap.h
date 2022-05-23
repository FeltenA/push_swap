#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int     num;
    struct s_stack  *next;
}   t_stack;

typedef struct s_chunk
{
    int max;
    int step;
    int size;
}   t_chunk;

#endif