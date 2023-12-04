/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:16:12 by pamone            #+#    #+#             */
/*   Updated: 2023/12/03 20:16:12 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_stack(t_stack **stack_a)
{
    t_stack_b *stack_b;
    int        i;

    // t_stack *tta = *stack_a;
    // while (tta != NULL)
    // {
    //    printf("The stack_a is >> %d <<<\n", tta->data);
    //    tta = tta->link;
    // }
    stack_b = NULL;
    if (ft_count_node(*stack_a) == 2)
        ft_sa(*stack_a, 1);
    else
    {
        stack_b = ft_sort_stack_b(stack_a);
        t_stack_b *tt = stack_b;
        while (tt != NULL)
        {
           printf("The stack_b is in ft_sort_stack  >> %d <<<\n", tt->data);
           tt = tt->link;
           
        }
        t_stack *tta = *stack_a;
        stack_a = ft_sort_stack_a(stack_a, &stack_b);
        while (tta != NULL)
        {
           printf("The stack_a is >> %d <<<\n", tta->data);
           tta = tta->link;
        }
        
        
        i = ft_find_index_a(*stack_a, ft_stack_a_min(*stack_a));
        printf("The value of i is %d ", i);
        printf("\nThe value of min is %d \n", ft_stack_a_min(*stack_a));
       //printf("The value of i is %d ", i)
        if (i < ft_count_node(*stack_a) - i)
        {
            while ((*stack_a)->data != ft_stack_a_min(*stack_a))
                ft_ra(stack_a, 1);
        }
        else
        {
            while ((*stack_a)->data != ft_stack_a_min(*stack_a))
                ft_rra(stack_a, 1);
        }
        
        
    }
    
}