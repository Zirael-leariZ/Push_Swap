/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:22:26 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/13 15:37:36 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (steps > cur_steps)
			{
				min_node = temp;
				steps = cur_steps;
			}
			temp = temp->next;
			nodes++;
		}
		// ft_printf("our min_node idx: %d\n", min_node->index);
		// ft_printf("our head in a: %d\n", a->head->index);
		push_to_a(a, b, min_node);
	}
}

void	pivot_sort(t_que *a, t_que *b)
{
	int	push_nb;
	int	pivot;

	push_nb = 0;
	//
	pivot = a->size / 2;
	// ft_printf("pivot is : %d\n", pivot);
	//
	if (!is_fully_sorted(a))
	{
		while (push_nb <= pivot && a->size > 3)
		{
			if (a->head->index <= pivot)
			{
				pb(a, b);
				push_nb++;
			}
			prep_que(a, b, pivot, pivot);
		}
		// ft_printf("push_nb: %d\n", push_nb);
	}
	if (a->size == 3)
		three_sort(a);
}

void	chunck_sort(t_que *a, t_que *b)
{
	int	push_nb;
	int	pivot;
	int	low_border;

	while (a->size > 3)
	{
		low_border = b->size;
		pivot = a->size / 2 + b->size;
		push_nb = b->size;
		// ft_printf("our pivot: %d\n", pivot);
		// ft_printf("our low_border: %d\n", low_border);
		// ft_printf("our push_nb%d\n", push_nb);
		while (push_nb <= pivot && a->size > 3)
		{
			if (a->head->index <= pivot)
			{
				pb(a, b);
				push_nb++;
			}
			prep_que(a, b, low_border, pivot);
		}
		// print_circular_arr(a, "a after first_chucnk");
	}
	three_sort(a);
}
// void	check_pa(t_que *a, t_que *b)
// {
// 	while (b->size > 0)
// 		pa(a, b);
// }