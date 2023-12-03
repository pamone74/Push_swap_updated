/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 03:32:01 by pamone            #+#    #+#             */
/*   Updated: 2023/11/30 03:32:01 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

typedef struct s_stack{
    int data;
    int index;
    struct s_stack *link;
}               t_stack;

typedef struct s_stack_b
{
   int data;
   int  index;
   struct s_stack_b *link;
}               t_stack_b;



/* The push_swap_utils.c */
void	ft_putstr(char *str);
void	ft_swap(int *item1, int *item2);
int		ft_get_index(t_stack **stack, int index);
void	ft_insert_at_index_a(t_stack **headref, int index, int data);

/*Operaion_a.c*/
void	ft_ra(t_stack **stack_a, int flag);
void	ft_sa(t_stack *stack_a, int flag);
void	ft_pa(t_stack **stack_a, t_stack_b **stack_b, int flag);
void	ft_rra(t_stack **stack_a, int flag);
void	ft_rrb(t_stack_b **stack_a, int flag);

/* b Operation*/
void		ft_sb(t_stack_b *stack_b, int flag);
void		ft_ss(t_stack * stack_a, t_stack_b *stack_b, int flag);
void		ft_pb(t_stack **stack_a, t_stack_b **stack_b, int flag);
void		ft_rb(t_stack_b **stack_b, int flag);
void		ft_rr(t_stack **stack_a, t_stack_b **stack_b, int flag);
void		ft_push_b(t_stack_b **headref, int data);
t_stack_b	*append_node_b(t_stack_b **headref, int data);


/* Operation Helper.c*/
int			ft_pop_a(t_stack **headref);
int			ft_pop(t_stack_b **headRef);
t_stack		*get_bottom_a(t_stack *stack_a);
t_stack_b	*get_bottom_b(t_stack_b *stack_b);
int			is_empty(t_stack *stack);


/* Operation Helper one.c*/
void	ft_rrr(t_stack_b **stack_b, t_stack **stack_a,int flag);
int		ft_duplicate(t_stack *stack_a);
void	ft_error(void);
int		ft_is_integer(int n);
int		ft_check_ascii(char *str);

/* push_swap.c*/
int	ft_check_overflow(int n);
int	ft_atoi(const char *str);
t_stack*	push_swap(char *str);

/* ft_split operations*/
char	**ft_split(const char	*str, int c);
char	*ft_substr(const char *str, size_t start, size_t len);
int     ft_strlen(char *str);
void	ft_free_split(char **str);
int	    ft_count_substring(const char *str, int c);
int	    ft_count_len(const char *str, int c);

/* parse args.c*/
void	ft_free_str(char **string);
t_stack	*ft_parse(char *args[], int argc);
t_stack *ft_split_parser(char **argv);

// Sorting algorithms
void	ft_sort_three(t_stack **stack_a);
int	ft_is_sorted(t_stack *stack_a);
void	ft_sort_all(t_stack **stack_a);
int ft_count_node(t_stack *head);
void	ft_sort_five(t_stack **stack_a);
void ft_insert_at_index(t_stack **stack_a, int index, int item);
void	ft_insert(t_stack **stack_a, t_stack_b *stack_b);


// List operation
t_stack	*ft_last_node_a(t_stack *stack_a);
t_stack	*ft_last_node_a(t_stack *stack_a);
int	ft_stack_b_min(t_stack_b *stack_b);
int	ft_stack_b_max(t_stack_b *stack_b);


int ft_get_inter_at_index(t_stack *stack_a, int index);

t_stack	*buildOneTwoThree();
t_stack	*create(t_stack *header, int data);
//t_stack *three(void);
//t_stack *create(t_stack *header, int data);
t_stack* link_test();
void wrongPush_test();
void ft_build_tail(t_stack **headref, int data);
t_stack * ft_append_node_a(t_stack **headref, t_stack *ref);
void build_tail_localRef(int data);
t_stack * copyList(t_stack *head);
t_stack *CopyListRec(t_stack *head);
t_stack *three(void);
void ft_push(t_stack **head, int data);
#endif