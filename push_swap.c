#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     size;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 2)
    {
        //error_check(argc, argv, 1);
        stack_a = ft_create_stack(size, argv, 1);
    }
    //error_check(argc, argv, 0);
    stack_a = ft_create_stack(argc, argv, 0);
    error_doubles_check(stack_a);
    sort_stack(&stack_a, &stack_b);
    return (0);
}
