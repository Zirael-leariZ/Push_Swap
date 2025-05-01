/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:48:52 by oishchen          #+#    #+#             */
/*   Updated: 2025/04/29 12:32:05 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_exit(int status)
{
	if (status == 1)
		ft_printf("ERROR\n");
	exit(1);
}

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	print_circular_arr(t_que *arr, char *arr_type)
{
	t_que	*temp = arr;
	int		i;

	i = 0;
	if (arr->head)
	{
		ft_printf("%s, head: %d\n", arr_type, arr->head->val);
		ft_printf("%s, size: %d\n", arr_type, arr->size);
	}
	while (i < arr->size)
	{
		ft_printf("%s Our data: %d\n", arr_type, temp->head->val);
		temp->head = temp->head->next;
		i++;
	}
}

void	purify_input(char *str, t_que *arr_a)
{
	int			sign;
	long long	res;

	sign = 0;
	while (*str)
	{
		res = 0;
		while (*str && *str == ' ')
			str++;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sign = -1;
			str++;
		}
		while (ft_isdigit(*str))
		{
			res = res * 10 + (*str - '0');
			str++;
		}
		if ((*str && ft_isspace(*str)) || !*str)
			append_value_bottom(arr_a, (int)res);
		else
			free_each_node_exit(&arr_a);
	}
}

t_que	*parse_input(int ac, char *av[])
{
	int		i;
	t_que	*arr_a;

	arr_a = NULL;
	if (ac > 1)
	{
		i = 1;
		arr_a = create_list();
		while (av[i])
			purify_input(av[i++], arr_a);
		// print_circular_arr(arr_a);
	}
	return (arr_a);
}

int main(int ac, char *av[])
{
	if (ac > 1)
	{
		t_que	*res;
		t_que	*res_b;
		res = parse_input(ac, av);
		res_b = create_list();
		print_circular_arr(res, "arr_a");
		ra(res);
		ra(res);
		ra(res);

		print_circular_arr(res, "arr_a");
		rra(res);
		print_circular_arr(res, "arr_a");
		free_each_node_exit(&res);
		free_each_node_exit(&res_b);
	}
	return (0);
}