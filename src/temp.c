/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:04:24 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/13 17:42:18 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_circular_arr(t_que *arr, char *arr_type)
{
	t_que	*temp = arr;
	int		i;

	i = 0;
	if (arr->head)
	{
		ft_printf("%s, head: %d\n", arr_type, arr->head->val);
		ft_printf("%s, size: %d\n", arr_type, arr->size);
	}
	while (i < arr->size)
	{
		ft_printf("%s Our data: %d index: %d\n", arr_type, temp->head->val, temp->head->index);
		temp->head = temp->head->next;
		i++;
	}
}

void	print_arr(int *arr_int, int size, char *which_arr) // works
{
	int	i;

	i = 0;
	ft_printf("%s ", which_arr);
	while (i < size)
	{
		ft_printf("%d ", arr_int[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_index(t_que *arr, char *message)
{
	int	i;
	t_que_node *temp;

	i = 0;
	temp = arr->head;
	while (i < arr->size)
	{
		ft_printf("%s that is the val %d, that is index %d\n", message, temp->val, temp->index);
		temp = temp->next;
		i++;
	}
}
