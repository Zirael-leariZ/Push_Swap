/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:58:14 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/01 15:00:36 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arr(int *arr_int, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_printf("%d ", arr_int[i++]);
	ft_printf("\n");
}

int	*cpy_que(t_que *arr_a)
{
	int		*cpy_arr;
	int		i;
	t_que	*temp;

	if (!arr_a)
		return ((void *)0);
	cpy_arr = malloc(arr_a->size);
	if (!cpy_arr)
		free_each_node_exit(&arr_a);
	i = 0;
	temp = arr_a;
	while (i < arr_a->size)
	{
		cpy_arr[i] = temp->head->val;
		temp->head = temp->head->next;
		i++;
	}
	return (cpy_arr);
}
