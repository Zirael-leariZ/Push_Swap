/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:30:23 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 15:33:56 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	command_exe(t_que *a, t_que *b, char *line)
{
	if (ft_strncmp(line, "pb\n", 3) == 0)
		pb_silent(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b, 1);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, 1);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, 1);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, 1);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, 1);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, 1);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, 1);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, 1);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, 1);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, 1);
	else
		return (0);
	return (1);
}

int	append_command(t_ops **my_ops, char *line)
{
	t_ops	*temp;
	t_ops	*last;

	temp = malloc(sizeof(t_ops));
	if (!temp)
		return (0);
	temp->command = ft_strdup(line);
	if (!temp->command)
		return (free(temp), 0);
	last = ft_find_last(*my_ops);
	if (!last)
		*my_ops = temp;
	else
		last->next = temp;
	temp->next = NULL;
	return (1);
}

t_ops	*rg_ops(t_que **a, t_que **b)
{
	char	*line;
	t_ops	*my_ops;
	int		*arr_int;

	arr_int = NULL;
	arr_int = ft_sort(a, arr_int);
	free(arr_int);
	my_ops = NULL;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!is_such_command(line) || !append_command(&my_ops, line))
		{
			free(line);
			free_ops(&my_ops);
			free_each_node(a);
			free_each_node_exit(b, 1);
		}
		if (line)
			free(line);
		line = get_next_line(0);
	}
	return (my_ops);
}

int	check_list(t_que *a)
{
	int	i;

	i = 0;
	if (a->size <= 1)
		return (1);
	while (i < a->size - 1)
	{
		if (a->head->index > a->head->next->index)
		{
			return (0);
		}
		a->head = a->head->next;
		i++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_que	*a;
	t_que	*b;
	t_ops	*my_ops;

	if (ac > 1)
	{
		a = parse_input(ac, av);
		if (!a)
			return (write(1, "KO\n", 3), 1);
		b = create_list();
		if (!b)
			free_each_node_exit(&a, 1);
		my_ops = rg_ops(&a, &b);
		if (apply_ops(a, b, my_ops) && check_list(a) && b->size == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_each_node(&a);
		free_ops(&my_ops);
		free_each_node_exit(&b, 0);
	}
	return (0);
}
