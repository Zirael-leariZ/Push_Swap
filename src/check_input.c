/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:48:52 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/15 14:24:52 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	is_in_que(t_que *arr, int cur_val)
{
	int		i;
	t_que	*cpy;

	i = 0;
	cpy = arr;
	while (i < arr->size)
	{
		if (cpy->head->val == cur_val)
			return (1);
		i++;
		cpy->head = cpy->head->next;
	}
	return (0);
}

void	atoi_to_que(char *str, t_que **arr_a)
{
	int			sign;
	long long	res;

	sign = 1;
	while (*str)
	{
		res = 0;
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
		if (!is_in_que(*arr_a, res))
		{
			if (!append_value_bottom(arr_a, (res * sign)))
				free_each_node_exit(arr_a);
		}
		else
			free_each_node_exit(arr_a);
	}
}

char	*no_space_str(char *src, char *dest, int *cur_pos)
{
	int	i;

	i = *cur_pos;
	dest = NULL;
	while (src[i])
	{
		while(src[i] && ft_isspace(src[i]))
			i++;
		*cur_pos = i;
		if ((src[i] == '+' || src[i] == '-') && ft_isdigit(src[i + 1]))
			i++;
		if (src[i] && !ft_isdigit(src[i]))
			return (NULL);
		while (src[i] && ft_isdigit(src[i]))
			i++;
		if (src[i] && !ft_isspace(src[i]) )
			return (NULL);
		if (i > *cur_pos)
			dest = ft_substr(src, *cur_pos, i - *cur_pos);
		while(src[i] && ft_isspace(src[i]))
			i++;
		*cur_pos = i;
		return (dest);
	}
	return (NULL);
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
	while (av[i] && ac > 1) // make sure that one digit is legit
	{
		input = no_space_str(av[i], input, &cur_pos);
		if (!input && av[i][cur_pos])
			return (free_each_node_exit(&arr_a), NULL);
		else if (input)
			atoi_to_que(input, &arr_a);
		free(input);
		if (!av[i][cur_pos])
		{
			i++;
			cur_pos = 0;
		}
	}
	return (arr_a);
}


