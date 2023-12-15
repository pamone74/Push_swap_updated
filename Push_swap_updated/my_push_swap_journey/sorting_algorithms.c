/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:52:31 by pamone            #+#    #+#             */
/*   Updated: 2023/12/02 10:52:31 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	while (stack_a->link != NULL)
	{
		if (stack_a->data > stack_a->link->data)
			return (1);
		stack_a = stack_a->link;
	}
	return (0);
}

int	ft_is_sorted_b(t_stack_b *stack_b)
{
	while (stack_b->link != NULL)
	{
		if (stack_b->data < stack_b->link->data)
			return (0);
		stack_b = stack_b->link;
	}
	return (1);
}

void	ft_sort_three(t_stack **stack_a)
{
	int	top;
	int	middle;
	int	last;

	top = (*stack_a)->data;
	middle = (*stack_a)->link->data;
	last = (*stack_a)->link->link->data;
	if(ft_is_sorted(*stack_a))
	{
	if (top < middle && last > top)
	{
		ft_sa(*stack_a, 1);
		ft_ra(stack_a, 1);
	}
	else if (top > middle && middle > last)
	{
		ft_ra(stack_a, 1);
		ft_sa(*stack_a, 1);
	}
	else if (top > middle && top > last)
		ft_ra(stack_a, 1);
	else if (top < last && middle < last)
		ft_sa(*stack_a, 1);
	else if (top < middle && middle > last)
		ft_rra(stack_a, 1);
	}
}
void ft_sort_three_b(t_stack_b **stack_a)
{
	printf("I am here\n");
	ft_displa_b(*stack_a);
    int top;
    int middle;
    int last;

    top = (*stack_a)->data;
    middle = (*stack_a)->link->data;
    last = (*stack_a)->link->link->data;
if(!ft_is_sorted_b(*stack_a))
{
    // if (top > middle && last < top)
    // {
        // ft_sb(*stack_a, 1);
        // ft_rrb(stack_a, 1);
    // }
    // else if (top < middle && middle < last)
    // {
        // ft_rb(stack_a, 1);
        // ft_sb(*stack_a, 1);
    // }
    // else if (top < middle && top < last)
        // ft_rb(stack_a, 1);
    // else if (top > last && middle > last)
        // ft_sb(*stack_a, 1);
    // else if (top > middle && middle < last)
        // ft_rb(stack_a, 1);
if (top < middle && last > middle)
{
	ft_rb(stack_a, 1);
	ft_sb(*stack_a, 1);
	
}
// else if (top > middle && middle > last)
// {
	// ft_rb(stack_a, 1);
	// ft_sb(*stack_a, 1);
// }
else if (top > middle && top > last)
{
		ft_rrb(stack_a, 1);
		ft_sb(*stack_a,1);

}
else if (top > middle && middle < last)
	ft_rrb(stack_a, 1);
else if (top < middle && top < last)
	ft_rb(stack_a, 1);
else if (top < middle && top > last)
	ft_sb(*stack_a, 1);
}
}


int get_min(t_stack_b **stack)
{
    t_stack_b*temp_node = *stack;
    int min = temp_node->data;
    while (temp_node != NULL)
        {
            if (temp_node->data < min)
                min = temp_node->data;
            temp_node = temp_node->link;
        }
    return min;
}
void	ft_sort_five(t_stack **stack_a)
{
	t_stack_b *stack_b;
	int		i;

	stack_b = NULL;
	i = -1;
	while(++i < 2)
		ft_pb(stack_a, &stack_b, 1);
	if(stack_b != NULL)
	{
		if(stack_b->data < stack_b->link->data)
			ft_sb(stack_b, 1);
	}
	if(ft_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	ft_insert(stack_a, stack_b);
}
// void	ft_sort_all(t_stack **stack_a)
// {
	// t_stack_b *stack_b;
	// t_stack_b *temp_b;
	// int			min;
	// int			total_count_a;
	// int			i;
// 
	// stack_b = NULL;
	////temp = *stack_a;
	// i = 0;
	// total_count_a = ft_count_node(*stack_a);
	// while (i < total_count_a)
	// {
		// ft_pb(stack_a, &stack_b, 1);
		// i++;
	// }
	// temp_b = stack_b;
	// min = get_min(&temp_b);
	// printf("The min is %d\n", min);
	// t_stack_b *node = NULL;
	// ft_push_b(&node, min);
	// stack_b = temp_b;
	// ft_pa(stack_a, &node, 1);
// }
void	ft_insert(t_stack **stack_a, t_stack_b *stack_b)
{
    int i;
    t_stack *tempA = *stack_a; 
    int index; 
    while(stack_b != NULL)
    {
        i = stack_b->data;
        tempA = *stack_a; 
        while (tempA != NULL && i > tempA->data)
            tempA = tempA->link;
        if (tempA != NULL) 
		{
            if (i < tempA->data) 
			{
                   index = ft_get_index(stack_a, tempA->data);
                   ft_insert_at_index_a(stack_a, index, i);
            }
           } else 
		   {
               index = ft_count_node(*stack_a);
               ft_insert_at_index_a(stack_a, index, i);
           }
           stack_b = stack_b->link;
   }
     free(stack_b);
}

int ft_get_index(t_stack **stack, int item)
{
    t_stack *node = *stack;
    int count = 0;
    if(node != NULL)
    {
        while(node != NULL)
        {
            if(node->data == item)
                return count;
            count ++;
            node = node->link;
        }
    }
    return 0;
}

// void	ft_sort_integers(t_stack **stack_a)
// {
	// t_stack_b *stack_b;
	// int			i;
// 
	// stack_b = NULL;
	// if (ft_count_node(*stack_a) == 2 && ft_is_sorted(*stack_a))
		// ft_sa(stack_a, 1);
	// else
	// {
		// stack_b = ft_sort_stack_b(stack_a);
	// }
// 
// }

