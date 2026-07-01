/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:14:36 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/10 23:27:44 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*orig;

	orig = dest;
	if (nb == 0)
		return (orig);
	while (*dest != 0)
		dest++;
	while (nb > 0 && *src != 0)
	{
		*dest = *src;
		dest ++;
		src ++;
		nb --;
	}
	*dest = '\0';
	return (orig);
}
