/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 08:42:40 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/15 13:22:58 by oishchen         ###   ########.fr       */
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
		// int		chuncks;
		(void)arr_int;
		a = parse_input(ac, av);
			if (!a)
				return (1);
		b = create_list();
			if (!b)
				free_each_node_exit(&a);
		arr_int = ft_sort(&a);
		free(arr_int);
		// print_circular_arr(a, "a after parse");
		// print_circular_arr(b, "b after parse");
		// chuncks = derive_chuncks(a->size);
		if (!is_fully_sorted(a))
		{
			// pivot_sort(a, b);

		// print_circular_arr(a, "a after pivot");
		// print_circular_arr(b, "b after pivot");

			chunck_sort(a, b);

		// print_circular_arr(a, "a after chunck");
		// print_circular_arr(b, "b after chunck");

			back_sort(a, b);
		
		// print_circular_arr(b, "b after back_sort");
		}
		// print_circular_arr(a, "a after back_sort");
		
		free_each_node(&a);
		free_each_node_exit(&b);
	}
	return (0);
}