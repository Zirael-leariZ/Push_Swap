/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:15:17 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 12:42:52 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	steps_in_b(t_que *b, t_que_node *b_node, int *rb_or_rrb)
{
	int			rb;
	int			rrb;
	t_que_node	*temp;

	rb = 0;
	temp = b->head;
	while (temp->val != b_node->val)
	{
		rb++;
		temp = temp->next;
	}
	temp = b->head;
	rrb = 0;
	while (temp->val != b_node->val)
	{
		rrb++;
		temp = temp->prv;
	}
	if (rb <= rrb)
	{
		*rb_or_rrb = 1;
		return (rb);
	}
	*rb_or_rrb = -1;
	return (rrb);
}

int	count_rra(t_que *a, t_que_node *b_node)
{
	t_que_node	*temp;
	int			rra;
	int			is_found;
	int			min_idx;
	int			max_idx;

	temp = a->head;
	min_idx = find_min_idx(a);
	max_idx = find_max_idx(a);
	rra = 0;
	is_found = (temp->prv->index < b_node->index
			&& temp->index > b_node->index)
		|| (b_node->index < min_idx && temp->index == min_idx)
		|| (b_node->index > max_idx && temp->prv->index == max_idx);
	while (!is_found)
	{
		temp = temp->prv;
		rra++;
		is_found = (temp->prv->index < b_node->index
				&& temp->index > b_node->index)
			|| (b_node->index < min_idx && temp->index == min_idx)
			|| (b_node->index > max_idx && temp->prv->index == max_idx);
	}
	return (rra);
}

int	steps_in_a(t_que *a, t_que_node *b_node, int *ra_or_rra)
{
	int			ra;
	int			rra;

	ra = 0;
	rra = 0;
	ra = count_ra(a, b_node);
	rra = count_rra(a, b_node);
	if (ra <= rra)
	{
		*ra_or_rra = 1;
		return (ra);
	}
	*ra_or_rra = -1;
	return (rra);
}

int	count_steps(t_que *a, t_que *b, t_que_node *b_node)
{
	int	b_to_right_pos;
	int	a_to_right_pos;
	int	rb_or_rrb;
	int	ra_or_rra;

	b_to_right_pos = steps_in_b(b, b_node, &rb_or_rrb);
	a_to_right_pos = steps_in_a(a, b_node, &ra_or_rra);
	if (rb_or_rrb == ra_or_rra)
	{
		if (b_to_right_pos <= a_to_right_pos)
			return (a_to_right_pos);
		return (b_to_right_pos);
	}
	return (b_to_right_pos + a_to_right_pos);
}

void	push_to_a(t_que *a, t_que *b, t_que_node *b_node)
{
	int	b_right_pos;
	int	a_right_pos;
	int	rb_or_rrb;
	int	ra_or_rra;

	b_right_pos = steps_in_b(b, b_node, &rb_or_rrb);
	a_right_pos = steps_in_a(a, b_node, &ra_or_rra);
	if (rb_or_rrb == ra_or_rra)
	{
		if (rb_or_rrb == 1)
			exe_rb_ra(a, b, b_right_pos, a_right_pos);
		else
			exe_rrb_rra(a, b, b_right_pos, a_right_pos);
		pa(a, b, 0);
		return ;
	}
	if (rb_or_rrb == 1)
		exe_rb_rra(a, b, b_right_pos, a_right_pos);
	else
		exe_rrb_ra(a, b, b_right_pos, a_right_pos);
	pa(a, b, 0);
	return ;
}
