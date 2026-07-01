// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: yichua <yichua@student.42singapore.sg>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/06/06 12:25:23 by jmerckx           #+#    #+#             */
// /*   Updated: 2026/06/06 19:20:43 by yichua           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <unistd.h>
// #include "str_util.h"

// char	try_get_values(char *str, int *values_buffer)
// {
// 	unsigned int	i;
// 	unsigned int	digits;

// 	i = 0;
// 	digits = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (i % 2 == 0)
// 		{
// 			if (str[i] < '1' || str[i] > '4')
// 				return (0);
// 			values_buffer[i / 2] = str[i] - '0';
// 			digits++;
// 		}
// 		else if (str[i] != ' ')
// 		{
// 			return (0);
// 		}
// 		i++;
// 	}
// 	if (digits == 16)
// 		return (1);
// 	else
// 		return (0);
// }

// void	print_invalid_params_error(void)
// {
// 	print("Parameters are not valid:\n");
// 	print("Please provide 1 string argument.\n");
// 	print("It should specify 16 integers ranging from 1 to 4.\n");
// 	print("They should be seperated by spaces.\n");
// }

// void	test_print_values(int *values)
// {
// 	unsigned int	i;
// 	char			c;

// 	i = 0;
// 	while (i < 16)
// 	{
// 		c = values[i] + '0';
// 		write(1, &c, 1);
// 		if (i < 15)
// 			print(", ");
// 		else
// 			print("\n");
// 		i++;
// 	}
// }

// void	popgmatrix(int *values, int gridmatrix[4][4])
// {
// 	int	i;
// 	int	k;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		k = 0;
// 		while (k < 4)
// 		{
// 			gridmatrix[i][k] = values[(i * 4) + k];
// 			k++;
// 		}
// 		i++;
// 	}
// }

// void	minmax(int gridmatrix[4][4], int writtenmatrix[4][4])
// {
// 	int	i;
// 	int	k;
// 	int	wr;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		k = 0;
// 		while (k < 4)
// 		{
// 			if (gridmatrix[i][k] == 4)
// 			{
// 				wr = 0;
// 				while (wr < 4)
// 				{
// 					if (i == 0)
// 						writtenmatrix[wr][0] = wr+1;
// 					else if(i == 2)
// 						writtenmatrix[0][wr] = wr+1;
// 					wr++;
// 				}
// 				break;
// 			}
// 			print_matrix(writtenmatrix, 4, 4);
// 			print_char('\n');
// 			k++;
// 		}
// 		i++;
// 	}
// }

// void	guesser(int gridmatrix[4][4], int writtenmatrix[4][4])
// {
// 	int	i;
// 	int	k;
// 	int rowCheck[4] = {0};

// 	i = 0;
// 	while (i < 4)
// 	{
// 		k = 0;
// 		while (k < 4)
// 		{
// 			if (writtenmatrix[i][k] == 0)
// 			{
// 				c = 0;
// 				while (c < 4)
// 				{
// 					rowCheck[c] = writtenmatrix[i][c];
// 					c++
// 				}
// 			}
// 		}
// 	}
// }



// int	main(int argc, char **argv)
// {
// 	int	values[16];
// 	int gridmatrix[4][4] = {0};
// 	int writtenmatrix[4][4] = {0};

// 	if (argc != 2)
// 	{
// 		print_invalid_params_error();
// 		return (1);
// 	}
// 	if (try_get_values(argv[1], values) == 0)
// 	{
// 		print_invalid_params_error();
// 		return (1);
// 	}
// 	popgmatrix(values, gridmatrix);
// 	minmax(gridmatrix, writtenmatrix);
// 	print("Grid Matrix\n");
// 	print_matrix(gridmatrix, 4, 4);
// 	print("\nWritten Matrix\n");
// 	print_matrix(writtenmatrix, 4, 4);
// 	return (0);
// }
