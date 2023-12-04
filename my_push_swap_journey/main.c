/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:52:39 by pamone            #+#    #+#             */
/*   Updated: 2023/11/30 18:52:39 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_last_element(t_stack *stack_a)
{
    t_stack *temp = stack_a;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    return temp->data;
}

// int ft_required_time(t_stack_b *stack_b, int size)
// {
    // int i = 0;
    // t_stack *temp = stack_b;
    // while()
// }
int main(int argc, char **argv)
{
    if(argc > 1)
    {
        t_stack *stack_a;
        t_stack_b *stack_b;

        stack_a = NULL;
        stack_b = NULL;
        stack_a = ft_parse(argv, argc);
        printf("the stack is null %d\n", ft_count_node(stack_a) );
        if(stack_a ==NULL)
            free(stack_a);
        // if(ft_count_node(stack_a) == 3 && !ft_duplicate(stack_a) && ft_is_sorted(stack_a))
            // ft_sort_three(&stack_a);
        // else if(ft_count_node(stack_a)> 3 && !ft_duplicate(stack_a) && ft_is_sorted(stack_a))
            // ft_sort_stack(&stack_a);
        // if(stack_a->data > stack_a->link->data)
        // {
            // ft_sa(stack_a, 1);
            // ft_rra(&stack_a, 1);
            // ft_ra(&stack_a, 1);
            // ft_sa(stack_a, 1);
        // }
        // 
    if(ft_count_node(stack_a) > 3 && ft_is_sorted(stack_a))
    {
        int i = 0;
        int size = ft_count_node(stack_a);
        t_stack *temp = stack_a;
        while (temp->link->link!= NULL && i < size)
        {
            if(temp->data > temp->link->data)
            { 
                ft_sa(temp, 1);
            }
            if((temp->data < temp->link->data) )
                ft_pb(&temp, &stack_b, 1);
            else
                {
                    ///ft_ra(&temp, 1);
                    ft_rra(&temp, 1);
                }
            i++;
        }
        if(temp->data > temp->link->data)
        { 
            ft_sa(temp, 1);
            ft_pb(&temp, &stack_b, 1);
        }
        stack_a = temp; 

        while (stack_b->link != NULL)
        {
            if(stack_b->data < stack_b->link->data)
                ft_sb(stack_b, 1);
            if(stack_b->data == ft_stack_b_max(stack_b))
                ft_pa(&stack_a, &stack_b, 1);
            else
                ft_rrb(&stack_b, 1);
        }
        ft_pa(&stack_a, &stack_b, 1);
    }  
    
        while (stack_a != NULL)
        {
            printf("The stack A is >>>>> %d <<<<  \n", stack_a->data);
            stack_a = stack_a->link;
        }
        
        //printf(">>>>>>>>>>>> %d <<<<<<<<<<<<<\n", !ft_is_sorted(stack_a));

        //  while (stack_b != NULL)
        // {
            // printf("The stack B is >>>>> %d <<<<  \n", stack_b->data);
            // stack_b = stack_b->link;
        // }
    }
    else
        return (0);
}