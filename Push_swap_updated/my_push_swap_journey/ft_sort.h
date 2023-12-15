#ifndef FT_SORT_H
#define FT_SORT_H

#include "push_swap.h"

void	index_stack(t_stack **stack);
int ft_bit_max(t_stack **stack_a);
void	radix_sort(t_stack **stack_a, t_stack_b **stack_b);
t_stack	*ft_stack_new(int value);

#endif


