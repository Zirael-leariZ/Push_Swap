/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:27:55 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/03 22:04:47 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_que *que_list)
{
	t_que	*temp;
	t_que	*origin;
	int	median;
	int	i;
	int	lower_bound;
	int	higer_bound;
	int	found;

	origin = que_list;
	found = 0;
	while (!found)
	{
		lower_bound = 0;
		higer_bound = 0;
		temp = que_list;
		median = origin->head->val;
		i = 0;
		while (i < que_list->size)
		{
			if (median < temp->head->val)
				higer_bound++;
			else
				lower_bound++;
			i++;
			temp->head = temp->head->next;
		}
		ft_printf("our size: %d\n", que_list->size);
		ft_printf("our higher_bound: %d\n", higer_bound);
		ft_printf("our lower_bound: %d\n", lower_bound);
		if (higer_bound == lower_bound && que_list->size % 2 == 0)
			found = 1;
		if (lower_bound - 1 == higer_bound && que_list->size % 2 == 1)
			found = 1;
		origin->head = origin->head->next;
	}
	return (median);
}

t_que	*sort_que(t_que *que_a, t_que *que_b)
{
	int	median;
	int	sorted;

	median = find_median(que_a);
	sorted = 0;
	while (!sorted)
	{
		
	}
}