/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_helper_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:06:19 by pamone            #+#    #+#             */
/*   Updated: 2023/11/29 15:06:19 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack_b **stack_b, t_stack **stack_a, int flag)
{
	ft_rra(stack_a, flag);
	ft_rrb(stack_b, flag);
}

int	ft_is_integer(int n)
{
	return (n >= '0' && n <= '9');
}

void	ft_error(void)
{
	ft_putstr("Error");
	return ;
}

int	ft_duplicate(t_stack *stack_a)
{
	t_stack	*new_node;
	t_stack	*runner;

	new_node = stack_a;
	if (new_node == NULL)
		return (1);
	while (new_node != NULL)
	{
		runner = new_node->link;
		while (runner != NULL)
		{
			if (new_node->data == runner->data)
				return (1);
			runner = runner->link;
		}
		new_node = new_node->link;
	}
	return (0);
}

int	ft_check_ascii(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_is_integer(str[i]))
			return (1);
		i++;
	}
	return (0);
}
