/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_sort_exe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:55:44 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 11:47:58 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exe_rb_rra(t_que *a, t_que *b, int rb_nb, int rra_nb)
{
	while (rb_nb--)
		rb(b, 0);
	while (rra_nb--)
		rra(a, 0);
}

void	exe_rb_ra(t_que *a, t_que *b, int rb_nb, int ra_nb)
{
	if (rb_nb <= ra_nb)
	{
		ra_nb -= rb_nb;
		while (rb_nb--)
			rr(a, b, 0);
		while (ra_nb--)
			ra(a, 0);
	}
	else
	{
		rb_nb -= ra_nb;
		while (ra_nb--)
			rr(a, b, 0);
		while (rb_nb--)
			rb(b, 0);
	}
}

void	exe_rrb_ra(t_que *a, t_que *b, int rrb_nb, int ra_nb)
{
	while (rrb_nb--)
		rrb(b, 0);
	while (ra_nb--)
		ra(a, 0);
}

void	exe_rrb_rra(t_que *a, t_que *b, int rrb_nb, int rra_nb)
{
	if (rrb_nb <= rra_nb)
	{
		rra_nb -= rrb_nb;
		while (rrb_nb--)
			rrr(a, b, 0);
		while (rra_nb--)
			rra(a, 0);
	}
	else
	{
		rrb_nb -= rra_nb;
		while (rra_nb--)
			rrr(a, b, 0);
		while (rrb_nb--)
			rrb(b, 0);
	}
}

int	count_ra(t_que *a, t_que_node *b_node)
{
	t_que_node	*temp;
	int			ra;
	int			is_found;
	int			min_idx;
	int			max_idx;

	temp = a->head;
	ra = 0;
	min_idx = find_min_idx(a);
	max_idx = find_max_idx(a);
	is_found = (temp->prv->index < b_node->index
			&& temp->index > b_node->index)
		|| (b_node->index < min_idx && temp->index == min_idx)
		|| (b_node->index > max_idx && temp->prv->index == max_idx);
	while (!is_found)
	{
		temp = temp->next;
		ra++;
		is_found = (temp->prv->index < b_node->index
				&& temp->index > b_node->index)
			|| (b_node->index < min_idx && temp->index == min_idx)
			|| (b_node->index > max_idx && temp->prv->index == max_idx);
	}
	return (ra);
}
