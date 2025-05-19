/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:34:44 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 15:18:46 by oishchen         ###   ########.fr       */
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
	return (0);
}

t_que	*parse_input(int ac, char *av[])
{
	int		i;
	t_que	*arr_a;
	char	*input;
	int		cur_pos;

	cur_pos = 0;
	i = 1;
	arr_a = create_list();
	if (!arr_a)
		return (NULL);
	while (av[i] && ac > 1)
	{
		input = no_space_str(av[i], input, &cur_pos);
		if ((!input && av[i][cur_pos]) || (!input && ft_strlen(av[i]) == 0))
			free_each_node_exit(&arr_a, 1);
		else if (input && !atoi_to_que(input, &arr_a, 1))
			return (free(input), free_each_node_exit(&arr_a, 1), NULL);
		free(input);
		if (!av[i][cur_pos])
		{
			i++;
			cur_pos = 0;
		}
	}
	return (arr_a);
}
