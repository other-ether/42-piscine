/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brutest_force.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerckx <jmerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:42:23 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 17:37:17 by jmerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print(char *str);
void	print_char(char c);
void	print_solution(int solution[4][4]);
char	is_valid(int values[16], int solution[4][4]);

char	try_solve(int values[], int solution[4][4], int index)
{
	int	row;
	int	col;
	int	digit;

	if (index == 16)
		return (is_valid(values, solution));
	row = index / 4;
	col = index % 4;
	if (solution[row][col] != 0)
		return (try_solve(values, solution, index + 1));
	digit = 1;
	while (digit <= 4)
	{
		solution[row][col] = digit;
		if (try_solve(values, solution, index + 1))
			return (1);
		digit++;
	}
	solution[row][col] = 0;
	return (0);
}
