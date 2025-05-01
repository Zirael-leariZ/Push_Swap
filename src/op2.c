/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:29:36 by oishchen          #+#    #+#             */
/*   Updated: 2025/04/29 12:23:55 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_que *arr_a)
{
	if (arr_a->size > 1)
	{
		ft_list_swap(arr_a);
		ft_printf("sa\n");
	}
}

void	sb(t_que *arr_b)
{
	if (arr_b->size > 1)
	{
		ft_list_swap(arr_b);
		ft_printf("sb\n");
	}
}

void	ss(t_que *arr_a, t_que *arr_b)
{
	if (arr_a->size > 1 && arr_b->size > 1)
	{
		ft_list_swap(arr_a);
		ft_list_swap(arr_b);
		ft_printf("ss\n");
	}
}

void	pb(t_que *arr_a, t_que *arr_b)
{
	ft_printf("PB start\n");
	append_value_bottom(arr_b, arr_a->head->val);
	delete_head(arr_a);
	ft_printf("pb\n");
	ft_printf("---------------------------------\n");
	print_circular_arr(arr_a, "arr_a");
	ft_printf("---------------------------------\n");
	print_circular_arr(arr_b,  "arr_b");
}

void	pa(t_que *arr_a, t_que *arr_b)
{
	append_value_bottom(arr_a, arr_b->head->val);
	delete_head(arr_b);
	ft_printf("pa\n");
	ft_printf("---------------------------------\n");
	print_circular_arr(arr_a, "arr_a");
	ft_printf("---------------------------------\n");
	print_circular_arr(arr_b,  "arr_b");
}
