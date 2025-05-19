/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 08:42:40 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 16:05:18 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int ac, char *av[])
{
	t_que	*a;
	t_que	*b;
	int		*arr_int;

	arr_int = NULL;
	if (ac > 1)
	{
		a = parse_input(ac, av);
		if (!a)
			return (write(2, "Error\n", 6), 1);
		b = create_list();
		if (!b)
			free_each_node_exit(&a, 1);
		arr_int = ft_sort(&a, arr_int);
		free(arr_int);
		while (!is_fully_sorted(a) && arr_int)
		{
			five_sort(a, b);
			chunck_sort(a, b);
			back_sort(a, b);
		}
		free_each_node(&a);
		free_each_node_exit(&b, 0);
	}
	return (0);
}
