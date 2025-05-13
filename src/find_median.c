/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:58:14 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/08 12:42:39 by oishchen         ###   ########.fr       */
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
		free_each_node_exit(&arr_a);
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

int	*sort_arr(int *arr, int size)
{
	int	i;
	int temp;
	int	*res;

	i = 0;
	while(i < size - 1)
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
		return (free(arr), NULL);
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

void	assign_index(t_que **que_list, int *sorted_arr)
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
			ft_printf("ERROR WITH INDEX ALLOCATION\n"); // delete that after
			free(sorted_arr);
			free_each_node_exit(que_list);
		}
		i++;
		temp = temp->next;
	}
}

int	*ft_sort(t_que **que_arr)
{
	int	*arr_int;
	int	*arr_sorted;

	arr_int = cpy_que(*que_arr);
	if (!arr_int)
		free_each_node_exit(que_arr);
	arr_sorted = sort_arr(arr_int, (*que_arr)->size);
	free(arr_int);
	if (!arr_sorted)
		free_each_node_exit(que_arr);
	print_arr(arr_sorted, (*que_arr)->size, "sorted_arr");
	assign_index(que_arr, arr_sorted);
	return (arr_sorted);
}