/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:22:26 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/15 23:02:27 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_in_que (t_que *a, int border)
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
		while (nodes < b->size)
		{
			cur_steps = count_steps(a, b, temp);
			if (steps > cur_steps || (steps == cur_steps && temp->index < min_node->index))
			{
				min_node = temp;
				steps = cur_steps;
			}
			temp = temp->next;
			nodes++;
		}
		push_to_a(a, b, min_node);
	}
}

// void	pivot_sort(t_que *a, t_que *b)
// {
// 	int	push_nb;
// 	int	pivot;

// 	push_nb = 0;
	
// 	pivot = a->size / 2;
// 	while (push_nb <= pivot && a->size > 3)
// 	{
// 		if (a->head->index <= pivot)
// 		{
// 			pb(a, b);
// 			push_nb++;
// 		}
// 		prep_que(a, b, pivot, 1);
// 		check_sa_ss_sb(a, b);
// 	}
// 	if (a->size == 3)
// 		three_sort(a);
// }

void	chunck_sort(t_que *a, t_que *b)
{
	int	chunck;
	int	i;

	i = 1;
	if (a->size + b->size >= 450)
		chunck = 50;
	if (a->size + b->size < 450 && a->size + b->size >= 100)
		chunck = 25;
	else if (a->size + b->size < 100)
		chunck = 20;
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
	three_sort(a);
}