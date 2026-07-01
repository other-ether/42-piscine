/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_solve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerckx <jmerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:04:53 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 16:51:15 by jmerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	try_min_max_top(int values[], int solution[4][4])
{
	int	i;
	int	digit;

	i = 0;
	while (i < 4)
	{
		if (values[i] == 1 && solution[i][0] == 0)
			solution[i][0] = 4;
		else if (values[i] == 1 && solution[i][0] != 4)
			return (0);
		else if (values[i] == 4)
		{
			digit = 1;
			while (digit <= 4)
			{
				if (solution[i][digit - 1] == 0)
					solution[i][digit - 1] = digit;
				else if (solution[i][digit - 1] != digit)
					return (0);
				digit++;
			}
		}
		i++;
	}
	return (1);
}

char	try_min_max_bot(int values[], int solution[4][4])
{
	int	i;
	int	digit;

	i = 4;
	while (i < 8)
	{
		if (values[i] == 1 && solution[i - 4][3] == 0)
			solution[i - 4][3] = 4;
		else if (values[i] == 1 && solution[i - 4][3] != 4)
			return (0);
		else if (values[i] == 4)
		{
			digit = 1;
			while (digit <= 4)
			{
				if (solution[i - 4][4 - digit] == 0)
					solution[i - 4][4 - digit] = digit;
				else if (solution[i - 4][4 - digit] != digit)
					return (0);
				digit++;
			}
		}
		i++;
	}
	return (1);
}

char	try_min_max_left(int values[], int solution[4][4])
{
	int	i;
	int	digit;

	i = 8;
	while (i < 12)
	{
		if (values[i] == 1 && solution[0][i - 8] == 0)
			solution[0][i - 8] = 4;
		else if (values[i] == 1 && solution[0][i - 8] != 4)
			return (0);
		else if (values[i] == 4)
		{
			digit = 1;
			while (digit <= 4)
			{
				if (solution[digit - 1][i - 8] == 0)
					solution[digit - 1][i - 8] = digit;
				else if (solution[digit - 1][i - 8] != digit)
					return (0);
				digit++;
			}
		}
		i++;
	}
	return (1);
}

char	try_min_max_right(int values[], int solution[4][4])
{
	int	i;
	int	digit;

	i = 12;
	while (i < 16)
	{
		if (values[i] == 1 && solution[3][i - 12] == 0)
			solution[3][i - 12] = 4;
		else if (values[i] == 1 && solution[3][i - 12] != 4)
			return (0);
		else if (values[i] == 4)
		{
			digit = 1;
			while (digit <= 4)
			{
				if (solution[4 - digit][i - 12] == 0)
					solution[4 - digit][i - 12] = digit;
				else if (solution[4 - digit][i - 12] != digit)
					return (0);
				digit++;
			}
		}
		i++;
	}
	return (1);
}

char	try_min_max_solve(int values[], int solution[4][4])
{
	if (try_min_max_top(values, solution) == 0)
		return (0);
	if (try_min_max_bot(values, solution) == 0)
		return (0);
	if (try_min_max_left(values, solution) == 0)
		return (0);
	if (try_min_max_right(values, solution) == 0)
		return (0);
	return (1);
}
