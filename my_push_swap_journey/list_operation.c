/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:51:15 by pamone            #+#    #+#             */
/*   Updated: 2023/12/03 12:51:15 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_last_node_a(t_stack *stack_a)
{
	if (!stack_a)
		return (NULL);
	while (stack_a->link)
		stack_a = stack_a->link;
	return (stack_a);
}
t_stack	*ft_last_node_a(t_stack *stack_a)
{
	if (!stack_a)
		return (NULL);
	while (stack_a->link)
		stack_a = stack_a->link;
	return (stack_a);
}
int	ft_stack_b_min(t_stack_b *stack_b)
{
    int		i;
    i = stack_b->data;
    while (stack_b)
    {
    	if (stack_b->data > i)
    		i = stack_b->data;
    	stack_b = stack_b->link;
    }
    return (i);
}

int	ft_stack_b_max(t_stack_b *stack_b)
{
	int		i;

	i = stack_b->data;
	while (stack_b)
	{
		if (stack_b->data > i)
			i = stack_b->data;
		stack_b = stack_b->link;
	}
	return (i);
}
int	ft_find_index(t_stack_b *stack_b, int nbr)
{
	int		i;

	i = 0;
	while (stack_b->link != nbr)
	{
		i++;
		stack_b = stack_b->link;
	}
	stack_b->index = 0;
	return (i);
}