/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:30:50 by pamone            #+#    #+#             */
/*   Updated: 2023/12/01 14:30:50 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_sort.h"

void ft_build_tail(t_stack **headref, int data)
{
    t_stack *tail;
    if((*headref) == NULL)
        ft_push(headref, data);
    else
    {
        tail = *headref;
        while(tail->link != NULL)
            tail = tail->link;
        ft_push(&(tail->link), data);
    }
}
t_stack	*ft_stack_end(t_stack *head)
{
	t_stack	*node;

	node = head;
	while (node->link)
	{
		node = node->link;
		if (node->link == NULL)
			return (node);
	}
	return (node);
}
void	ft_stack_append(t_stack **stack, t_stack *new)
{
	t_stack	*new_node;

	if (*stack)
	{
		new_node = ft_stack_end(*stack);
		new_node->link = new;
		new->link = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->link = NULL;
	}
}

void	ft_free_str(char **string)
{
	char	*temp;

	if(!string)
		return ;
	while (*string)
	{
		temp = *string;
		string++;
		free(temp);
	}
	*string = NULL;
}
t_stack	*ft_parse(char *args[], int argc)
{
	t_stack		*stack_a;
	t_stack     *new;
	int			i;
	char		*nor = ft_strjoin(args, argc);
	char		**str = ft_split(nor, ' ');		
	stack_a = NULL;
	while (str[i] != NULL)
	{

		if(ft_check_ascii(str[i]) || ft_check_overflow(ft_atoi(str[i])))
		{
			ft_error();
			//ft_free_str(args);
			//free(args);
			//free(args[i]);
			return 0;
		}	
		else
		{
			new = ft_stack_new(ft_atoi((*ft_split(str[i], ' '))));
			ft_stack_append(&stack_a, new);

		}
		i++;
	}
	index_stack(&stack_a);
	return (stack_a);
}

t_stack *ft_split_parser(char **argv)
{
	t_stack *stack_a;
	char	**temp;
	int		i;

	stack_a = NULL;
	i = 0;
	temp = ft_split(argv[1], ' ');
	while (temp[i] != NULL)
	{
		if(ft_check_ascii(temp[i]) || ft_check_overflow(ft_atoi(temp[i])))
		{
			ft_error();

			free(temp);
			free(temp[i]);
		}	
		else
			ft_build_tail(&stack_a, ft_atoi(temp[i]));
		i++;
	}
	ft_free_str(temp);
	free(temp);
	return (stack_a);
}
void freeList(t_stack *head) {
    while (head != NULL) {
        t_stack* temp = head;
        head = head->link;
        free(temp);
    }
}
void selectionSort(t_stack* head_ref) {
    t_stack* current = head_ref;
    t_stack* min;
    while (current != NULL) {
        // Assume the current node is the minimum
        min = current;
        // Iterate through the rest of the list to find the minimum
      t_stack* temp = current->link;
        while (temp != NULL) {
            if (temp->data < min->data) {
                min = temp;
            }
            temp = temp->link;
        }
        // Swap the data of the current node and the minimum node
        int temp_data = current->data;
        current->data = min->data;
        min->data = temp_data;

        // Move to the link node
        current = current->link;
    }
}

int	ft_get_median(const t_stack *stack_a)
{
	int len;

	t_stack * temp_a;

	temp_a = CopyListRec(stack_a);
	len = ft_count_node(temp_a)/2;
	selectionSort(temp_a);
	return ft_get_inter_at_index(temp_a, len);
}

int	ft_get_median_b(t_stack_b *stack_b)
{
	int len;
	t_stack_b *temp_b;

	temp_b = stack_b;
	len = ft_count_node_b(temp_b)/2;
	ft_selection_sort_b(temp_b);
	return ft_get_inter_at_index_b(temp_b, len);
}

void ft_selection_sort_b(t_stack_b* head_ref) {
    t_stack_b* current = head_ref;
    t_stack_b* min;
    while (current != NULL) {
        // Assume the current node is the minimum
        min = current;
        // Iterate through the rest of the list to find th
      t_stack_b* temp = current->link;
        while (temp != NULL) {
            if (temp->data < min->data) {
                min = temp;
            }
            temp = temp->link;
        }
        // Swap the data of the current node and the minim
        int temp_data = current->data;
        current->data = min->data;
        min->data = temp_data;

        // Move to the next node
        current = current->link;
    }
}