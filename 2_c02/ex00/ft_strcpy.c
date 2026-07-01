/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 19:52:48 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/04 12:29:03 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*orig;

	orig = dest;
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (orig);
}
