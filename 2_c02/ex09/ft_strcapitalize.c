/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:07:07 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/05 14:01:47 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char *cha)
{
	if ((*cha >= 48 && *cha <= 57)
		|| (*cha >= 65 && *cha <= 90)
		|| (*cha >= 97 && *cha <= 122))
	{
		return (1);
	}
	return (0);
}

char	capitalize(char *cha)
{
	if (*cha >= 97 && *cha <= 122)
		*cha -= 32;
	return (*cha);
}

char	lowcase(char *cha)
{
	if (*cha >= 65 && *cha <= 90)
		*cha += 32;
	return (*cha);
}

char	*ft_strcapitalize(char *str)
{
	char	*orig;

	orig = str;
	while (*str != 0)
	{
		while ((*str != 0) && (is_alphanumeric(str) == 0))
			str++;
		capitalize(str);
		str++;
		while ((*str != 0) && (is_alphanumeric(str) == 1))
		{
			lowcase(str);
			str++;
		}
	}
	return (orig);
}
