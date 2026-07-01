/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:37:32 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/18 12:46:48 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*newstr;
	int		len;

	len = ft_strlen(src);
	newstr = malloc((len + 1) * sizeof(char));
	if (newstr == 0)
		return (0);
	ft_strcpy(newstr, src);
	return (newstr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*super;

	i = 0;
	super = malloc((ac + 1) * sizeof(t_stock_str));
	if (super == NULL)
		return (NULL);
	while (ac > i)
	{
		super[i].size = ft_strlen(av[i]);
		super[i].str = av[i];
		super[i].copy = ft_strdup(av[i]);
		if (super[i].copy == NULL)
		{
			while (--i >= 0)
				free(super[i].copy);
			free(super);
			return (NULL);
		}
		i ++;
	}
	super[i].size = 0;
	super[i].str = 0;
	super[i].copy = 0;
	return (super);
}
