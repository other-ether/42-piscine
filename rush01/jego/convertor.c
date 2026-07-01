/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerckx <jmerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:40:07 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 16:41:30 by jmerckx          ###   ########.fr       */
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
