/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:10:55 by pamone            #+#    #+#             */
/*   Updated: 2023/12/03 12:10:55 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
This function takes stack A and push integers from stack A to stack B until there are only three items left.
First check if the list size is five and this is how it is done, the conditional if statement if (ft_count_node(*stack_a) > 3 && ft_is_sorted(*stack_a)) make sures there are more than three elements in stack A and it is not sorted. 
if the condition is true, i call ft_pb() that will pop the top element from A and push it to B. This is done two times purposely to check if the elements are five. but if the elements are greater than five, then we shall sort B till we reach where there are only three elemenst left in stack A

*/
t_stack_b *ft_sort_stack_b(t_stack **stack_a)
{
    t_stack_b *stack_b;

    stack_b = NULL;
    if (ft_count_node(*stack_a) > 3 && ft_is_sorted(*stack_a))
        ft_pb(stack_a, &stack_b, 1);
    if (ft_count_node(*stack_a) > 3 && ft_is_sorted(*stack_a))
        ft_pb(stack_a, &stack_b, 1);
    if (ft_count_node(*stack_a) > 3 && ft_is_sorted(*stack_a))
        ft_sort_stack_b_three(stack_a, &stack_b);
}

void    ft_sort_stack_b_three(t_stack **stack_a, t_stack_b **stack_b)
{
    int i;
    t_stack *temp_node;

    while (ft_count_node(*stack_a) > 3 && ft_is_sorted(*stack_a))
    {
        i = ft_flexible_operation(*stack_a, *stack_b);
    }
}

int ft_flexible_operation(t_stack *stack_a, t_stack_b *stack_b)
{
    
}