/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:29:33 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/09 18:12:02 by oishchen         ###   ########.fr       */
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
	if (i == -1)
		arr->head = arr->head->prv;
	if (i == 1)
		arr->head = arr->head->next;
}

void	ft_list_swap(t_que *arr)
{
	int	data;
	int	index;

	if (arr->size > 1)
	{
		data = arr->head->val;
		index = arr->head->index;
		arr->head->val = arr->head->next->val;
		arr->head->index = arr->head->next->index;
		arr->head->next->index = index;
		arr->head->next->val = data;
	}
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


