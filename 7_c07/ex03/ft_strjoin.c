/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 00:02:06 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/18 01:11:26 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strcat(char *dest, char *src)
{
	char	*orig;

	orig = dest;
	while (*dest != 0)
		dest++;
	while (*src != 0)
	{
		*dest = *src;
		dest ++;
		src ++;
	}
	*dest = '\0';
	return (orig);
}

char	*allocate_buffer(int size, int superlen, char *sep)
{
	char	*str;
	int		total_len;

	if (size == 0)
		total_len = 1;
	else
		total_len = superlen + 1 + (size - 1) * ft_strlen(sep);
	str = malloc(total_len * sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		superlen;
	int		i;

	superlen = 0;
	i = 0;
	while (size > i)
		superlen += ft_strlen(strs[i++]);
	result = allocate_buffer(size, superlen, sep);
	if (result == NULL)
		return (NULL);
	if (size > 0)
	{
		i = 0;
		while (size > i)
		{
			ft_strcat(result, strs[i]);
			if (size > i + 1)
				ft_strcat(result, sep);
			i++;
		}
	}
	return (result);
}
