/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 04:00:18 by pamone            #+#    #+#             */
/*   Updated: 2023/12/07 02:59:50 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_from_b_to_a(t_stack_b **stak_b, t_stack **stack_a);
t_stack *getTail(t_stack *cur)
{
    while (cur != NULL && cur->link != NULL)
        cur = cur->link;
    return cur;
}
t_stack*partition(t_stack *head, t_stack *end, t_stack**newHead, t_stack **newEnd)
{
    t_stack *pivot = end;
    t_stack *prev = NULL, *cur = head, *tail = pivot;
    while(cur != pivot) {
        if(cur->data < pivot->data) {
            if((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->link;
        }
        else {
            if(prev)
                prev->link = cur->link;
            t_stack *tmp = cur->link;
            cur->link = NULL;
            tail->link = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if((*newHead) == NULL)
        (*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
}

//  here the sorting happens exclusive of the end node
t_stack *quickSortRecur(t_stack *head, t_stack *end)
{
    if (!head || head == end)
        return head;
    t_stack *newHead = NULL, *newEnd = NULL;
    t_stack *pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        t_stack *tmp = newHead;
        while (tmp->link != pivot)
            tmp = tmp->link;
        tmp->link = NULL;
        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->link = pivot;
    }
    pivot->link = quickSortRecur(pivot->link, newEnd);
    return newHead;
}
void quickSort(t_stack **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

void    ft_sort_five_many(t_stack **stack_a)
{
    int rank_one;
    int rank_two;
    t_stack *temp_a;
    t_stack_b *stack_b;
    
    stack_b = NULL;
    temp_a = *stack_a;
    int dis_rank_one;
    int dis_rank_two;
    int i = 0;
    while(temp_a->link->link != NULL)
    {
        rank_one = ft_stack_a_min(temp_a);
        rank_two = ft_second_last(temp_a);
        dis_rank_one = ft_pos_rank_one(temp_a, rank_one);
        dis_rank_two = ft_pos_rank_one(temp_a, rank_two);
        // printf("The iteration is [%d]\nRank 01 >> %d << The pos is (%d)\nRank 02 >> %d << The pos is (%d)\n", i, rank_one, dis_rank_one, rank_two, dis_rank_two);
        // printf("The top data is >>> %d <<<< and is === rankone? %d === rank2? %d\n", temp_a->data, 
        // temp_a->data == rank_one, temp_a->data == rank_two);
         //ft_display(temp_a);
        if(temp_a->data == rank_one || temp_a->data == rank_two)
            ft_pb(&temp_a, &stack_b, 1);
        else if(dis_rank_two < dis_rank_one || dis_rank_two > dis_rank_one)
            ft_ra(&temp_a, 1);
        else
            ft_rra(&temp_a, 1);
        //temp_a =  temp_a->link; 
        i++;
    }
    if(temp_a->data < temp_a->link->data)
        ft_pb(&temp_a, &stack_b, 1);
    else
    {
        ft_sa(temp_a, 1);
        ft_pb(&temp_a, &stack_b, 1);
    }
    
    //ft_display(stack_b);
        
    *stack_a = temp_a;
    ft_from_b_to_a(&stack_b, stack_a);
   // ft_display(*stack_a);
}
void ft_from_b_to_a(t_stack_b **stak_b, t_stack **stack_a)
{
    if(stak_b != NULL)
    {
        //ft_displa_b(*stak_b);
        while ((*stak_b)->link != NULL)
        {
            int max = ft_stack_b_max(*stak_b);
            if((*stak_b)->data == max)
                ft_pa(stack_a, stak_b, 1);
            else
                ft_sb(*stak_b, 1);
        }
        ft_pa(stack_a,stak_b, 1);
        
    }
}
// void    ft_crazy_sort(t_stack **stack_a, int Num, int begin, int  end, int loc)
// {
    // int start = 
// }
int main(int ac, char *argv[])
{
    if(ac > 1)
    {
        t_stack *stack_a;
        t_stack_b *stack_b;
        stack_a = NULL;
        stack_b = NULL;
        stack_a = ft_parse(argv, ac);
        //printf("The stack is not NULL %d  %d\n", stack_a == NULL, stack_a->data);
        ft_sort_five_many(&stack_a);

        
    }

    
}