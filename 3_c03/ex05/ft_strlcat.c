/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:24:35 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/11 12:24:36 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	slen;
	unsigned int	dlen;
	unsigned int	copied;

	slen = ft_strlen(src);
	dlen = 0;
	copied = 0;
	while (dlen < size && dest[dlen] != 0)
		dlen++;
	if (dlen == size)
		return (size + slen);
	dest += dlen;
	while (copied + dlen + 1 < size && *src != 0)
	{
		*dest = *src;
		dest ++;
		src ++;
		copied ++;
	}
	*dest = '\0';
	return (dlen + slen);
}
