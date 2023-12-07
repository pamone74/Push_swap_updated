/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:30:50 by pamone            #+#    #+#             */
/*   Updated: 2023/12/01 14:30:50 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_build_tail(t_stack **headref, int data)
{
    t_stack *tail;
    if((*headref) == NULL)
        ft_push(headref, data);
    else
    {
        tail = *headref;
        while(tail->link != NULL)
            tail = tail->link;
        ft_push(&(tail->link), data);
    }
}

void	ft_free_str(char **string)
{
	char	*temp;

	if(!string)
		return ;
	while (*string)
	{
		temp = *string;
		string++;
		free(temp);
	}
	*string = NULL;
}
t_stack	*ft_parse(char *args[], int argc)
{
	t_stack		*stack_a;
	int			i;
	char		*nor = ft_strjoin(args, argc);
	char		**str = ft_split(nor, ' ');		
	stack_a = NULL;
	while (str[i] != NULL)
	{

		if(ft_check_ascii(str[i]) || ft_check_overflow(ft_atoi(str[i])))
		{
			ft_error();
			//ft_free_str(args);
			//free(args);
			//free(args[i]);
			return 0;
		}	
		else
			ft_build_tail(&stack_a, ft_atoi((*ft_split(str[i], ' '))));
		i++;
	}
	return (stack_a);
}

t_stack *ft_split_parser(char **argv)
{
	t_stack *stack_a;
	char	**temp;
	int		i;

	stack_a = NULL;
	i = 0;
	temp = ft_split(argv[1], ' ');
	while (temp[i] != NULL)
	{
		if(ft_check_ascii(temp[i]) || ft_check_overflow(ft_atoi(temp[i])))
		{
			ft_error();

			free(temp);
			free(temp[i]);
		}	
		else
			ft_build_tail(&stack_a, ft_atoi(temp[i]));
		i++;
	}
	ft_free_str(temp);
	free(temp);
	return (stack_a);
}
