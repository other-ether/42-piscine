/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerckx <jmerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:17:45 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 16:44:03 by jmerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	is_buffer_unique(int buffer[4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (buffer[i] == buffer[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	is_valid_unique_row(int solution[4][4])
{
	int	buffer[4];
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
		buffer[3] = 0;
		while (x < 4)
		{
			buffer[x] = solution[x][y];
			x++;
		}
		if (is_buffer_unique(buffer) == 0)
			return (0);
		y++;
	}
	return (1);
}

char	is_valid_unique_column(int solution[4][4])
{
	int	buffer[4];
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
		buffer[3] = 0;
		while (y < 4)
		{
			buffer[y] = solution[x][y];
			y++;
		}
		if (is_buffer_unique(buffer) == 0)
			return (0);
		x++;
	}
	return (1);
}

char	is_valid_unique(int solution[4][4])
{
	if (is_valid_unique_row(solution) == 0)
		return (0);
	if (is_valid_unique_column(solution) == 0)
		return (0);
	return (1);
}
