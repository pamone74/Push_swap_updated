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
t_stack_b	*ft_last_node_b(t_stack_b *stack_b)
{
	if (!stack_b)
		return (NULL);
	while (stack_b->link)
		stack_b= stack_b->link;
	return (stack_b);
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

int	ft_stack_a_min(t_stack *stack_a)
{
    int		i;
    i = stack_a->data;
    while (stack_a)
    {
    	if (stack_a->data < i)
    		i = stack_a->data;
    	stack_a = stack_a->link;
    }
    return (i);
}

int	ft_stack_a_max(t_stack *stack_a)
{
	int		i;

	i = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data > i)
			i = stack_a->data;
		stack_a = stack_a->link;
	}
	return (i);
}
int	ft_find_index_b(t_stack_b *stack_b, int nbr)
{
	t_stack_b *tta = stack_b;
	printf("\nThis is function ft_find_index_b and. nbr is %d\n\n", nbr);
	while (tta != NULL)
	{
	   printf("The stack_a in ft_sort_a >> %d <<<\n", tta->data);
	   tta = tta->link;
	}
		
	int		i;

	i = 0;
	while (stack_b->data != nbr)
	{
		printf("The stac_b data is >>>>>>> %d <<<<<<<< \n", stack_b->data);
		i++;
		stack_b = stack_b->link;
	}
	stack_b->index = 0;
	return (i);
}

int	ft_find_index_a(t_stack *stack_a, int nbr)
{
	int		i;

	i = 0;
	while (stack_a->data != nbr)
	{
		i++;
		stack_a = stack_a->link;
	}
	stack_a->index = 0;
	return (i);
}