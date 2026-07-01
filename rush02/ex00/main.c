/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 16:14:10 by kitang            #+#    #+#             */
/*   Updated: 2026/06/14 18:58:22 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "strings.h"

void	parser(char *input, char *dictname);

int	diccheck(char *file)
{
	int	l;

	l = ft_strlen (file);
	if (l < 6 || file[l -5] != '.' || file[l -4] != 'd' || file[l -3] != 'i'
		|| file[l -2] != 'c' || file[l -1] != 't')
	{
		ft_putstr("You did not enter a valid reference dictionary.\n");
		return (-1);
	}
	return (0);
}

int	numcheck(char *num)
{
	int	i;

	i = 0;
	while (num[i] != '\0')
	{
		if (num[i] < '0' || num[i] > '9')
		{
			ft_putstr("Error\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	compliance(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 3 || argc < 2)
	{
		ft_putstr("Please enter exactly 1 or 2 arguments.\n");
		return (-1);
	}
	if (argc == 2)
	{
		if (numcheck(argv[1]) == -1)
			return (-1);
	}
	if (argc == 3)
	{
		if (numcheck(argv[2]) == -1)
			return (-1);
		if (diccheck(argv[1]) == -1)
			return (-1);
	}
	return (0);
}

char	*skip_zero(char *nbr)
{
	if (*nbr == '0')
	{
		while (*nbr == '0' && *(nbr +1) != '\0')
			nbr++;
	}
	return (nbr);
}

int	main(int argc, char **argv)
{
	char	*nbr;
	char	*dict;

	dict = "numbers.dict";
	if (compliance(argc, argv) == -1)
		return (1);
	if (argc == 2)
		nbr = argv[1];
	if (argc == 3)
	{
		nbr = argv[2];
		dict = argv[1];
	}
	nbr = skip_zero(nbr);
	parser(nbr, dict);
	ft_putstr("");
	return (0);
}
