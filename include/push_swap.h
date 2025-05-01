/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:36:13 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/01 14:54:10 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct s_que_node
{
	struct s_que_node	*next;
	struct s_que_node	*prv;
	int					val;
} t_que_node;

typedef struct	s_que
{
	t_que_node	*head;
	int			size;
} t_que;

//parse input ac && av
t_que	*parse_input(int ac, char *av[]);
char	*no_space_str(char *src, char *dest, int *cur_pos);
void	atoi_to_que(char *str, t_que *arr_a);
int		ft_isspace(int c);

//delete after
void print_circular_arr(t_que *arr, char *arr_type);
void print_arr(int *arr_int, int size);

//median search
int	*cpy_que(t_que *arr_a);

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
t_que	*append_value_bottom(t_que *lst, int data);

#endif
