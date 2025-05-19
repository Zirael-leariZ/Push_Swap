/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:22:26 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 10:55:35 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_two(t_que *a, t_que *b)
{
	int			min_idx;
	t_que_node	*a_node;
	int			ra_nb;

	while (a->size != 3)
	{
		a_node = a->head;
		min_idx = find_min_idx(a);
		ra_nb = 0;
		while (a_node->index != min_idx && ra_nb <= a->size / 2)
		{
			ra_nb++;
			a_node = a_node->next;
		}
		if ((ra_nb == a->size / 2 && a_node->index == min_idx)
			|| ra_nb < a->size / 2)
			exe_rb_ra(a, b, 0, ra_nb);
		else
		{
			while (a->head->index != min_idx)
				rra(a, 0);
		}
		pb(a, b);
	}
}

int	index_in_que(t_que *a, int border)
{
	t_que_node	*a_node;
	int			i;

	i = 0;
	a_node = a->head;
	while (i < a->size)
	{
		if (a_node->index < border)
			return (1);
		i++;
		a_node = a_node->next;
	}
	return (0);
}

void	back_sort(t_que *a, t_que *b)
{
	t_que_node	*min_node;
	t_que_node	*temp;
	int			nodes;
	int			cur_steps;
	int			steps;

	while (b->size > 0)
	{
		min_node = b->head;
		nodes = 0;
		temp = b->head;
		steps = count_steps(a, b, temp);
		while (nodes++ < b->size)
		{
			cur_steps = count_steps(a, b, temp);
			if (steps > cur_steps || (steps == cur_steps
					&& temp->index > min_node->index))
			{
				min_node = temp;
				steps = cur_steps;
			}
			temp = temp->next;
		}
		push_to_a(a, b, min_node);
	}
}

void	chunck_sort(t_que *a, t_que *b)
{
	int	chunck;
	int	i;

	if (!is_fully_sorted(a) && a->size > 3)
	{
		i = 1;
		chunck = calc_chunck(a, b);
		while (chunck * i < (a->size + b->size) / 2)
			i++;
		while (a->size > 3)
		{
			while (index_in_que(a, chunck * i) && a->size > 3)
			{
				if (a->head->index <= chunck * i)
					pb(a, b);
				prep_que(a, b, chunck, i);
			}
			i++;
		}
	}
	three_sort(a);
}

void	five_sort(t_que *a, t_que *b)
{
	if (a->size == 5)
	{
		push_two(a, b);
		three_sort(a);
		back_sort(a, b);
		is_fully_sorted(a);
	}
}
