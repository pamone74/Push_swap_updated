#include "push_swap.h"

int get_value_at(t_stack *stack, int item)
{
    t_stack *node = stack;
    int count = 0;
    if(node != NULL)
    {
        while(node != NULL)
        {
            if(node->data == item)
                return count;
            count ++;
            node = node->link;
        }
    }
    return 0;
}
int partition(t_stack **a, int start, int end) {
    int pivot_index = start + (end - start) / 2;
    int pivot = get_value_at(*a, pivot_index); // Assuming you have a function to get the value at index

    int s = start;
    int e = end;

    while (s < e) {
        while (get_value_at(*a, s) <= pivot && s < pivot_index) {
            s++;
        }

        while (get_value_at(*a, e) > pivot && e > pivot_index) {
            e--;
        }

        if (s < e) {
            while (get_value_at(*a, s) != get_value_at(*a, e)) {
                ft_ra(a,1);
            }
            ft_sa(*a, 1);
            while (get_value_at(*a, s) != get_value_at(*a, e)) {
                ft_rra(a,1);
            }
        }
    }

    return pivot_index;
}

// Function to perform Quick Sort on the stack
void quick_sort(t_stack **a, int start, int end) {
    if (start < end) {
        int position = partition(a, start, end);
        quick_sort(a, start, position - 1);
        quick_sort(a, position + 1, end);
    }
}

int main(void)
{
    t_stack *stack_a  = NULL;
    ft_push(&stack_a, 7);
    ft_push(&stack_a, 2);
    ft_push(&stack_a, 9);
    ft_push(&stack_a, 3);
    ft_push(&stack_a, 9);
    quick_sort(&stack_a, 0, 4);
    while (stack_a != NULL)
    {
        printf("The element is >>>>>> %d <<<<<<\n", stack_a->data);
        stack_a = stack_a->link;
    }
    
}