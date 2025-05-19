/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:41:59 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 12:09:31 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_que	*append_value_bottom(t_que **lst, int data)
{
	t_que_node	*new;

	if (!lst)
		return (NULL);
	new = (t_que_node *)malloc(sizeof(t_que_node));
	if (!new)
		free_each_node_exit(lst, 1);
	if ((*lst)->size == 0)
	{
		new->next = new;
		new->prv = new;
		(*lst)->head = new;
	}
	else
	{
		new->next = (*lst)->head;
		new->prv = (*lst)->head->prv;
		(*lst)->head->prv->next = new;
		(*lst)->head->prv = new;
	}
	new->val = data;
	(*lst)->size++;
	return (*lst);
}

void	free_each_node_exit(t_que **arr, int status)
{
	t_que_node	*temp;
	int			i;

	i = 0;
	if ((*arr)->size > 0)
	{
		temp = (*arr)->head;
		while (i < (*arr)->size)
		{
			(*arr)->head = (*arr)->head->next;
			free(temp);
			temp = (*arr)->head;
			i++;
		}
	}
	if (*arr)
		free(*arr);
	exit(status);
}

void	free_each_node(t_que **arr)
{
	t_que_node	*temp;
	int			i;

	i = 0;
	if ((*arr)->head)
	{
		temp = (*arr)->head;
		while (i < (*arr)->size)
		{
			(*arr)->head = (*arr)->head->next;
			free(temp);
			temp = (*arr)->head;
			i++;
		}
	}
	if (*arr)
		free(*arr);
}

t_que	*create_list(void)
{
	t_que	*lst;

	lst = (t_que *)malloc(sizeof(t_que));
	if (!lst)
		return ((void *)0);
	lst->head = NULL;
	lst->size = 0;
	return (lst);
}

int	calc_chunck(t_que *a, t_que *b)
{
	int	chunck;

	if (a->size + b->size >= 450)
		chunck = 50;
	if (a->size + b->size < 450 && a->size + b->size >= 100)
		chunck = 25;
	else if (a->size + b->size < 100)
		chunck = 20;
	return (chunck);
}
