/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:41:59 by oishchen          #+#    #+#             */
/*   Updated: 2025/04/29 12:13:35 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_que	*append_value_bottom(t_que *lst, int data)
{
	t_que_node *new;

	if (!lst)
		return (NULL);
	new = (t_que_node *)malloc(sizeof(t_que_node));
	if (!new)
		return (NULL);
	if ((lst)->size == 0)
	{
		new->next = new;
		new->prv = new;
		lst->head = new;
	}
	else
	{
		new->next = (lst)->head;
		new->prv = (lst)->head->prv;
		lst->head->prv->next = new;
		lst->head->prv = new;
	}
	new->val = data;
	lst->size++;
	return (lst);
}

void	free_each_node_exit(t_que **arr)
{
	t_que_node	*temp;
	int		i;

	i = 0;
	temp = (*arr)->head;
	while (i < (*arr)->size)
	{
		(*arr)->head = (*arr)->head->next;
		free(temp);
		temp = (*arr)->head;
		i++;
	}
	free(*arr);
	exit(1);
}

t_que	*create_list(void)
{
	t_que	*lst;

	lst = (t_que *)malloc(sizeof(t_que));
	if (!lst)
		return (NULL);
	lst->head = NULL;
	lst->size = 0;
	return (lst);
}
