/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:29:33 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 12:31:41 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

void	rotate(t_que *arr, int i)
{
	if (!arr)
		return ;
	if (i == -1)
		arr->head = arr->head->prv;
	if (i == 1)
		arr->head = arr->head->next;
}

void	ft_list_swap(t_que *arr)
{
	int	data;
	int	index;

	if (arr->size > 1)
	{
		data = arr->head->val;
		index = arr->head->index;
		arr->head->val = arr->head->next->val;
		arr->head->index = arr->head->next->index;
		arr->head->next->index = index;
		arr->head->next->val = data;
	}
}

int	find_min_idx(t_que *a)
{
	t_que_node	*temp;
	int			min;
	int			i;

	temp = a->head;
	min = temp->index;
	i = 0;
	while (i < a->size)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
		i++;
	}
	return (min);
}

int	find_max_idx(t_que *a)
{
	int			max;
	int			i;
	t_que_node	*temp;

	temp = a->head;
	max = temp->index;
	i = 0;
	while (i < a->size)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
		i++;
	}
	return (max);
}
