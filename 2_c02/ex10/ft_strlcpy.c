/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 02:13:14 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/05 14:02:37 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*orig;

	orig = src;
	if (size == 0)
		return (ft_strlen(orig));
	while (*src != 0 && size - 1 > 0)
	{
		*dest = *src;
		dest ++;
		src ++;
		size --;
	}
	*dest = '\0';
	return (ft_strlen(orig));
}
