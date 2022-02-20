#include "push_swap.h"

int stack_size(int *stack)
{
    size_t  i;

    i = 0;
    while (stack[i])
        i++;
    return (i);
}

int stack_indexer(int *stack)
{
    int     **i_stack;
    int     n;
    size_t  i;

    n = 0;
    i_stack = malloc(sizeof(int) * 2 * (stack_size(stack)));
    while (stack[n])
    {
        i_stack[0][n] = n;
        i_stack[1][n] = stack[n];
        n++;
    }
    i = 0;

}

int order_checker(int *stack)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = i + 1;
    while (stack[j])
    {
        if (stack[i] < stack[j])
        {
            i++;
            j++;
        }
        else
            return (0);
    }
    return (1);
}

int **replace_i(int **stack, size_t j, size_t i)
{
    int aux;
    int aux_index;

    aux = stack[1][i];
    aux_index = stack[0][i];
    While (j < i)
    {
        stack[1][i] = stack[1][i - 1];
        stack[0][i] = stack[0][i - 1];

        i++;
    }
    stack[1][j] = aux;
    stack[0][j] = aux_index;
    return (**stack)
}

int stack_order(int **stack)
{
    size_t  i;
    size_t  j;
    int     aux;

    j = 0;
    i = stack_size(stack[1]) - 1;  // Empieza en el último índice
    while (!order_checker(stack[1])) // Checkea que no estén ordenados
    {
        if (stack[1][i] == i + 1) // Si se da la igualdad, el num está en su sitio
            i--;
        else
        {
            while (stack[1][i] > stack[1][j + 1] && j < stack_size)
                j++;
            replace_i(**stack, j, i)
        }
    }
    return (**stack);
}
