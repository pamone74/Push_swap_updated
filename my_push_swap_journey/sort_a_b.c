/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:10:55 by pamone            #+#    #+#             */
/*   Updated: 2023/12/03 12:10:55 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
This function takes stack A and push integers from stack A to stack B until there are only three items left.
First check if the list size is five and this is how it is done, the conditional if statement if (ft_count_node(*stack_a) > 3 && ft_is_sorted(*stack_a)) make sures there are more than three elements in stack A and it is not sorted. 
if the condition is true, i call ft_pb() that will pop the top element from A and push it to B. This is done two times purposely to check if the elements are five. but if the elements are greater than five, then we shall sort B till we reach where there are only three elemenst left in stack A

*/
t_stack_b *ft_sort_stack_b(t_stack **stack_a)
{
    t_stack_b *stack_b;

    stack_b = NULL;
    if (ft_count_node(*stack_a) > 3 && ft_is_sorted(*stack_a))
        ft_pb(stack_a, &stack_b, 1);
    if (ft_count_node(*stack_a) > 3 && ft_is_sorted(*stack_a))
        ft_pb(stack_a, &stack_b, 1);
    if (ft_count_node(*stack_a) > 3 && ft_is_sorted(*stack_a))
        ft_sort_stack_b_three(stack_a, &stack_b);
    if (ft_is_sorted(*stack_a))
        ft_sort_three(stack_a);
    return (stack_b);
    
}

t_stack **ft_sort_stack_a(t_stack **stack_a, t_stack_b **stack_b)
{
    int             i = 0;
    t_stack_b       *temp_node;
    while(*stack_b)
    {
        t_stack_b *tt = *stack_b;
        printf("\nThis is function ft_sort_stack_a\n\n");
        while (tt != NULL)
        {
           printf("The stack_b in ft_sort_a >> %d <<<\n", tt->data);
           tt = tt->link;

        }
        temp_node = *stack_b;
        i = ft_flexible_operation_b_a(*stack_a, *stack_b);
        printf("i >>>> %d \n", i);
        while (i > 0)
        {
            if (i == ft_rotate_ra_rb_a(*stack_a, *stack_b, temp_node->data))
                i = ft_push_ra_rb(stack_a, stack_b, temp_node->data, 'b');
            else if (i == ft_rotate_rra_rrb_a(*stack_a, *stack_b, temp_node->data))
                i = ft_push_rra_rrb(stack_a, stack_b, temp_node->data, 'b');
            else if (i == ft_rotate_ra_rrb_a(*stack_a, *stack_b, temp_node->data))
                i = ft_push_ra_rrb(stack_a, stack_b, temp_node->data, 'b');
            else if (i == ft_rotate_rra_rb_a(*stack_a, *stack_b, temp_node->data))
                i = ft_push_rra_rb(stack_a, stack_b, temp_node->data, 'b');
            else
                temp_node = temp_node->link;
        }
        
    }
    return (stack_a);
}
void    ft_sort_stack_b_three(t_stack **stack_a, t_stack_b **stack_b)
{
    int i;
    t_stack *temp_node;

    while (ft_count_node(*stack_a) > 3 && ft_is_sorted(*stack_a))
    {
        temp_node = *stack_a;
        i = ft_flexible_operation_a_b(*stack_a, *stack_b);
        while (i > 0)
        {
            if (i == ft_rotate_ra_rb(*stack_a, *stack_b, temp_node->data))
                i = ft_push_ra_rb(stack_a, stack_b, temp_node->data, 'p');
            else if (i == ft_rotate_rra_rrb(*stack_a, *stack_b, temp_node->data))
                i = ft_push_rra_rrb(stack_a, stack_b, temp_node->data, 'p');
            else if (i == ft_rotate_ra_rrb(*stack_a, *stack_b, temp_node->data))
                i = ft_push_ra_rrb(stack_a, stack_b, temp_node->data, 'p');
            else if (i == ft_rotate_rra_rb(*stack_a, *stack_b, temp_node->data))
                i = ft_push_rra_rb(stack_a, stack_b, temp_node->data, 'p');
            else
                temp_node = temp_node->link;
        }

    }
}
// This function calculate and decides which rotation
// combination is best to use to sort the stack. Of
// course, after rotation there is always one push
// operation is left to do which i embeded to code.
// Function is used during push from A to B.

int ft_flexible_operation_a_b(t_stack *stack_a, t_stack_b *stack_b)
{
    int     i;
    t_stack *temp;

    temp = stack_a;
    i = ft_rotate_rra_rrb(stack_a, stack_b, temp->data);
    while (temp)
    {
        if (i > ft_rotate_ra_rb(stack_a, stack_b, temp->data))
            i = ft_rotate_ra_rb(stack_a, stack_b, temp->data);
        if (i > ft_rotate_rra_rrb(stack_a, stack_b, temp->data))
            i = ft_rotate_rra_rrb(stack_a, stack_b, temp->data);
        if (i > ft_rotate_ra_rrb(stack_a, stack_b, temp->data))
            i = ft_rotate_ra_rrb(stack_a, stack_b, temp->data);
        if (i > ft_rotate_rra_rb(stack_a, stack_b, temp->data))
            i = ft_rotate_rra_rb(stack_a, stack_b, temp->data);
        temp = temp->link;
    }
    return (i);
}



