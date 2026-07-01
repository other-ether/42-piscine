/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:07:09 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/14 22:27:49 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putstr(char *str)
{
	while (*str != '\n' && *str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((s1[i] - s2[i]));
	}
	return ((s1[i] - s2[i]));
}

int	matchkey(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (i == n)
		return (0);
	return (1);
}

char	*ft_strstr(char *haystack, char *to_find)
{
	int	len;
	int	i;

	len = ft_strlen(to_find);
	i = len;
	if (*to_find == '\0')
		return (haystack);
	while (*haystack != '\0')
	{
		if (matchkey(haystack, to_find, len) == 0)
		{
			while (haystack[i] == ' ')
				i++;
			if (haystack[i] != ':')
				return (0);
			return (haystack + len);
		}
		haystack ++;
	}
	return (0);
}
