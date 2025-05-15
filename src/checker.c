/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:30:23 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/15 23:50:41 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct	s_ops
{
	void			*command;
	struct s_ops	*next;
} t_ops;

void	free_ops(t_ops **ops)
{
	t_ops	*current;
	t_ops	*next;

	if (!ops)
		return;
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
	// ft_printf("len %d\n", len);
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

int	command_exe(t_que *a, t_que *b, char *line)
{
	ft_printf("we are in\n");
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
	ft_printf("we ar out command exe\n");
	return (1);
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
		{
			ft_printf("NULL IS RETURNED\n");
			return (0);
		}
			
		temp = temp->next;
	}
	ft_printf("ONE IS RETURNED\n");
	ft_printf("SIZE B IS %d\n", b->size);
	return (1);
}

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

int	append_command(t_ops **my_ops, char *line)
{	
	t_ops	*temp;
	t_ops	*last;

	// ft_printf("we are in append_command\n");
	temp = malloc(sizeof(t_ops));
	// ft_printf("after malloc t_ops\n");
	if (!temp)
		return (0);
	temp->command = ft_strdup(line);
	// ft_printf("after temp->command t_ops\n");
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

	my_ops = NULL;
	line = get_next_line(0);
	ft_printf("%s", line);
	while (line != NULL)
	{
		if (!is_such_command(line) || !append_command(&my_ops, line))
		{
			free(line);
			free_ops(&my_ops);
			free_each_node(a);
			free_each_node_exit(b);
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
			return (0);
		a->head = a->head->next;
		i++;
	}
	ft_printf("CHECK LIST RETURN 1\n");
	return (1);
}

int main(int ac, char *av[])
{
	if (ac > 1)
	{
		t_que	*a;
		t_que	*b;
		t_ops	*my_ops;

		a = parse_input(ac, av);
			if (!a)
				return (1);
		b = create_list();
			if (!b)
				free_each_node_exit(&a);
		my_ops = rg_ops(&a, &b);
		if (apply_ops(a, b, my_ops) && check_list(a) && b->size == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_each_node(&a);
		free_ops(&my_ops);
		free_each_node_exit(&b);
	}
	return (0);
}
