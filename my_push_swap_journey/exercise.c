#include "push_swap.h"
t_stack *create(t_stack *header, int data)
{
    t_stack * node = (t_stack *)malloc(sizeof(t_stack));
    if(!node)
        return NULL;
    node->data = data;
    node->link = NULL;
    header  = node;
    return header;
}
t_stack *buildOneTwoThree()
{
    int i = 0;
    t_stack *cur = NULL;
    t_stack *h = NULL;
    while(++i < 4)
    {
    t_stack *head = (t_stack *)malloc(sizeof(t_stack));
    if(!head)
        return NULL;
    head->data = i;
    head->link = NULL;
    if(h == NULL)
    {
        h = head;
        cur = h;
    }
    else
    {
        cur->link = head;
        cur =  head;
    }
    }
    return h;
}

t_stack *three(void)
{
    t_stack * new_node = (t_stack *)malloc(sizeof(t_stack));
    if(!new_node)
        return NULL;
    int i = 0;
    while(++i < 4)
    {
        new_node = create(new_node, i);
    }
    return new_node;
}

int ft_count_node(t_stack *head)
{
    if(head == NULL)
        return 0;
    t_stack *node = head;
    int i = 0;
    while(node != NULL)
    { 
        node = node->link;
        i++;
    }
    return i;
}
int ft_count_node_b(t_stack_b *head)
{
    if(head == NULL)
        return 0;
    t_stack_b *node = head;
    int i = 0;
    while(node != NULL)
    { 
        node = node->link;
        i++;
    }
    return i;
}
t_stack* link_test()
{
    t_stack * node = buildOneTwoThree();
    t_stack *newNode = (t_stack *)malloc(sizeof(t_stack));
    if(!newNode)    
        return 0;
    newNode->data = 10;
    newNode->link = node;
    node = newNode;
    return node;
}
void ft_push(t_stack **head, int data)
{
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if(!new_node)
        return;
    new_node->data = data;
    new_node->link = *head;
    *head = new_node;
}

t_stack * ft_append_node_a(t_stack **headref, t_stack *ref)
{
    t_stack *current = *headref;
    if(current == NULL)
        current = ref;
    else
    {
        while (current->link != NULL)
            current = current->link; 
        current->link = ref;
    }
    free(ref);
    ref = NULL;
    return current;
}
t_stack_b * append_node_b(t_stack_b **headref, int data)
{
    t_stack_b *current = *headref;
    t_stack_b *new_node = (t_stack_b*)malloc(sizeof(t_stack_b));
    new_node->data = data;
    new_node->link = NULL;
    if(current == NULL)
        current = new_node;
    else
    {
        while (current->link != NULL)
            current = current->link; 
        current->link = new_node;
    }
    return current;
}
t_stack * copyList(t_stack *head)
{
    t_stack * headL = head;
    t_stack * newList = NULL;
    t_stack * tail = NULL;
    while(headL != NULL)
    {
        if(newList == NULL)
        {
           ft_push(&newList, headL->data);
            tail = newList;
        }
        else
        {
            ft_push(&tail->link, headL->data);
            tail = tail->link;   
        }
        headL = headL->link;
    }
    return newList;
}

t_stack *CopyListRec(t_stack *head)
{
    if(head == NULL)
        return NULL;
    else
    {
        t_stack *current = head;
        t_stack *newList = (t_stack *)malloc(sizeof(t_stack));
        if(!newList)
            return NULL;
        newList->data = current->data;
        newList->link = CopyListRec(current->link);
        return newList;
    }
    
}



void ft_insert_at_index(t_stack **stack_a, int index, int item) 
{
   if (*stack_a == NULL || index < 0)
       return;
   t_stack *newNode = (t_stack *)malloc(sizeof(t_stack));
   if (!newNode) 
		return;
   newNode->data = item;
   if (index == 0) {
       newNode->link = *stack_a;
       *stack_a = newNode;
   } else 
   {
      t_stack *current = *stack_a;
       int i = 0;
       while (current != NULL && i < index - 1) 
	   {
           current = current->link;
           i++;
       }
       if (current != NULL) 
	   {
           newNode->link = current->link;
           current->link = newNode;
       } else 
	   {
		   ft_build_tail(stack_a, item);
           free(newNode); 
       }
   }
}

int ft_get_inter_at_index(t_stack *stack_a, int index)
{
    t_stack *temp_node;
    int i;

    i = 0;
    temp_node = stack_a;
    if(stack_a == NULL)
        return (0);
    while(temp_node != NULL)
    {
        if(i == index)
            return (temp_node->data);
        temp_node = temp_node->link;
        i++;
    }
    return (0);
    
}