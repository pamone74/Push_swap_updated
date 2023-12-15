#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
    int data;
    struct s_stack *next;
} t_stack;

// Function to initialize the stack
void initializeStack(t_stack **stack) {
    *stack = NULL;
}

// Function to check if the stack is empty
int isStackEmpty(t_stack *stack) {
    return stack == NULL;
}

// Function to push an element onto the stack
void push(t_stack **stack, int data) {
    t_stack *newNode = (t_stack *)malloc(sizeof(t_stack));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = *stack;
    *stack = newNode;
}

// Function to swap the first two elements of the stack
void sa(t_stack **stack) {
    if (*stack != NULL && (*stack)->next != NULL) {
        int temp = (*stack)->data;
        (*stack)->data = (*stack)->next->data;
        (*stack)->next->data = temp;
    }
}

// Function to swap the first two elements of stack b
void sb(t_stack **stack) {
    sa(stack);
}

// Function to swap the first two elements of both stacks
void ss(t_stack **stack_a, t_stack **stack_b) {
    sa(stack_a);
    sb(stack_b);
}

// Function to push an element from stack b to stack a
void pa(t_stack **stack_a, t_stack **stack_b) {
    if (!isStackEmpty(*stack_b)) {
        push(stack_a, (*stack_b)->data);
    }
}

// Function to push an element from stack a to stack b
void pb(t_stack **stack_a, t_stack **stack_b) {
    pa(stack_b, stack_a);
}

// Function to rotate the stack (shift up all elements by 1)
void ra(t_stack **stack) {
    if (*stack != NULL) {
        int first_data = (*stack)->data;
        t_stack *current = *stack;
        while (current->next != NULL) {
            current->data = current->next->data;
            current = current->next;
        }
        current->data = first_data;
    }
}

// Function to rotate stack b
void rb(t_stack **stack) {
    ra(stack);
}

// Function to rotate both stacks
void rr(t_stack **stack_a, t_stack **stack_b) {
    ra(stack_a);
    rb(stack_b);
}

// Function to reverse rotate the stack (shift down all elements by 1)
void rra(t_stack **stack) {
    if (*stack != NULL) {
        int last_data;
        t_stack *current = *stack;
        while (current->next != NULL) {
            current = current->next;
        }
        last_data = current->data;
        while (current != *stack) {
            current->data = current->data;
            current = current->next;
        }
        (*stack)->data = last_data;
    }
}

// Function to reverse rotate stack b
void rrb(t_stack **stack) {
    rra(stack);
}

// Function to reverse rotate both stacks
void rrr(t_stack **stack_a, t_stack **stack_b) {
    rra(stack_a);
    rrb(stack_b);
}

// Function to sort a stack using quicksort operations
void quickSort(t_stack **stack_a, t_stack **stack_b, int size) {
    if (size <= 1) {
        return;
    }

    int pivot = (*stack_a)->data;

    t_stack *lower = NULL;
    t_stack *upper = NULL;

    // Partition the stack into elements less than or equal to the pivot and elements greater than the pivot
    t_stack *current = (*stack_a)->next;
    while (current != NULL) {
        int current_data = current->data;
        if (current_data <= pivot) {
            push(&lower, current_data);
        } else {
            push(&upper, current_data);
        }
        current = current->next;
    }

    // Recursively sort the lower and upper partitions
    quickSort(&lower, stack_b, size / 2);
    quickSort(&upper, stack_b, size / 2);

    // Merge the sorted partitions back into the original stack
    while (!isStackEmpty(lower)) {
        ra(stack_a);
        pb(stack_b, stack_a);
    }

    while (!isStackEmpty(upper)) {
        ra(stack_a);
        pb(stack_b, stack_a);
    }
}

// Function to print the elements of the stack
void printStack(t_stack *stack) {
    printf("Stack: ");
    while (stack != NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

int main(void) {
    t_stack *stack_a;
    t_stack *stack_b;

    initializeStack(&stack_a);
    initializeStack(&stack_b);

    // Push elements onto stack_a (replace these values with your own)
    push(&stack_a, 30);
    push(&stack_a, 10);
    push(&stack_a, 20);
    push(&stack_a, 5);
    push(&stack_a, 15);

    // Print the initial state
    printf("Before sorting:\n");
    printStack(stack_a);
    printStack(stack_b);

    // Implement quicksort using the provided operations
    quickSort(&stack_a, &stack_b, 5);

    // Print the final state
    printf("\nAfter sorting:\n");
    printStack(stack_a);
    printStack(stack_b);

    return 0;
}
