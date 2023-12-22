/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:15:36 by pamone            #+#    #+#             */
/*   Updated: 2023/12/16 23:42:16 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
    
	while ((*s1 || *s2) )
	{
		if (*s1 != *s2)
		{
			return ((unsigned char) *s1 - (unsigned char)*s2);
		}
		s1 ++;
		s2 ++;
	}
	return (0);
}
int ft_comapare_command(char *cml, t_stack **stack_a, t_stack_b **stack_b)
{
    if (ft_strcmp(cml, "pa") == 0)
        ft_pa(stack_a, stack_b, 0);
    if (ft_strcmp(cml, "sa") == 0)
        ft_sa(*stack_a, 0);
    if (ft_strcmp(cml, "ra") == 0)
        ft_ra(stack_a, 0);
    if (ft_strcmp(cml, "rra") == 0)
        ft_rra(stack_a, 0);
    if (ft_strcmp(cml, "pb") == 0)
        ft_pb(stack_a,stack_b, 0);
    if (ft_strcmp(cml, "rb") == 0)
        ft_rb(stack_b, 0);
    if (ft_strcmp(cml, "rrb") == 0)
        ft_rrb(stack_b, 0);
    if (ft_strcmp(cml, "sa") == 0)
        ft_sb(*stack_b, 0);
    if (ft_strcmp(cml, "ss") == 0)
        ft_ss(*stack_a, *stack_b, 0);
    if (ft_strcmp(cml, "rrr") == 0)
        ft_rrr(stack_b, stack_a, 0);
    if (ft_strcmp(cml, "ss") == 0)
        ft_rr(stack_a, stack_b, 0);
    return (1);
}

void    ft_print(t_stack **stack_a, t_stack_b **stack_b)
{
    if (!ft_is_sorted(*stack_a))
        ft_putstr("OK");
    else
        ft_putstr("KO");
    ft_free_stack(*stack_a);
    free(stack_b);
}

int main(int argc, char *argv[])
{
    t_stack     *stack_a;
    t_stack_b   *stack_b;
    char        *cml;

    if (argc > 1)
    {
        stack_a = NULL;
        stack_a = NULL;
        ft_parse(&stack_a,argv);
        if (ft_is_sorted(stack_a) && !ft_duplicate(stack_a))
        {
            int i = 0;
            while (i < ft_count_node(stack_a))
            {
                cml = get_next_line(1);
                ft_comapare_command(cml,&stack_a, &stack_b);
                free(cml);
                i++;
            }
        }
        else
	        ft_error();
    }
}