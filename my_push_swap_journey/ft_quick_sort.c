/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 04:00:18 by pamone            #+#    #+#             */
/*   Updated: 2023/12/04 07:01:00 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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