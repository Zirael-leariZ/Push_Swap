/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:36:13 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/15 13:26:15 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

#define SA 0
#define SB 1
#define SS 2
#define PA 3
#define PB 4
#define RA 5
#define RB 6
#define RR 7
#define RRA 8
#define RRB 9
#define RRR 10

typedef struct s_que_node
{
	struct s_que_node	*next;
	struct s_que_node	*prv;
	int					val;
	int					index;
} t_que_node;

typedef struct	s_que
{
	t_que_node	*head;
	int			size;
} t_que;

// sort suplementary
void	pivot_sort(t_que *a, t_que *b);
void	chunck_sort(t_que *a, t_que *b);
void	back_sort(t_que *a, t_que *b);
void	sort_exe(t_que *a, t_que *b, t_que_node *b_node);

//BACKSORT_UTILS
int		count_steps(t_que *a, t_que *b, t_que_node *b_node);
int		steps_in_b(t_que *b, t_que_node *b_node, int *rb_or_rrb);
int		steps_in_a(t_que *a, t_que_node *b_node, int *ra_or_rra);
void	push_to_a(t_que *a, t_que *b, t_que_node *b_node);

//EFFICIENCY functions
void	prep_que(t_que *a, t_que *b, int chunck, int t_used);
void	check_sa_ss_sb(t_que *a, t_que *b);

// EXECUTE BACK_SORT
void	exe_rb_rra(t_que *a, t_que *b, int rb_nb, int rra_nb);
void	exe_rb_ra(t_que *a, t_que *b, int rb_nb, int ra_nb);
void	exe_rrb_rra(t_que *a, t_que *b, int rrb_nb, int rra_nb);
void	exe_rrb_ra(t_que *a, t_que *b, int rrb_nb, int ra_nb);
// void	ra_rb_rr(t_que *a, t_que *b, int pivot, int chunck);
// int	derive_chuncks(int size);
// int	nb_rb(t_que *b, int high_border, int pivot);
// int	nb_ra(t_que *que_a, int high_border);
// int	nb_rra(t_que *a, int high_border);
// int		ft_min(int a, int b);

// check for already sorted arr
int	is_sorted(t_que_node *a_node, int size);
int	rewind_que(t_que *a, int begin_idx);
int	is_fully_sorted(t_que *a);
void	three_sort(t_que *a);

//parse input ac && av
t_que	*parse_input(int ac, char *av[]);
char	*no_space_str(char *src, char *dest, int *cur_pos);
void	atoi_to_que(char *str, t_que **arr_a);
int		ft_isspace(int c);
int		is_in_que(t_que *arr, int cur_val);

//delete after
void print_circular_arr(t_que *arr, char *arr_type);
void print_arr(int *arr_int, int size, char *which_arr);
void print_index(t_que *arr, char *message);

//median search
int	*cpy_que(t_que *arr_a);
int *ft_sort(t_que **que_arr);
int	*sort_arr(int *arr, int size, t_que **a);
void assign_index(t_que **que_list, int *arr);
// int	*cumulative_arr(int *arr);
// int	find_max(int *arr, int size);
// int	*count_cum_arr(int *arr, int size, int exp);
// int	*sort_arr(int **int_arr, int **int_tenarr, int size, int exp);
// int	*ft_radix_sort(t_que *que_arr);
// int	find_median(t_que *que_list);

// subfunctions for allowed functions
void	delete_head(t_que *arr);
void	ft_list_swap(t_que *arr_a);
void	rotate(t_que *arr_a, int i);

// allowed functions
void	rrr(t_que *arr_a, t_que *arr_b);
void	rrb(t_que *arr_b);
void	rra(t_que *arr_a);
void	rr(t_que *arr_a, t_que *arr_b);
void	rb(t_que *arr_b);
void	ra(t_que *arr_a);
void	pa(t_que *arr_a, t_que *arr_b);
void	pb(t_que *arr_a, t_que *arr_b);
void	ss(t_que *arr_a, t_que *arr_b);
void	sb(t_que *arr_b);
void	sa(t_que *arr_a);

// general utils
t_que	*create_list(void);
void	free_each_node_exit(t_que **arr);
void	free_each_node(t_que **arr);
t_que	*append_value_bottom(t_que **lst, int data);

#endif
