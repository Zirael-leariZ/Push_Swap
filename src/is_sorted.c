/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:51:47 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 12:35:45 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_que_node *a_node, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (a_node->index > a_node->next->index)
			return (0);
		i++;
		a_node = a_node->next;
	}
	return (1);
}

int	rewind_que(t_que *a, int begin_idx)
{
	int	pivot;

	pivot = a->size / 2;
	if (begin_idx > pivot)
	{
		begin_idx = a->size - begin_idx;
		while (begin_idx--)
			rra(a, 0);
	}
	else
		while (begin_idx--)
			ra(a, 0);
	return (1);
}

int	is_fully_sorted(t_que *a)
{
	t_que_node	*a_node;
	int			i;
	int			flg;

	i = 0;
	flg = 0;
	a_node = a->head;
	while (i < a->size)
	{
		flg = is_sorted(a_node, a->size);
		if (flg)
			return (rewind_que(a, i));
		a_node = a_node->next;
		i++;
	}
	return (0);
}

void	three_sort(t_que *a)
{
	while (!is_fully_sorted(a) && a->size > 1)
	{
		if (a->head->prv->index < a->head->next->index)
			rra(a, 0);
		if (a->head->index > a->head->next->index)
			sa(a, 0);
		if (a->head->index > a->head->next->index)
			ra(a, 0);
	}
}
