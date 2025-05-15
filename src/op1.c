/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:32:29 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/15 19:04:31 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_que *arr_a, int is_silent)
{
	rotate(arr_a, 1);
	if (!is_silent)
		ft_printf("ra\n");
}

void	rb(t_que *arr_b, int is_silent)
{
	rotate(arr_b, 1);
	if (!is_silent)
		ft_printf("rb\n");
}

void	rr(t_que *arr_a, t_que *arr_b, int is_silent)
{
	rotate(arr_a, 1);
	rotate(arr_b, 1);
	if (!is_silent)
		ft_printf("rr\n");
}

void	rra(t_que *arr_a, int is_silent)
{
	rotate(arr_a, -1);
	if (!is_silent)
		ft_printf("rra\n");
}

void	rrb(t_que *arr_b, int is_silent)
{
	rotate(arr_b, -1);
	if (!is_silent)
		ft_printf("rra\n");
}
