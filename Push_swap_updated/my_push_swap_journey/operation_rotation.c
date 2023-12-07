/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:38:46 by pamone            #+#    #+#             */
/*   Updated: 2023/12/03 12:38:46 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function calculates how many times we should rotate the stacks together.
// Because after a certain amoun of rotate, we will proceed only with one stack
// rotation. Since here we have reverse rotate,rather than index number,
// we check reverse index number which is 
// calculated by list_size - index_number.
int	ft_rotate_rra_rrb(t_stack *stack_a, t_stack_b *stack_b, int n)
{
	int	i;

	i = 0;
	if (ft_find_place_b(stack_b, n))
		i = ft_count_node_b(stack_b) - ft_find_place_b(stack_b, n);
	if ((i < (ft_count_node(stack_a) - ft_find_index_a(stack_a,n))) && ft_find_index_a(stack_a, n))
		i = ft_count_node(stack_a) - ft_find_index_a(stack_a, n);
	return (i);
}

int	ft_find_place_b(t_stack_b *stack_b, int number)
{
	int			i;
	t_stack_b	*tmp;

	i = 1;
	if (number > stack_b->data && number < ft_last_node_b(stack_b)->data)
		i = 0;
	else if (number > ft_stack_b_max(stack_b) || number < ft_stack_b_min(stack_b))
		i = ft_find_index_b(stack_b, ft_stack_b_max(stack_b));
	else
	{
		tmp = stack_b->link;
		while (stack_b->data < number || tmp->data > number)
		{
			stack_b = stack_b->link;
			tmp = stack_b->link;
			i++;
		}
	}
	return (i);
}

int	ft_find_place_a(t_stack *stack_a, int number)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (number > stack_a->data && number < ft_last_node_a(stack_a)->data)
		i = 0;
	else if (number > ft_stack_a_max(stack_a) || number < ft_stack_a_min(stack_a))
		i = ft_find_index_a(stack_a, ft_stack_a_max(stack_a));
	else
	{
		tmp = stack_a->link;
		while (stack_a->data < number || tmp->data > number)
		{
			stack_a = stack_a->link;
			tmp = stack_a->link;
			i++;
		}
	}
	return (i);
}
/*
This will calculate the number of times it is required to
rotate the stacks together. After a certain amount of rotate,
we will proceed with just a stack rotation.
*/
int	ft_rotate_ra_rb(t_stack *stack_a, t_stack_b *stack_b, int n)
{
	int	i;

	i = ft_find_place_b(stack_b, n);
	if (i < ft_find_index_a(stack_a, n))
		i = ft_find_index_a(stack_a, n);
	return (i);
}
// This function do same calculations for rra+rb case.
int	ft_rotate_rra_rb(t_stack *stack_a, t_stack_b *stack_b, int n)
{
	int	i;

	i = 0;
	if (ft_find_index_a(stack_a, n))
		i = ft_count_node(stack_a) - ft_find_index_a(stack_a, n);
	i = ft_find_place_b(stack_b, n) + i;
	return (i);
}

int	ft_rotate_ra_rrb(t_stack *stack_a, t_stack_b *stack_b, int n)
{
	int	i;

	i = 0;
	if (ft_find_place_b(stack_b, n))
		i = ft_count_node_b(stack_b) - ft_find_place_b(stack_b, n);
	i = ft_find_index_a(stack_a, n) + i;
	return (i);
}

// ra + rb

int	ft_rotate_ra_rb_a(t_stack *stack_a, t_stack_b *stack_b, int n)
{
	int	i;

	i = ft_find_place_a(stack_a, n);
	if (i < ft_find_index_b(stack_b, n))
		i = ft_find_index_b(stack_b, n);
	return (i);
}

// rra + rrb

int	ft_rotate_rra_rrb_a(t_stack *stack_a, t_stack_b *stack_b, int n)
{
	int	i;

	// t_stack  *tta = stack_a;
	// printf("\nThis is function ft_rotate_rra_rrb_a\n\n");
	// while (tta != NULL)
	// {
	//    printf("The stack_a in ft_sort_a >> %d <<<\n", tta->data);
	//    tta = tta->link;
	// }
	i = 0;
	if (ft_find_place_a(stack_a, n))
	{
		i = ft_count_node(stack_a) - ft_find_place_a(stack_a, n);
		printf(">>>>>>> %d <<<<<< and n is >>>> %d <<< \n", i, n);
		t_stack  *tta = stack_a;
		printf("\nThis is function ft_rotate_rra_rrb_a 01 \n\n");
		while (tta != NULL)
		{
		   printf("The stack_a in ft_sort_a >> %d <<<\n", tta->data);
		   tta = tta->link;
		}
	}
	printf("\n\nthe value of i is === %d\n", i);
	printf("\n\nthe value of b_size is === %d\n", ft_count_node_b(stack_b));
	printf("\n\nthe value of index_b is === %d\n", ft_find_index_b(stack_b,n));
	//printf("\n\nthe value of i is === %d\n", i);
	if ((i < (ft_count_node_b(stack_b) - ft_find_index_b(stack_b,n))) && ft_find_index_b(stack_b, n))
	{
		i = ft_count_node_b(stack_b) - ft_find_index_b(stack_b, n);
		t_stack  *tta = stack_a;
		printf("\nThis is function ft_rotate_rra_rrb_a 02\n\n");
		while (tta != NULL)
		{
		   printf("The stack_a in ft_sort_a >> %d <<<\n", tta->data);
		   tta = tta->link;
		}
		
	}
	
	return (i);
}

// ra + rrb

int	ft_rotate_ra_rrb_a(t_stack *stack_a, t_stack_b *stack_b, int n)
{
	int	i;

	i = 0;
	if (ft_find_index_b(stack_b, n))
		i = ft_count_node_b(stack_b) - ft_find_index_b(stack_b, n);
	i = ft_find_index_a(stack_a, n) + i;
	return (i);
}

// rra + rb
int	ft_rotate_rra_rb_a(t_stack *stack_a, t_stack_b *stack_b, int n)
{
	int	i;

	i = 0;
	if (ft_find_place_a(stack_a, n))
		i = ft_count_node(stack_a) - ft_find_place_a(stack_a, n);
	i = ft_find_index_b(stack_b, n) + i;
	return (i);
}
