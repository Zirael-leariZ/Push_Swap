/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:32:29 by oishchen          #+#    #+#             */
/*   Updated: 2025/04/28 12:15:47 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_que *arr_a)
{
	rotate(arr_a, 1);
	ft_printf("ra\n");
}

void	rb(t_que *arr_b)
{
	rotate(arr_b, 1);
	ft_printf("rb\n");
}

void	rr(t_que *arr_a, t_que *arr_b)
{
	rotate(arr_a, 1);
	rotate(arr_b, 1);
	ft_printf("rr\n");
}

void	rra(t_que *arr_a)
{
	rotate(arr_a, -1);
	ft_printf("rra\n");
}