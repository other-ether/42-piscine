/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerckx <jmerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 12:25:23 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 17:37:32 by jmerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print(char *str);
void	print_char(char c);
void	print_solution(int solution[4][4]);
char	try_min_max_solve(int values[], int solution[4][4]);
char	try_solve(int values[], int solution[4][4], int index);
char	is_valid(int values[16], int solution[4][4]);
void	convert_2d_to_1d(int array1d[16], int array2d[4][4]);
void	convert_1d_to_2d(int array1d[16], int array2d[4][4]);

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

void	populate_with_zeroes(int solution[4][4])
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (i < 16)
	{
		solution[x][y] = 0;
		x++;
		if (x == 4)
		{
			x = 0;
			y++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	values[16];
	int	solution[4][4];

	if (argc != 2 || try_get_values(argv[1], values) == 0)
	{
		print_invalid_params_error();
		return (0);
	}
	populate_with_zeroes(solution);
	if (try_min_max_solve(values, solution) == 0)
	{
		print_no_solution_error();
		return (0);
	}
	if (try_solve(values, solution, 0) == 0)
	{
		print_no_solution_error();
		return (0);
	}
	print_solution(solution);
	return (0);
}
