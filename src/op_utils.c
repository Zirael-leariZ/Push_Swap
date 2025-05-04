/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:29:33 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/04 13:42:06 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

void	rotate(t_que *arr, int i)
{
	if (!arr)
		return ;
	if (i == 1)
		arr->head = arr->head->prv;
	if (i == -1)
		arr->head = arr->head->next;
}

void	ft_list_swap(t_que *arr)
{
	int	temp;

	temp = arr->head->val;
	arr->head->val = arr->head->next->val;
	arr->head->next->val = temp;
}

void	delete_head(t_que *arr)
{
	t_que_node *cur_head;
	
	if (!arr || arr->size == 0)
		return;
	cur_head = arr->head;
	if (arr->size == 1)
	{
		free(arr->head);
		arr->head = NULL;
	}
	else
	{
		arr->head->prv->next = arr->head->next;
		arr->head->next->prv = arr->head->prv;
		arr->head = arr->head->next;
		free(cur_head);
	}
	arr->size--;
}

int	move_counter_ahead(t_que *que_list, int digit, int direction)
{
	t_que	*cpy;
	int		i;

	cpy = que_list;
	i = 0;
	while (i < que_list->size)
	{
		if (digit == cpy->head->val)
			return (i);
		if (direction == 1)
			cpy->head = cpy->head->next;
		else if (direction == -1)
			cpy->head = cpy->head->prv;
		i++;
	}
	return (-1);
}
