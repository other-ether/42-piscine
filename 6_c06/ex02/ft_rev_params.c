/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:21:01 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/08 16:25:24 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		return (0);
	argc = argc - 1;
	while (argc > 0)
	{
		while (argv[argc][i] != 0)
		{
			write(1, &(argv[argc][i]), 1);
			i++;
		}
		write(1, "\n", 1);
		argc --;
		i = 0;
	}
	return (0);
}
