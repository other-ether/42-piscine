// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   sudokumain.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: yichua <yichua@student.42singapore.sg>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/06/06 12:25:23 by jmerckx           #+#    #+#             */
// /*   Updated: 2026/06/06 17:39:16 by yichua           ###   ########.fr       */
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
// void	testGridformula(int *values)
// {
// 	unsigned int	i;
// 	unsigned int	k;
// 	unsigned int	colTOffset;
// 	unsigned int	colBOffset;
// 	unsigned int	rowLOffset;
// 	unsigned int	rowROffset;
// 	unsigned int	nCols;
// 	unsigned int	nRows;

// 	nCols = 4;
// 	nRows = 4;
// 	colTOffset = 0;
// 	colBOffset = nCols;
// 	rowLOffset = nCols  * 2;
// 	rowROffset = rowLOffset + nRows;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		k = 0;
// 		while (k < 4)
// 		{
// 			print("Position ");
// 			print_char(((i * nCols) + k) + '0');
// 			print(": ");
// 			print_char((char)values[colTOffset + i] + '0');
// 			print(" ");
// 			print_char((char)values[colBOffset + i] + '0');
// 			print(" ");
// 			print_char((char)values[rowLOffset + k] + '0');
// 			print(" ");
// 			print_char((char)values[rowROffset + k] + '0');
// 			k++;
// 			print("\n");
// 		}
// 		print("\n");
// 		i++;
// 	}
// }

// void	colrowmatrix(int *values, int rows, int cols, int maxVal)
// {
// 	int crmatrix[rows][cols][maxVal];
// 	int i;
// 	int k;

// 	i = 0;
// 	while (i < rows)
// 	{
// 		k = 0;
// 		while (k < cols)
// 		{
// 			crmatrix[rows][cols][(i * rows) + k] = values[(i * rows) + k];
// 			k++;
// 		}
// 		i++;
// 	}
// }

// void	formula(int *values)
// {
// 	unsigned int	i;
// 	unsigned int	k;

// 	int	possibilities[nRows][nCols][maxVal];

// 	i = 0;
// 	while (i < 4)
// 	{
// 		k = 0;
// 		while (k < 4)
// 		{

// 		}
// 		print("\n");
// 		i++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	unsigned int	nCols;
// 	unsigned int	nRows;
// 	unsigned int	maxVal;

// 	nCols = 4;
// 	nRows = 4;
// 	maxVal = 4;

// 	int	values[nCols*nRows];

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
// 	formula(values);
// 	return (0);
// }
