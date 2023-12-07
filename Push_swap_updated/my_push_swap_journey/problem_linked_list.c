/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 03:54:53 by pamone            #+#    #+#             */
/*   Updated: 2023/12/04 03:54:53 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int count(t_stack *head, int searchFor)
{
    t_stack *current = head;
    if(head ==  NULL)   
        return 0;
    int i = 0;
    while (current != NULL)
    {
        if(current->data == searchFor)
            i++;
        current = current->link;
    }
    return i;
    
}

void DeleteList(t_stack **headref)
{
    t_stack *current = *headref;
    t_stack *next  = NULL;
    while(current != NULL)
    {
        next = current->link;
        free(current);
        current = next;
    }
    (*headref) = NULL;
}
int Isorted(t_stack *header)
{
    printf("I am here and the data is ===>>>> %d\n", header->data);
    t_stack *cur = header;
    while(cur != NULL && cur->link != NULL && cur->data < cur->link->data)
    {
       cur = cur->link; 
    }
    return (cur->link == NULL);
    
}
void SortedInsert(t_stack **headref, t_stack *newNode)
{
    printf("I am here the head and newnode..... %d \n", newNode->data);
    if(newNode == NULL)
        return;
    if((*headref) == NULL || (*headref)->data >= newNode->data)
    {
        newNode->link  = *headref;
        *headref = newNode;
    }
    else
    {
        t_stack *current = *headref;
        while (current->link != NULL && current->link->data < newNode->data)
        {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}
void InsertSort(t_stack **headref)
{
    t_stack *current = *headref;
    t_stack *node;
    t_stack *result = NULL;
        while (current != NULL)
        {
            node = current->link;
            SortedInsert(&result, current);
            current = node;
        }
    printf("I have reached here\n"); 
    *headref = result;
}

void Append(t_stack **Aref, t_stack **bRef)
{
    t_stack *currentA = *Aref;
    t_stack *currenB = *bRef;
    t_stack *prev = NULL;
    int item;
    if(currenB == NULL)
        return;
    while(currenB != NULL)
    {
        item = currenB->data;
        *bRef = currenB->link;
        free(currenB);
        ft_append_node_a(&currentA, item);  
        currenB = *bRef;
    }
        *Aref = currentA;
}

int odd(int len)
{
    return (len % 2 == 1);
}
void FrontBackSplit(t_stack *source, t_stack **Front, t_stack **back)
{
    t_stack *newNode = source;
    int number;
    int i;
    number = count_node(source);
    printf("The size of the list is ++ >>>>> === %d\n", number);
    if(source == NULL)
        return;
    if(number == 1)
    {
        ft_push(Front,newNode->data);
        return;
    }
    if(odd(number))
    {
         i = (number/2) + 1;
         ft_push(Front, newNode->data);
         while (i > 1)
         { 
             newNode = newNode->link;
             ft_append_node_a(Front, newNode->data);
             i--;
         }
         newNode = newNode->link;
         i = (number/2);
         ft_push(back, newNode->data);
         while (i > 1)
         {
             newNode = newNode->link;
             ft_append_node_a(back, newNode->data);
             i--;
         }
            } 
    else
    {
        i = number/2;
        ft_push(Front, newNode->data);
        while (i > 1)
        {
            
            newNode = newNode->link;
            ft_append_node_a(Front, newNode->data);
            i--;
        }
        newNode = newNode->link;
        i = number/2;
        ft_push(back, newNode->data);
        while (i > 1)
        {
            newNode = newNode->link;
            ft_append_node_a(back, newNode->data);
            i--;
        }

    }       

}

void RemoveDuplicate(t_stack *head)
{
    printf("I am here!");
    t_stack *newNode = head;
    t_stack *prev = NULL;
    if(newNode == NULL)
        return;
    if(count_node(newNode)==1)
        return;
    InsertSort(&newNode);
    while(newNode != NULL)
    {
        while(newNode->data == newNode->link->data)
        {
            prev = newNode->link;
            free(newNode);
            newNode = prev;
        }
        newNode = newNode->link;
    }

}
void ProblemTest()
{
    t_stack *node = buildOneTwoThree();
    ft_append_node_a(&node, 2);
    t_stack  *new =  (t_stack *)malloc(sizeof(t_stack));
    new->data = 10;
    new->link = NULL;
    ft_push(&new, 10);
    ft_push(&new, 10);
    Append(&node, &new);
    InsertSort(&node);
    RemoveDuplicate(node);
    t_stack *nodex = node;
    while(nodex != NULL)
    {
      printf("The data is ====>  %d\n", nodex->data);
      nodex = nodex->link;
    }
    DeleteList(&node);
}
int	empty(t_stack_b *stack)
{
    return stack == NULL;
}

int main(int argc, char *argv[])
{
    t_stack *B = NULL;
    if(argc > 1)
    {
        int i = 2;
      ft_push(&B, atoi(argv[1]));
        while(argv[i])
         {
            if(ft_check_ascii(argv[i]))
            {   ft_error();
                    return 0;
            }
            else if (ft_check_overflow(ft_atoi(argv[i])))
            {
                ft_error();
                return 0;
            }
              ft_append_node_a(&B, atoi(argv[i]));
            i++;
        }

          printf("Atoi %d >>>>> \n", ft_atoi("-5555555555553"));  
    }
     t_stack_b *A = NULL;
    ft_sa(B, 1);
    ft_pb(&B, &A,1);
    ft_pb(&B, &A,1);
    ft_pb(&B, &A,1);
    ft_ra(&B, 1);
    ft_rb(&A,1);
    ft_rra(&B, 1);
    ft_rrb(&A, 1);
    ft_sa(B, 1);
    ft_pa(&B, &A, 1);
    ft_pa(&B, &A, 1);
    ft_pa(&B, &A, 1);
}