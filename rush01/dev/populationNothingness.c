/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populationNothingness.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:44:31 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/07 16:44:02 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"
#include "convertor.h"
#include "write_util.h"
#include <unistd.h>
#include "see_validator.h"
#include "unique_validator.h"

char	checklegal(int *layout, int *params, int spot)
{
	int	converted[4][4];
	convert_1d_to_2d(layout, converted);

	if (is_valid_unique(converted) == 0)
        return 0;

	if (spot == 16)
		return is_valid_see(params, converted);

	return 1;
}

int	population(int spot, int*layout, int*params)
{
	int	guess;

	guess = 0;
	if (spot == 16) 
	{	
		return 1;
	}
	if (layout[spot] != 0)
		return (population(spot + 1, layout, params));
	while (guess < 4)
	{
		guess ++;
		layout[spot] = guess;
		if (checklegal(layout, params, spot) == 1)
		{
			if (population(spot + 1, layout, params) == 1)
				return 1;
		}
		layout[spot] = 0;
	}
	return (0) ;
}
