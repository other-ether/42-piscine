/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:27:32 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/10 23:27:38 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
