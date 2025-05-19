/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_chunck_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:43:16 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 10:24:54 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_ra(t_que	*a, t_que *b, int chunck, int t_used)
{
	t_que_node	*a_node;
	int			ra_nb;
	int			high_border;

	(void)a;
	(void)b;
	ra_nb = 0;
	high_border = chunck * t_used;
	if (b->size < a->size)
		high_border = (a->size + b->size) / 2;
	a_node = a->head;
	while (ra_nb < a->size && a_node->index > high_border)
	{
		ra_nb++;
		a_node = a_node->next;
	}
	if (ra_nb == a->size)
		return (0);
	return (ra_nb);
}

int	nb_rb(t_que *a, t_que *b, int chunck, int t_used)
{
	t_que_node	*b_node;
	int			border;

	(void)a;
	(void)b;
	if (!b->head || !b)
		return (0);
	border = (chunck) / 2 + (chunck * (t_used - 1));
	if (b->size < a->size)
		border = (a->size + b->size) / 4;
	b_node = b->head;
	if (b_node->index <= border && b_node->index < b_node->next->index)
		return (1);
	return (0);
}

void	ra_rb_rr(t_que *a, t_que *b, int ra_nb, int rb_nb)
{
	if (ra_nb > 0 && rb_nb > 0)
	{
		if (ra_nb >= rb_nb)
		{
			ra_nb -= rb_nb;
			while (rb_nb--)
				rr(a, b, 0);
			while (ra_nb--)
				ra(a, 0);
		}
		else
			while (rb_nb--)
				rb(b, 0);
	}
	else
	{
		while (ra_nb--)
			ra(a, 0);
		while (rb_nb--)
			rb(b, 0);
	}
}

int	nb_rra(t_que *a, t_que *b, int chunck, int t_used)
{
	t_que_node	*a_node;
	int			rra_nb;
	int			high_border;

	(void)a;
	(void)b;
	high_border = chunck * t_used;
	if (b->size < a->size)
		high_border = (a->size + b->size) / 2;
	a_node = a->head;
	rra_nb = 0;
	while (a_node->index > high_border && rra_nb < a->size)
	{
		rra_nb++;
		a_node = a_node->prv;
	}
	if (rra_nb == a->size)
		return (0);
	return (rra_nb);
}

void	prep_que(t_que *a, t_que *b, int chunck, int t_used)
{
	int	ra_nb;
	int	rb_nb;
	int	rra_nb;

	ra_nb = nb_ra(a, b, chunck, t_used);
	rra_nb = nb_rra(a, b, chunck, t_used);
	rb_nb = nb_rb(a, b, chunck, t_used);
	if (rra_nb < ra_nb)
	{
		while (rra_nb--)
			rra(a, 0);
		while (rb_nb--)
			rb(b, 0);
	}
	else
		ra_rb_rr(a, b, ra_nb, rb_nb);
}
