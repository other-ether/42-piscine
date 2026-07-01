/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:24:35 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/13 21:57:23 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n > 0 && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
		{
			i++;
			n--;
		}
		else
			return (-1);
	}
	if (n == 0)
		return (10);
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *haystack, char *to_find)
{
	int		len;

	len = ft_strlen(to_find);
	if (*to_find == '\0')
		return (haystack);
	while (*haystack != '\0')
	{
		if (ft_strncmp(haystack, to_find, len) == 10)
		{
			return (haystack);
		}
		haystack ++;
	}
	return (0);
}
