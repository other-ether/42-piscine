/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 01:11:28 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/08 15:57:21 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	white_space(char **str)
{
	while ((**str >= 9 && **str <= 13) || (**str == 32))
	{
		if (**str == '\0')
			break ;
		(*str)++;
	}
}

int	negatize(char *str)
{
	int	count;

	count = 0;
	while (*str == 43 || *str == 45)
	{
		if (*str == 45)
			count ++;
		str ++;
	}
	if (count % 2 == 0)
		return (1);
	else
		return (-1);
}

int	digitalize(char char_dig)
{
	int	dig;

	dig = char_dig - '0';
	return (dig);
}

int	convert_to_int(char**str)
{
	int	output;

	output = 0;
	while (**str >= 48 && **str <= 57)
	{
		output = output * 10;
		output = output + digitalize(**str);
		(*str)++;
	}
	return (output);
}

int	ft_atoi(char *str)
{
	int	end_result;

	end_result = 0;
	white_space(&str);
	end_result = (negatize(str));
	while (*str == 43 || *str == 45)
	{
		if (*str == '\0')
			break ;
		str++;
	}
	end_result = end_result * convert_to_int(&str);
	return (end_result);
}
