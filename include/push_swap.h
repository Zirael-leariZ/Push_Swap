/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:36:13 by oishchen          #+#    #+#             */
/*   Updated: 2025/04/29 10:59:41 by oishchen         ###   ########.fr       */
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
	int		size;
} t_que;

t_que	*parse_input(int ac, char *av[]);
void	purify_input(char *str, t_que *arr_a);
void print_circular_arr(t_que *arr, char *arr_type);
int		ft_isspace(int c);
void	ft_exit(int status);
void	delete_head(t_que *arr);
void	ft_list_swap(t_que *arr_a);
void	rotate(t_que *arr_a, int i);
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
t_que	*create_list(void);
void	free_each_node_exit(t_que **arr);
t_que	*append_value_bottom(t_que *lst, int data);

#endif
