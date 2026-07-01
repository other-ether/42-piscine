/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 23:23:24 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/08 16:22:20 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	p;
	int	i;

	p = 1;
	i = 0;
	if (argc == 1)
		return (0);
	while (p < argc)
	{
		while (argv[p][i] != 0)
		{
			write(1, &(argv[p][i]), 1);
			i++;
		}
		write(1, "\n", 1);
		p ++;
		i = 0;
	}
	return (0);
}
