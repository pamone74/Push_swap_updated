#include "push_swap.h"
t_stack	*ft_stack_new(int value)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->data = value;
	node->index = -1;
	node->link = NULL;
	return (node);
}
static t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min))
			{
				min = head;
				has_min = 1;
			}
			head = head->index;
		}
	}
	return (min);
}

void	index_stack(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}


int ft_bit_max(t_stack **stack_a)
{
    t_stack *temp_node;
    int max;
    int bits;

    temp_node = *stack_a;
    max = temp_node->index;
    bits = 0;
    while (temp_node)
    {
        if(temp_node->index > max)
            max = temp_node->index;
        temp_node = temp_node->link;
    }
    while ((max >> bits) != 0)
	{
			 bits ++;
	}
       
    return (bits);
}
void	radix_sort(t_stack **stack_a, t_stack_b **stack_b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_count_node(head_a);
	max_bits = ft_bit_max(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ft_ra(stack_a,1);
			else
				ft_pb(stack_a, stack_b,1);
		}
		while (ft_count_node_b(*stack_b) != 0)
			ft_pa(stack_a, stack_b,1);
		i++;
	}
}