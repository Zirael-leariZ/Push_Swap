/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:16:24 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/15 21:51:30 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_que *arr_a, t_que *arr_b, int is_silent)
{
	rotate(arr_a, -1);
	rotate(arr_b, -1);
	if (!is_silent)
		ft_printf("rrr\n");
}

void	pb_silent(t_que *arr_a, t_que *arr_b)
{
	t_que_node	*temp;

	temp = arr_a->head->next;
	arr_a->head->prv->next = arr_a->head->next;
	arr_a->head->next->prv = arr_a->head->prv;
	if (arr_b->head)
	{
		arr_a->head->prv = arr_b->head->prv;
		arr_a->head->next = arr_b->head;
		arr_b->head->prv->next = arr_a->head;
		arr_b->head->prv = arr_a->head;
		arr_b->head = arr_a->head;
	}
	else
	{
		arr_b->head = arr_a->head;
		arr_b->head->next = arr_a->head;
		arr_b->head->prv = arr_a->head;
		arr_a->head->next = arr_b->head;
		arr_a->head->prv = arr_b->head->prv;
	}
	arr_a->head = temp;
	arr_b->size++;
	arr_a->size--;
}
