/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   population.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:44:31 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/07 15:56:44 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"
#include "convertor.h"
#include "write_util.h"
#include <unistd.h>
#include <stdio.h> // omit later

char	checklegal(int *layout, int *params)
{
	/* convert to 2d */
	int converted[4][4];
	convert_1d_to_2d(layout, converted);

	/* run the check */
	char result = is_valid(params, converted);
	char resultChar = result + '0';
	print("Check, result is: ");
	write(1, &resultChar, 1);
	print("\n");
	return (result);
}

int	population(int spot, int*layout, int*params)
{
	int	guess;

	guess = 0;
	if (spot == 16) // base case. 15 or 16?
	{	
		printf("debug: The square was completely filled.");
		return 1;
	}
	// if (layout[spot] != 0) // skip prefilled spot
    //     return (population(spot + 1, layout, params)); // hiding temporarily
	while (guess < 4)
	{
		guess ++; // move?
		layout[spot] = guess;
		if (checklegal(layout, params) == 1) // go to next spot if correct
		{
			if (population(spot + 1, layout, params) == 1)
				return 1;
		}
		// layout[spot] = 0; 
	}
	return (0) ;
}
