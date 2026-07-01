/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 12:25:23 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 16:29:39 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "write_util.h"
#include "min_max_solve.h"
#include "brutest_force.h"
#include "validator.h"
#include "convertor.h"

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
}

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

// solution[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
int	main(int argc, char **argv)
{
	int			values[16];
	int			reconvert[4][4];
	int			result;
	int			converted[16];
	static int	solution[4][4];

	result = population(0, converted, values);
	if (argc != 2)
	{
		print_invalid_params_error();
		return (1);
	}
	if (try_get_values(argv[1], values) == 0)
	{
		print_invalid_params_error();
		return (1);
	}
	if (try_min_max_solve(values, solution) == 0)
	{
		print_no_solution_error();
		return (1);
	}
	convert_2d_to_1d(converted, solution);
	if (result == 0)
	{
		print_no_solution_error();
		return (0);
	}
	convert_1d_to_2d(converted, reconvert);
	print_solution(reconvert);
	return (0);
}
