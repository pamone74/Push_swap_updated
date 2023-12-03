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

int	ft_rotate_rra_rrb(t_stack *stack_a, t_stack_b *stack_b, int number)
{
	int	i;

	i = 0;
	if (ft_get_index_b(stack_b, number))
		i = ft_count_node_b(stack_b) - ft_get_index_b(stack_b, number);
	if ((i < ft_count_node(stack_a) - ft_get_index(stack_a,number)))
}
int	ft_find_place_a(t_stack *stack_b, int number)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (number > stack_b->nbr && number < ft_lstlast(stack_b)->nbr)
		i = 0;
	else if (number > ft_stack_b_max(stack_b) || number < ft_stack_b_min(stack_b))
		i = ft_find_index(stack_b, ft_stack_b_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < number || tmp->nbr > numberh)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}