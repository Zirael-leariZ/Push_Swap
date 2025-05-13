/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:15:17 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/13 15:35:20 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
if rb_or_rrb = 1, rb was the most efficient
if rb_or_rrb = -1, rrb was the most efficient
*/

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

int	count_ra(t_que *a, t_que_node *b_node)
{
	t_que_node	*temp;
	int			ra;
	int			is_found;
	int			min_idx;

	temp = a->head;
	ra = 0;
	min_idx = find_min_idx(a);
	is_found = (temp->prv->index < b_node->index
			&& temp->index > b_node->index)
			|| (b_node->index < min_idx && temp->index == min_idx);
	while (!is_found)
	{
		temp = temp->next;
		ra++;
		is_found = (temp->prv->index < b_node->index
			&& temp->index > b_node->index)
			|| (b_node->index < min_idx && temp->index == min_idx);
	}
	return (ra);
}

int	count_rra(t_que *a, t_que_node *b_node)
{
	t_que_node	*temp;
	int			rra;
	int			is_found;
	int			min_idx;

	temp = a->head;
	min_idx = find_min_idx(a);
	rra = 0;
	is_found = (temp->prv->index < b_node->index
			&& temp->index > b_node->index)
			|| (b_node->index < min_idx && temp->index == min_idx);
	while (!is_found)
	{
		temp = temp->prv;
		rra++;
		is_found = (temp->prv->index < b_node->index
			&& temp->index > b_node->index)
			|| (b_node->index < min_idx && temp->index == min_idx);
	}
	return (rra);
}

int	steps_in_a(t_que *a, t_que_node *b_node, int *ra_or_rra)
{
	t_que_node	*temp;
	int			ra;
	int			rra;
	int			is_found;

	ra = 0;
	rra = 0;
	temp = a->head;
	is_found = 0;
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

	// ft_printf("current node->idx is: %d\n", b_node->index);
	b_to_right_pos = steps_in_b(b, b_node, &rb_or_rrb);
	// ft_printf("steps in b: %d, direction: %d\n", b_to_right_pos, rb_or_rrb);
	a_to_right_pos = steps_in_a(a, b_node, &ra_or_rra);
	// ft_printf("steps in a: %d, direction: %d\n", a_to_right_pos, ra_or_rra);
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
		pa(a, b);
		return ;
	}
	if (rb_or_rrb == 1)
		exe_rb_rra(a, b, b_right_pos, a_right_pos);
	else
		exe_rrb_ra(a, b, b_right_pos, a_right_pos);
	pa(a, b);
	return ;
}
void	exe_rb_rra(t_que *a, t_que *b, int rb_nb, int rra_nb)
{
	while (rb_nb--)
		rb(b);
	while (rra_nb--)
		rra(a);
}

void	exe_rb_ra(t_que *a, t_que *b, int rb_nb, int ra_nb)
{
	if (rb_nb <= ra_nb)
	{
		ra_nb -= rb_nb;
		while (rb_nb--)
			rr(a, b);
		while (ra_nb--)
			ra(a);
	}
	else
	{
		rb_nb -= ra_nb;
		while (ra_nb--)
			rr(a, b);
		while (rb_nb--)
			rb(b);
	}
}

void	exe_rrb_ra(t_que *a, t_que *b, int rrb_nb, int ra_nb)
{
	while (rrb_nb--)
		rrb(b);
	while (ra_nb--)
		ra(a);
}

void	exe_rrb_rra(t_que *a, t_que *b, int rrb_nb, int rra_nb)
{
	if (rrb_nb <= rra_nb)
	{
		rra_nb -= rrb_nb;
		while (rrb_nb--)
			rrr(a, b);
		while (rra_nb--)
			rra(a);
	}
	else
	{
		rrb_nb -= rra_nb;
		while (rra_nb--)
			rrr(a, b);
		while (rrb_nb--)
			rrb(b);
	}
}
