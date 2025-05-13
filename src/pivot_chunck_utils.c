/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_chunck_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:43:16 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/13 08:43:08 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_ra(t_que	*a, int high_border)
{
	t_que_node	*a_node;
	int			ra_nb;

	ra_nb = 0;
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

int	nb_rb(t_que *b, int border_high, int border_low)
{
	t_que_node	*b_node;
	int			border;

	if (!b->head || !b)
		return (0);
	border = (border_high - border_low) / 2 + border_low;
	if (border_high == border_low)
		border = border_high / 2;
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
				rr(a, b);
			while (ra_nb--)
				ra(a);
		}
		else
			while (rb_nb--)
				rb(b);
	}
	else
	{
		while(ra_nb--)
			ra(a);
		while (rb_nb--)
			rb(b);
	}
}

int	nb_rra(t_que *a, int high_border)
{
	t_que_node	*a_node;
	int			rra_nb;

	a_node = a->head;
	rra_nb = 0;
	while (a_node->index > high_border && a->size > 3 && rra_nb < a->size)
	{
		rra_nb++;
		a_node = a_node->prv;
	}
	if (rra_nb == a->size)
		return (0);
	return (rra_nb);
}

void	prep_que(t_que *a, t_que *b, int low_border, int high_border)
{
	int	ra_nb;
	int	rb_nb;
	int	rra_nb;

	ra_nb = nb_ra(a, high_border);
	rra_nb = nb_rra(a, high_border);
	rb_nb = nb_rb(b, high_border, low_border);
	if (rra_nb < ra_nb)
	{
		while (rra_nb--)
			rra(a);
		while (rb_nb--)
			rb(b);
	}
	else
		ra_rb_rr(a, b, ra_nb, rb_nb);
}

// main_eff_function(XD)
// {
// 	while (i < size/2) // firstly direction -> a - b_cur '-' & a - b_next '+'
// 	{
// 		is_right_pos = index_diff2(a, b, 1);
// 		i++;
// 		if (is_right_pos)
// 			count_moves(t_que *)
// 		a = a->next;
// 	}
// }

// formula to count the difference between head->prv && head->next;
// t_que_node	*index_diff2(t_que *a_list, t_que *b_list, int *direction, int size)
// {
// 	int	is_good_pos;
// 	t_que_node	*a;
// 	t_que_node	*b_cur;
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	is_good_pos = 0;
// 	a = a_list->head;
// 	b_cur = b_list->head;
// 	while (i < (size / 2) && !is_good_pos)
// 	{
// 		is_good_pos = (a->index - b_cur->index > 0);
// 		b_cur = b_cur->next;
// 		i++;
// 	}
// 	is_good_pos = 0;
// 	a = a_list->head;
// 	b_cur = b_list->head;
// 	while (j < (size / 2) && !is_good_pos)
// 	{
// 		a = a_list->head;
// 		b_cur = b_list->head;
// 		is_good_pos = (a->index - b_cur->index > 0);
// 		b_cur = b_cur->prv;
// 		j++;
// 	}
// 	if (is_good_pos)
// 	{
// 		if (i < j)
// 		{
// 			*direction = 1;
// 			return (i);
// 		}
// 		else
// 		{
// 			*direction = -1;
// 			return (j - 1);
// 		}
// 	}
// 	else // in case of else we need to return the position with lesser difference
// 		return (0);
// }


// t_que_node	*template_function(int good_pos, int direction, int steps)
// {

// }

/*
now how do we count the position for insertion?
function that takes node_a and node_b
find_place(t_que_node *a, t_que_node *b)

then we compare the index of a with the index of b prv (b prv should be bigger)
the diff should be negative: 

index_cmp_bc(a->index, b->prv->index);

same thing for b, but now b should be less (the diff should be positive)

index_cmp_nxt(a->index, b); 

now, the indexes should have some values, ideally bc will be negative and nxt positive 

LET'S NOW TRY EASIER VERSION WITHOUT EFFICIENCY COUNT, 
so if the prv index is - and the current + we try to push this value(we also will be pushing untill a array is bigger than 1)

if : index_cmp_bc - && index_cmp_nxt + => count_steps
*create a value, called min moves counter = count_steps
we will need to count each a->val for each gap b->prv && b || b && b->next or we can do like that 
count until (i < size / 2)
	a && b <=> b->next, b = b->next; 
	and then to count the moves , same for 
	a && b->prv <=> b, b = b->prv; 
	then we save the current min and current a value, and if next a value costs less we save the next value and so on

	Overall: 
	1) create an algorithm that takes a head->val from the stack and compare it with one direction of b stack, while preserving the sign of subtraction
*/

// int	eff_right_pos(t_que *que_list_a, t_que *que_list_b, int *sorted_arr)
// {
// 	t_que_node	*temp_a = que_list_a->head;
// 	t_que_node	*temp_b = que_list_b->head;
// 	double		minmin;
// 	double		cur_min;
// 	int			distance;
// 	int			direction;

// 	int	index_b = find_index(sorted_arr, temp_a->val);
// 	int	index_a = find_index(sorted_arr, temp_b->val);
// 	while (i < que_list_a->size)
// 	{
// 		cur_digit = temp_a->val;
// 		index_a = (sorted_arr, cur_digit);
// 		diff_index = index_diff(index_a, index_b); // if + just pa, else rra
// 		if (diff_index < 0)
// 			abs_diff = -diff_index;
// 		else
// 			abs_diff = diff_index;
// 		diff_efficiency = abs_diff / ((size - 1)  / pushed_nb);// all should be in double
// 		// the closer to 1 the better


// 		distance_ahead = move_counter(que_list_a, cur_digit, 1);
// 		distance_back = move_counter(que_list_a, cur_digit, -1);
// 		if (distance_ahead > distance_back)
// 			distance = distance_back;
// 		else
// 			distance = distance_ahead;

// 		int	efficiency = abs_min + distance; // but we do not want diff_index to be too low
// 	}
// }
