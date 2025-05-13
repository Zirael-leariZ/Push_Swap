/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:29:36 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/13 11:40:18 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_que *arr_a)
{
	if (arr_a->size > 1)
	{
		ft_list_swap(arr_a);
		ft_printf("sa\n");
	}
}

void	sb(t_que *arr_b)
{
	if (arr_b->size > 1)
	{
		ft_list_swap(arr_b);
		ft_printf("sb\n");
	}
}

void	ss(t_que *arr_a, t_que *arr_b)
{
	if (arr_a->size > 1 && arr_b->size > 1)
	{
		ft_list_swap(arr_a);
		ft_list_swap(arr_b);
		ft_printf("ss\n");
	}
}

void	pb(t_que *arr_a, t_que *arr_b)
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
	ft_printf("pb\n");
}

void	pa(t_que *arr_a, t_que *arr_b)
{
	t_que_node	*temp;

	if (arr_b->size == 0 || !arr_b || !arr_a)
		return ;
	if (arr_b->size > 1)
	{
		temp = arr_b->head->next;
		arr_b->head->next->prv = arr_b->head->prv;
		arr_b->head->prv->next = arr_b->head->next;
	}
	else
		temp = NULL;
	arr_b->head->prv = arr_a->head->prv;
	arr_b->head->next = arr_a->head;
	arr_a->head->prv->next = arr_b->head;
	arr_a->head->prv = arr_b->head;
	arr_a->head = arr_b->head;
	arr_b->head = temp;
	arr_a->size++;
	arr_b->size--;
	ft_printf("pa\n");
}
