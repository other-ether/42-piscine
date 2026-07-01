/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerckx <jmerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:46:48 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 16:43:37 by jmerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	is_valid_see_top(int values[], int solution[4][4])
{
	int	i;
	int	j;
	int	seen;
	int	highest;

	i = 0;
	while (i < 4)
	{
		j = 0;
		seen = 0;
		highest = 0;
		while (j < 4)
		{
			if (solution[i][j] > highest)
			{
				seen++;
				highest = solution[i][j];
			}
			j++;
		}
		if (seen != values[i])
			return (0);
		i++;
	}
	return (1);
}

char	is_valid_see_bot(int values[], int solution[4][4])
{
	int	i;
	int	j;
	int	seen;
	int	highest;

	i = 4;
	while (i < 8)
	{
		j = 3;
		seen = 0;
		highest = 0;
		while (j >= 0)
		{
			if (solution[i - 4][j] > highest)
			{
				seen++;
				highest = solution[i - 4][j];
			}
			j--;
		}
		if (seen != values[i])
			return (0);
		i++;
	}
	return (1);
}

char	is_valid_see_left(int values[], int solution[4][4])
{
	int	i;
	int	j;
	int	seen;
	int	highest;

	i = 8;
	while (i < 12)
	{
		j = 0;
		seen = 0;
		highest = 0;
		while (j < 4)
		{
			if (solution[j][i - 8] > highest)
			{
				seen++;
				highest = solution[j][i - 8];
			}
			j++;
		}
		if (seen != values[i])
			return (0);
		i++;
	}
	return (1);
}

char	is_valid_see_right(int values[], int solution[4][4])
{
	int	i;
	int	j;
	int	seen;
	int	highest;

	i = 12;
	while (i < 16)
	{
		j = 3;
		seen = 0;
		highest = 0;
		while (j >= 0)
		{
			if (solution[j][i - 12] > highest)
			{
				seen++;
				highest = solution[j][i - 12];
			}
			j--;
		}
		if (seen != values[i])
			return (0);
		i++;
	}
	return (1);
}

char	is_valid_see(int values[], int solution[4][4])
{
	if (is_valid_see_top(values, solution) == 0)
		return (0);
	if (is_valid_see_bot(values, solution) == 0)
		return (0);
	if (is_valid_see_left(values, solution) == 0)
		return (0);
	if (is_valid_see_right(values, solution) == 0)
		return (0);
	return (1);
}
