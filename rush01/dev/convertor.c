/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 17:20:28 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/07 17:22:43 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	convert_2d_to_1d(int array1d[16], int array2d[4][4])
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (i < 16)
	{
		array1d[i] = array2d[x][y];
		x++;
		if (x == 4)
		{
			x = 0;
			y++;
		}
		i++;
	}
}

void	convert_1d_to_2d(int array1d[16], int array2d[4][4])
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (i < 16)
	{
		array2d[x][y] = array1d[i];
		x++;
		if (x == 4)
		{
			x = 0;
			y++;
		}
		i++;
	}
}
