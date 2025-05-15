/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 08:42:40 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/16 00:34:26 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av[])
{
	if (ac > 1)
	{
		t_que	*a;
		t_que	*b;
		int		*arr_int;

		(void)arr_int;
		a = parse_input(ac, av);
			if (!a)
				return (write(2, "ERROR\n", 6));
		b = create_list();
			if (!b)
				free_each_node_exit(&a);
		arr_int = ft_sort(&a);
		free(arr_int);
		if (!is_fully_sorted(a))
		{
			chunck_sort(a, b);
			back_sort(a, b);
			is_fully_sorted(a);
		}
		free_each_node(&a);
		free_each_node_exit(&b);
	}
	return (0);
}