int ft_flexible_operation_b_a(t_stack *stack_a, t_stack_b *stack_b)
{
    int     i;
    t_stack *temp;

    temp = stack_a;
    i = ft_rotate_rra_rrb_a(stack_a, stack_b, temp->data);

    t_stack  *tta = stack_a;
printf("\nThis is function ft_flexible_operation_b_a\n\n");
while (tta != NULL)
{
   printf("The stack_a in ft_sort_a >> %d <<<\n", tta->data);
   tta = tta->link;
}
    printf("i >>>> %d \n", i);
    while (temp)
    {
        if (i > ft_rotate_ra_rb_a(stack_a, stack_b, temp->data))
            i = ft_rotate_rra_rrb_a(stack_a, stack_b, temp->data);
        if (i > ft_rotate_rra_rrb_a(stack_a, stack_b, temp->data))
            i = ft_rotate_rra_rrb_a(stack_a, stack_b, temp->data);
        if (i > ft_rotate_ra_rrb_a(stack_a, stack_b, temp->data))
            i = ft_rotate_ra_rrb_a(stack_a, stack_b, temp->data);
        if (i > ft_rotate_rra_rb_a(stack_a, stack_b, temp->data))
            i = ft_rotate_rra_rb_a(stack_a, stack_b, temp->data);
        temp = temp->link;
    }
    return (i);
}


// apply the rotation.
// This do reverse rotate for stack A and stack B for the required amount

int ft_push_ra_rb(t_stack **stack_a, t_stack_b **stack_b, int n, char c)
{
    if (c == 'p')
    {
        while ((*stack_a)->data != n && ft_find_place_b(*stack_b, n) > 0)
            ft_rr(stack_a, stack_b, 1);
        while ((*stack_a)->data != n)
            ft_ra(stack_a, 1);
        while (ft_find_place_b(*stack_b, n) > 0)
            ft_rb(stack_b, 1);
        ft_pb(stack_a, stack_b, 1);
    }
    else
    {
        while ((*stack_b)->data != n && ft_find_place_a(*stack_a, c) > 0)
            ft_rr(stack_a, stack_b, 1);
        while ((*stack_b)->data != n)
            ft_rb(stack_b, 1);
        while (ft_find_place_a((*stack_a), n) > 0)
            ft_ra(stack_a, 1);
        ft_pa(stack_a, stack_b, 1);    
    }
    return (-1);
}
int ft_push_rra_rrb(t_stack **stack_a, t_stack_b **stack_b, int c, char d)
{
    if (d == 'p')
    {
        while ((*stack_a)->data != c && ft_find_place_b(*stack_b, c) > 0)
            ft_rrr(stack_b, stack_a, 1);
        while ((*stack_a)->data != c)
            ft_rra(stack_a, 1);
        while (ft_find_place_b(*stack_b, c))
            ft_rrb(stack_b, 1);
        ft_pb(stack_a, stack_b, 1);
    }
    else
    {
        while ((*stack_b)->data != c && ft_find_place_a(*stack_a, c) > 0)
            ft_rrr(stack_b, stack_a, 1);
        while ((*stack_b)->data != c)
            ft_rrb(stack_b, 1);
        while (ft_find_place_a(*stack_a, c) > 0)
            ft_rra(stack_a, 1);
        ft_pa(stack_a, stack_b, 1); 
    }
    return (-1);
}

int ft_push_ra_rrb(t_stack **stack_a, t_stack_b **stack_b, int c, char s)
{
    if ( s == 'p')
    {
        while ((*stack_a)->data != c)
            ft_ra(stack_a, 1);
        while (ft_find_place_b(*stack_b, c) > 0)
            ft_rrb(stack_b, 1);
        ft_pb(stack_a, stack_b, 1);
    }
    else
    {
        while (ft_find_place_a(*stack_a, c) > 0)
            ft_ra(stack_a, 1);
        while ((*stack_b)->data != c)
            ft_rrb(stack_b, 1);
        ft_pa(stack_a, stack_b, 1);  
    }
    return (-1);
    
}

int ft_push_rra_rb(t_stack **stack_a, t_stack_b **stack_b, int c, char s)
{
    if ( s == 'p')
    {
        while ((*stack_a)->data != c)
            ft_rra(stack_a, 1);
        while (ft_find_place_b(*stack_b, c) > 0)
            ft_rb(stack_b, 1);
        ft_pb(stack_a, stack_b, 1);
    }
    else
    {
        while (ft_find_place_a(*stack_a, c) > 0)
            ft_rra(stack_a, 1);
        while ((*stack_b)->data != c)
            ft_rb(stack_b, 1);
        ft_pa(stack_a, stack_b, 1);  
    }
    return (-1);
    
}