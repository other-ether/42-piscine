/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 22:37:57 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/09 14:28:32 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

I NEED A FUNCTION TO CONVERT BASE TOO

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != 0)
	{
		i++;
		str++;
	}
	return (i);
}

void	white_space(char **str) // collapse this and some other functions
{
	while ((**str >= 9 && **str <= 13) || (**str == 32))
	{
		if (**str == '\0')
			break ;
		(*str)++;
	}
}

int	convert_to_int(char**str) // collapsed already
{
	int	dig;
	int	output;

	dig = **str - '0';
	output = 0;
	while (**str >= 48 && **str <= 57)
	{
		output = output * 10;
		output = output + dig;
		(*str)++;
	}
	return (output);
}

int	ft_atoi(char *str)
{
	int	end_result;
	int	count;

	end_result = 1;
	count = 0;
	white_space(&str);
	while (*str == 43 || *str == 45)
	{
		if (*str == 45)
			count ++;
		str ++;
	}
	if (count % 2 == 0)
		end_result = -1;
	while (*str == 43 || *str == 45)
	{
		if (*str == '\0')
			break ;
		str++;
	}
	end_result = end_result * convert_to_int(&str);
	return (end_result);
}

int ft_atoibase(char *str, char *base)
{
	int radix;
	int i;
	int result;

	radix = ft_strlen(base); 
	i = 1;
	result = strstr ;
	while (i < radix)
	{

	}
	
	then after converting just plug in the result to ft_atoi
}
