/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainNothingness.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 12:25:23 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 16:41:31 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "write_util.h"
#include "min_max_solve.h"
#include "brutest_force.h"
#include "validator.h"
#include "convertor.h"
#include <stdio.h> // omit later
#include <string.h> // omit later

char	try_get_values(char *str, int *values_buffer)
{
	unsigned int	i;
	unsigned int	digits;

	i = 0;
	digits = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
			values_buffer[i / 2] = str[i] - '0';
			digits++;
		}
		else if (str[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	if (digits == 16)
		return (1);
	else
		return (0);
}	// if (argc != 2)
	// {
	// 	print_invalid_params_error();
	// 	return (1);
	// }
	// if (try_get_values(argv[1], values) == 0)
	// {
	// 	print_invalid_params_error();
	// 	return (1);
	// }

void	print_invalid_params_error(void)
{
	print("Parameters are not valid:\n");
	print("Please provide 1 string argument.\n");
	print("It should specify 16 integers ranging from 1 to 4.\n");
	print("They should be seperated by spaces.\n");
}

void	print_no_solution_error(void)
{
	print("There is no valid solution.\n");
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

int	population(int spot, int*layout, int*params);

int	main(int argc, char **argv)
{
	int	values[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};


	// int solution[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

	// if (argc != 2)
	// {
	// 	print_invalid_params_error();
	// 	return (1);
	// }
	// if (try_get_values(argv[1], values) == 0)
	// {
	// 	print_invalid_params_error();
	// 	return (1);
	// }
	// if (try_min_max_solve(values, solution) == 0)
	// {
	// 	print_no_solution_error();
	// 	return (1);
	// }
	
	/* Guosh time */
	int result;
	int nothingness[16] = {0}; // testing from an empty array
	result = population(0, nothingness, values);
  	int length = sizeof(values) / sizeof(values[0]); 
	for (int i = 0; i < length; i++)
		printf("%d ", nothingness[i]);
    printf("\n");
	// if (result == 0)
	// {
	// 	print_no_solution_error();
	// 	return (0);
	// }
	/*good, now try population*/
	// print("HALLELUJAH ITS A MIRACLE\n");

	// int reconvert[4][4];
	// convert_1d_to_2d(converted, reconvert);
	// print_solution(reconvert);
	
	return (0);
}
