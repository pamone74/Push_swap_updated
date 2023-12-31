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

int ft_pos_rank_one(t_stack *stack_a_a, int item)
{
    int i = 0;
    t_stack *stack_a = stack_a_a;
    while(stack_a && stack_a->data != item)
    {
        stack_a = stack_a->link;
        i++;
    }
    return (i);
}
void ft_display(t_stack *stak)
{
    t_stack* stack_a = stak;
    while (stack_a != NULL)
    {
     printf("The stack A is >>>>> %d <<<<  \n", stack_a->data);
     stack_a = stack_a->link;
    }
}

void ft_displa_b(t_stack_b *stak)
{
    t_stack_b* stack_a = stak;
    while (stack_a != NULL)
    {
     printf("The stack B is >>>>> %d <<<<  \n", stack_a->data);
     stack_a = stack_a->link;
    }
}
int ft_second_last(t_stack* stack_a_a) {
    t_stack *stack_a =  stack_a_a;
    if (stack_a == NULL || stack_a->link == NULL) {
        return INT_MIN;
    }

    int smallest = INT_MAX;
    int second_smallest = INT_MAX;

    while (stack_a != NULL) {
        if (stack_a->data < smallest) {
            second_smallest = smallest;
            smallest = stack_a->data;
        } else if (stack_a->data < second_smallest && stack_a->data != smallest) {
            second_smallest = stack_a->data;
        }

        stack_a = stack_a->link;
    }

    if (second_smallest == INT_MAX) {
        return INT_MIN;
    } else {
        return second_smallest;
    }
}

// int ft_second_last(t_stack *stack_a)
// {
    // int i = 0;
    // while(stack_a && stack_a->data > ft_stack_a_min(stack_a) && stack_a->data != ft_stack_a_max(stack_a))
    // {
        // stack_a = stack_a->link;
        // i++;
    // }
    // return (stack_a->data);
// }
// int main(int argc, char **argv)
// {
    // if(argc > 1)
    // {
        // t_stack *stack_a;
        // t_stack_b *stack_b;
// 
        // stack_a = NULL;
        // stack_b = NULL;
        // stack_a = ft_parse(argv, argc);
        // printf("the stack is null %d\n", ft_count_node(stack_a) );
        // if(stack_a ==NULL)
            // free(stack_a);
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
    // if(ft_count_node(stack_a) > 3 && ft_is_sorted(stack_a) && !ft_duplicate(stack_a))
    // {
        // int i = 0;
        // int size = ft_count_node(stack_a);
        // t_stack *temp = stack_a;
        //int max = ft_stack_a_max(stack_a);
        // printf("The Pos Rank one is %d\n", ft_pos_rank_one(temp, ft_stack_a_min(temp)));
        // printf("The Pos Rank two is %d\n", ft_second_last(temp));
        // while (temp->link->link!= NULL && i < size)
        // {
            // if(temp->data > temp->link->data)
            // { 
                // ft_sa(temp, 1);
            // }
            // if((temp->data < temp->link->data))
                // ft_pb(&temp, &stack_b, 1);
            // else
                // {
                    // ft_ra(&temp, 1);
                    // ft_rra(&temp, 1);
                // }
            // i++;
        // }
        // if(temp->data > temp->link->data)
        // { 
            // ft_sa(temp, 1);
            // ft_pb(&temp, &stack_b, 1);
        // }
        // stack_a = temp; 

        // while (stack_b->link != NULL)
        // {
            // if(stack_b->data < stack_b->link->data)
                // ft_sb(stack_b, 1);
            // if(stack_b->data == ft_stack_b_max(stack_b))
                // ft_pa(&stack_a, &stack_b, 1);
            // else
                // ft_rrb(&stack_b, 1);
        // }
        // ft_pa(&stack_a, &stack_b, 1);
    // }  
    
        // while (stack_a != NULL)
        // {
            // printf("The stack A is >>>>> %d <<<<  \n", stack_a->data);
            // stack_a = stack_a->link;
        // }
        // 
       // printf(">>>>>>>>>>>> %d <<<<<<<<<<<<<\n", !ft_is_sorted(stack_a));

        //  while (stack_b != NULL)
        // {
            // printf("The stack B is >>>>> %d <<<<  \n", stack_b->data);
            // stack_b = stack_b->link;
        // }
    // }
    // else
        // return (0);
//}