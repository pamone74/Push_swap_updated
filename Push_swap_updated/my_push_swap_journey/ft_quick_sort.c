/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 04:00:18 by pamone            #+#    #+#             */
/*   Updated: 2023/12/15 17:03:22 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_sort.h"
void ft_from_b_to_a(t_stack_b **stak_b, t_stack **stack_a);
//int    ft_sort_fiv(t_stack **stack_a, int len, t_stack_b **stack_b);
int ft_quick_sort_b(t_stack **stack_a, t_stack_b **stack_b, int len);
void ft_push_sort_three(t_stack_b **stack_b, t_stack **stack_a, int len);
int ft_is_less_b(t_stack_b *stack_a, int median);
int ft_is_less(t_stack *stack_a, int median);
t_stack *getTail(t_stack *cur)
{
    while (cur != NULL && cur->link != NULL)
        cur = cur->link;
    return cur;
}
//  here the sorting happens exclusive of the end node
// int    ft_sort_a(t_stack **stack_a, t_stack_b **stack, int len)
// {
    // int median;
    // int num_ls;
    // int pushed = 0;
    // num_ls = len;
    // median = ft_get_median(*stack_a);
    // if(!ft_is_sorted(*stack_a))
    // {
        // if(ft_count_node(*stack_a) <= 3)
        // {
            // if(ft_count_node(*stack_a)== 2 && (*stack_a)->data > (*stack_a)->link->data )
                // ft_sa(*stack_a, 1);
            // else
                // ft_sort_three(stack_a);
            // return 0;
        // }
            //  while (len != num_ls / 2 + num_ls % 2)
            //  {
                //  if((*stack_a)->data < median && len --)
                    //  ft_pb(stack_a, &stack, 1);
                // else if(ft_is_less(stack_a, median))
                // {
                    //    ft_ra(stack_a, 1);
                // pushed ++;
                // }
                // else 
                    // break;
                // }    
            // while (num_ls / 2 + num_ls % 2 != ft_count_node_b(stack) && pushed --)
            // {    
                    //  ft_rra(stack_a, 1);
            // }
            // ft_sort_a(stack_a, stack, num_ls / 2 + num_ls % 2);
        // }
        // return 1;
// }
// void    ft_sort_b(t_stack **stack_a, t_stack_b **stack_b, int len)
// {
    // int median;
    // int num_ls;
    // int pushed = 0;
    // num_ls = len;
    // median =  ft_get_median_b(*stack_b);
    // if(ft_is_sorted_b(*stack_b))
    // {
        // while(len--)
            // ft_pa(stack_a, stack_b, 1);
    // }
    // if(len <= 3){
        // ft_push_sort_three(stack_b, stack_a, len);
        // return;
    // }
    // while(len != num_ls / 2)
    // {
        // if((*stack_b)->data >= median && len --)
            // ft_pa(stack_a, stack_b, 1);
        // else if(ft_is_less_b(*stack_b, median))
        // {
            // ft_rb(stack_b, 1);
        // }
        // else
            // break;
    // }
    // while(num_ls / 2 != ft_count_node_b(stack_b) && pushed --)
        // ft_rrb(stack_b, 1);
    // ft_sort_b(stack_a, stack_b, num_ls / 2);
    // 
// }
// void ft_quick_sort(t_stack **stack_a, t_stack_b **stack_b, int len)
// {
    // if (!ft_is_sorted(*stack_a))
    // {
        // ft_sort_a(stack_a, stack_b, len);
        // ft_sort_b(stack_a, stack_b, len);
    // }
// }
// 
int ft_sort_a(t_stack **stack_a, t_stack_b **stack_b, int len)
{
    int median;
    int num_ls;
    int pushed = 0;
    num_ls = len;
    if (ft_is_sorted(*stack_a))
    {
        if (ft_count_node(*stack_a) <= 3)
        {
            if (ft_count_node(*stack_a) == 2 && (*stack_a)->data > (*stack_a)->link->data)
                ft_sa(*stack_a, 1);
            else
                ft_sort_three(stack_a);
            return 0;
        }

        median = ft_get_median(*stack_a);

        while (len != num_ls / 2 + num_ls % 2)
        {
            printf("I am here and the median == %d\n and the top == %d \n", median, (*stack_a)->data);
            if(!ft_is_less(*stack_a, median))
                break;
            else if ((*stack_a)->data < median && len--)
                ft_pb(stack_a, stack_b, 1);
            else if ( ++pushed)
                ft_ra(stack_a, 1);
        }

        while (num_ls / 2 + num_ls % 2 != ft_count_node_b(*stack_b) && pushed--)
        {
            ft_rra(stack_a, 1);
        }

        ft_sort_a(stack_a, stack_b, num_ls / 2  + num_ls % 2);
    }

    return 1;
}

void ft_sort_b(t_stack **stack_a, t_stack_b **stack_b, int len)
{
    int median;
    int num_ls;
    int pushed = 0;
    num_ls = len;

    if (ft_is_sorted_b(*stack_b))
    {
        while (len--)
            ft_pa(stack_a, stack_b, 1);
    }

    if (len <= 3)
    {
        ft_push_sort_three(stack_b, stack_a, len);
        return;
    }

    median = ft_get_median_b(*stack_b);

    while (len != num_ls / 2)
    {
        if ((*stack_b)->data >= median && len--)
            ft_pa(stack_a, stack_b, 1);
        else if (ft_is_less_b(*stack_b, median))
        {
            ft_rb(stack_b, 1);
        }
        else
            break;
    }

    while (num_ls / 2 != ft_count_node_b(*stack_b) && pushed--)
        ft_rrb(stack_b, 1);

    ft_sort_b(stack_a, stack_b,  num_ls / 2);
}

void ft_quick_sort(t_stack **stack_a, t_stack_b **stack_b)
{
    if (ft_is_sorted(*stack_a))
    {
        ft_sort_a(stack_a, stack_b, ft_count_node(*stack_a));
        ft_sort_b(stack_a, stack_b, ft_count_node_b(*stack_b));
    }
}

int ft_is_less(t_stack *stack_a, int median)
{
    t_stack *temp;
    
    temp = stack_a;
    while(temp != NULL)
    {
        if(temp->data >= median)
            return (0);
        temp = temp->link;
    }
    return (1);
}

int ft_is_less_b(t_stack_b *stack_a, int median)
{
    t_stack_b *temp;
    
    temp = stack_a;
    while(temp != NULL)
    {
        if(temp->data <= median)
            return (0);
        temp = temp->link;
    }
    return (1);
}
void ft_push_sort_three(t_stack_b **stack_b, t_stack **stack_a, int len)
{
    if(len == 1)
        ft_pa(stack_a, stack_b, 1);
    else if(len == 2)
        if((*stack_b)->data < (*stack_b)->link->data)
            ft_sb(*stack_b, 1);
    else
        ft_sort_three_b(stack_b);
}
void ft_from_b_to_a(t_stack_b **stack_b, t_stack **stack_a)
{
    if(stack_b)
    {
        int count = 0;
        
        while ((*stack_b)->link != NULL)
        {
            int max = ft_stack_b_max(*stack_b);
            if((*stack_b)->data == max)
                ft_pa(stack_a, stack_b, 1);
            else if(++count)
                ft_sb(*stack_b, 1);
        }
        ft_pa(stack_a,stack_b, 1);
        
    }
}
void    ft_cc_sort(t_stack **stack_a)
{
    if(ft_is_sorted(*stack_a)){
        int largest;
        t_stack_b *stack_b = NULL;
        int next_element;
        int len ;
        int num ;
        while((*stack_a)->link->link != NULL)
        {
            if((*stack_a)->data == ft_stack_a_min(*stack_a) || (*stack_a)->data == ft_second_last(*stack_a))
                ft_pb(stack_a, &stack_b, 1);
            else if(ft_pos_rank_one(*stack_a, ft_stack_a_min(*stack_a) ) < ft_count_node(*stack_a)/2 || ft_pos_rank_one(*stack_a, ft_second_last(*stack_a) ) < ft_count_node(*stack_a)/2)
                ft_ra(stack_a, 1);
            else
                ft_rra(stack_a,1);
        }
        if(ft_count_node(*stack_a) <= 3)
        {
            if(ft_count_node(*stack_a)  == 2 && (*stack_a)->data > (*stack_a)->link->data)
                ft_sa(*stack_a, 1);
            else
                ft_sort_three(stack_a);
        }
         ft_from_b_to_a(&stack_b, stack_a);
    }
}
int main(int ac, char *argv[])
{
    if(ac > 1)
    {
        t_stack *stack_a;
        t_stack_b *stack_b;
        stack_a = NULL;
        stack_b = NULL;
        stack_a = ft_parse(argv, ac);
        radix_sort(&stack_a, &stack_b);
        printf("Is sorted %d\n", ft_is_sorted(stack_a));
        ft_display(stack_a);
    }

    
}