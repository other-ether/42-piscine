/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:45:36 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/11 16:54:24 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	compare(char*s1, char*s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((s2[i] - s1[i]));
	}
	return ((s2[i] - s1[i]));
}

void	printer(char**str, int size)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (size > i)
	{
		while (str[i][j])
		{
			write(1, &(str[i][j]), 1);
			j ++;
		}
		i ++;
		j = 0;
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int		j;
	char	*buffer;
	int		status;

	status = 1;
	if (argc <= 1)
		return (0);
	while (status == 1)
	{
		j = 1;
		status = 0;
		while (argc - 1 > j)
		{
			if (compare(argv[j], argv[j + 1]) < 0)
			{
				buffer = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = buffer;
				status = 1;
			}
			j ++;
		}
	}
	printer(argv, argc);
	return (0);
}
