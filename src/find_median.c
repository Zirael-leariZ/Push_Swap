/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:58:14 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/01 12:58:33 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cpy_que(t_que *arr_a)
{
	int		*cpy_arr;
	int		i;
	t_que	*temp;

	cpy_arr = malloc(arr_a->size);
	i = 0;
	temp = arr_a;
	while (i < arr_a->size)
	{
		cpy_arr[i] = temp->head->val;
		temp->head = temp->head->next;
		i++;
	}
	return (arr_a);
}