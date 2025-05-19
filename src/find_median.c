/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:58:14 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 12:32:52 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cpy_que(t_que *arr_a) // works
{
	int			*cpy_arr;
	int			i;
	t_que_node	*temp;

	if (!arr_a)
		return ((void *)0);
	cpy_arr = (int *)malloc(arr_a->size * sizeof(int));
	if (!cpy_arr)
		free_each_node_exit(&arr_a, 1);
	i = 0;
	temp = arr_a->head;
	while (i < arr_a->size)
	{
		cpy_arr[i] = temp->val;
		temp = temp->next;
		i++;
	}
	return (cpy_arr);
}

int	*sort_arr(int *arr, int size, t_que **a)
{
	int	i;
	int	temp;
	int	*res;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	res = (int *)malloc(size * sizeof(int));
	if (!res)
		return (free(arr), free_each_node_exit(a, 1), NULL);
	i = -1;
	while (++i < size)
		res[i] = arr[i];
	return (res);
}

int	find_index(int *arr_int, int size, int digit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr_int[i] == digit)
			return (i);
		i++;
	}
	return (-1);
}

int	assign_index(t_que **que_list, int *sorted_arr)
{
	int			i;
	t_que_node	*temp;

	i = 0;
	temp = (*que_list)->head;
	while (i < (*que_list)->size)
	{
		temp->index = find_index(sorted_arr, (*que_list)->size, temp->val);
		if (temp->index == -1)
		{
			free(sorted_arr);
			return (free_each_node(que_list), 0);
		}
		i++;
		temp = temp->next;
	}
	return (1);
}

int	*ft_sort(t_que **que_arr, int *arr_sorted)
{
	int	*arr_int;

	arr_int = cpy_que(*que_arr);
	if (!arr_int)
		free_each_node_exit(que_arr, 1);
	arr_sorted = sort_arr(arr_int, (*que_arr)->size, que_arr);
	free(arr_int);
	if (!arr_sorted)
		return (free_each_node(que_arr), (void *)0);
	if (!assign_index(que_arr, arr_sorted))
		return ((void *)0);
	return (arr_sorted);
}
