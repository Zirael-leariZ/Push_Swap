/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:34:44 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 12:36:20 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops	*ft_find_last(t_ops *my_ops)
{
	t_ops	*temp;

	if (!my_ops || !my_ops->command)
		return (NULL);
	temp = my_ops;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	apply_ops(t_que *a, t_que *b, t_ops *my_ops)
{
	int		res;
	t_ops	*temp;

	temp = my_ops;
	while (temp)
	{
		res = command_exe(a, b, temp->command);
		if (!res)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	free_ops(t_ops **ops)
{
	t_ops	*current;
	t_ops	*next;

	if (!ops)
		return ;
	current = *ops;
	while (current)
	{
		next = current->next;
		free(current->command);
		free(current);
		current = next;
	}
	*ops = NULL;
}

int	is_such_command(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp("ss\n", str, len) == 0
		|| ft_strncmp("sa\n", str, len) == 0
		|| ft_strncmp("sb\n", str, len) == 0
		|| ft_strncmp("pa\n", str, len) == 0
		|| ft_strncmp("pb\n", str, len == 0
			|| ft_strncmp("ra\n", str, len) == 0
			|| ft_strncmp("rb\n", str, len) == 0
			|| ft_strncmp("rra\n", str, len) == 0
			|| ft_strncmp("rrb\n", str, len) == 0
			|| ft_strncmp("rr\n", str, len) == 0
			|| ft_strncmp ("rrr\n", str, len)) == 0)
		return (1);
	return (1);
}
