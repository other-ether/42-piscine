/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichua <yichua@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 12:25:23 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 18:03:29 by yichua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *str);

void	print_invalid_params_error(void)
{
	print("Parameters are not valid:\n");
	print("Please provide 1 string argument.\n");
	print("It should specify 16 integers ranging from 1 to 4.\n");
	print("They should be seperated by spaces.\n");
}

void	test_print_values(int *values)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < 16)
	{
		c = values[i] + '0';
		write(1, &c, 1);
		if (i < 15)
			print(", ");
		else
			print("\n");
		i++;
	}
}
