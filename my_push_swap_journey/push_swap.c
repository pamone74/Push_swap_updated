/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:33:50 by pamone            #+#    #+#             */
/*   Updated: 2023/11/29 01:33:50 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_overflow(int n)
{
	if (n == INT_MIN || n == INT_MAX)
		return (1);
	return (0);
}

void	ft_whitespace(const char **str)
{
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
		(*str)++;
}

int	ft_sign(const char **str)
{
	int	sign;

	sign = 1;
	ft_whitespace(str);
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	digit;

	sign = ft_sign(&str);
	result = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		digit = *str - '0';
		if (result > INT_MAX / 10 || (result == INT_MAX / 10
				&& digit > INT_MAX % 10))
		{
			if (sign == 1)
				return (2147483647);
			else
				return (-2147483648);
		}
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}

// t_stack*	push_swap(char *str)
// {
	// t_stack	*stack_a;
// 
	// stack_a = NULL;
	// if (ft_check_ascii(str) && ft_check_overflow(ft_atoi(str)))
		// ft_error();
	// else
	// {
		// ft_push(&stack_a, ft_atoi(str));
		// str ++;
	// }
	// while (*str)
	// {
		// if (ft_check_ascii(str))
			// ft_error();
		// else if (ft_check_overflow(ft_atoi(str)))
			// ft_error();
		// ft_append_node_a(&stack_a, ft_atoi(str));
		// str++;
	// }
// }
// 