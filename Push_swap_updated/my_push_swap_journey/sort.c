/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:16:12 by pamone            #+#    #+#             */
/*   Updated: 2023/12/03 20:16:12 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sw(int *item, int *e)
{
	int i = *item;
	*item = *e;
	*e = i;
}
int partition(int *tab, int lower, int upper)
{
    int start = lower;
    int end = upper;
    int pivot = tab[start];
    while (start < end)
    {
        while(tab[start] <= pivot)
            start ++;
        while (tab[end] > pivot)
            end --;
        if(start < end)
            ft_sw(&tab[start], &tab[end]);
    }
    ft_sw(&tab[lower], &tab[end]);
    return end; 
}

void quick_sort(int *tab, int start, int end)
{
    if(start < end)
    {
        int pos = partition(tab, start, end);
        quick_sort(tab, start, pos -1);
        quick_sort(tab, pos + 1, end);
    }
}

int main(void)
{
        int tab[5] = {1,4,3,6,7};
        quick_sort(tab, 0, 4-1);
        int i = 0;
        while(i < 5)
        {
            printf("%d\n", tab[i]);
            i++;
        }

}

int ft_fnd(t_stack *stack, int index)
{
    int i = 0;
    while(stack != NULL && i < index)
    {
        stack = stack->link;
        i ++;
    }
    return stack->data;
}
void    ft_quicky(t_stack **stack_a)
{
    t_stack *temp = *stack_a;
    t_stack_b *stack_b = NULL;
    int pivot = temp->data;
    int i = 0;
    int start =  0;
    int end  = ft_count_node(temp);
    while (start < end)
    {
        while (ft_fnd(temp, start++) <= pivot)
            ft_pb(&temp, &stack_b, 1);
        while (ft_fnd(stack_a, end--) > pivot)
        {
            ft_rra(&temp, 1);
            ft_pb(&temp,&stack_b,1);
        }
        if(start < end)
        {
            if(ft_count_node(temp) > 2)
                ft_rra(temp, 1);
            else
                ft_sa(temp, 1);
        }
    while (stack_b->link != NULL)
    {
        if(stack_b->data != pivot)
        {
            ft_pa(&temp, &stack_b, 1);
            ft_ra(&temp, 1);
        }
        else
             ft_pa(&temp, &stack_b, 1);
    }
        if(stack_b->data != pivot)
        {
            ft_pa(&temp, &stack_b, 1);
            ft_ra(&temp, 1);
        }
        else
            ft_pa(&temp, &stack_b, 1);
        
    }
    
    
    }