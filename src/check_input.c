/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:48:52 by oishchen          #+#    #+#             */
/*   Updated: 2025/05/19 14:27:58 by oishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int	is_allowed_val(long long res)
{
	if (res <= -2147483648 || res > 2147483647)
		return (write(2, "PEERR\n", 6), 0);
	return (1);
}

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
			return (write(2, "Error\n", 6), 1);
		i++;
		cpy->head = cpy->head->next;
	}
	return (0);
}

int	atoi_to_que(char *str, t_que **arr_a, int sign)
{
	long long	res;

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
		if (!is_in_que(*arr_a, res * sign) && is_allowed_val(res)
			&& append_value_bottom(arr_a, (res * sign)))
			return (1);
		else
			return (0);
	}
	return (0);
}

char	*no_space_str(char *src, char *dest, int *cur_pos)
{
	int	i;

	i = *cur_pos;
	dest = NULL;
	while (src[i])
	{
		while (src[i] && ft_isspace(src[i]))
			i++;
		*cur_pos = i;
		if ((src[i] == '+' || src[i] == '-') && ft_isdigit(src[i + 1]))
			i++;
		if (src[i] && !ft_isdigit(src[i]))
			return (write(2, "Error\n", 6), NULL);
		while (src[i] && ft_isdigit(src[i]))
			i++;
		if (src[i] && !ft_isspace(src[i]))
			return (write(2, "Error\n", 6), NULL);
		if (i > *cur_pos)
			dest = ft_substr(src, *cur_pos, i - *cur_pos);
		while (src[i] && ft_isspace(src[i]))
			i++;
		*cur_pos = i;
		return (dest);
	}
	return (write(2, "Error\n", 6), NULL);
}
