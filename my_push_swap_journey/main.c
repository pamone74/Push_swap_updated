/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:52:39 by pamone            #+#    #+#             */
/*   Updated: 2023/11/30 18:52:39 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        t_stack *stack_a;

        stack_a = NULL;
        stack_a = ft_parse(argv, argc);
        //printf("the stack is null %d\n", ft_is_sorted(stack_a) );
        // if(stack_a ==NULL)
            // free(stack_a);
        if(ft_count_node(stack_a) == 3 && !ft_duplicate(stack_a) && ft_is_sorted(stack_a))
            ft_sort_three(&stack_a);
        else if(ft_count_node(stack_a)== 5 && !ft_duplicate(stack_a) && ft_is_sorted(stack_a))
            ft_sort_five(&stack_a);
        
        while (stack_a != NULL)
        {
            printf("The stack A is >>>>> %d <<<<  \n", stack_a->data);
            stack_a = stack_a->link;
        }
        
    }
    else
        return (0);
}