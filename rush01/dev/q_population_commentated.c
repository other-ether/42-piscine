/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   population.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerckx <jmerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:44:31 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/07 15:05:53 by jmerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"
#include "convertor.h"
#include "write_util.h"
#include <unistd.h>

// actually yeah we don't need malloc BUT if we did:
// int *jegolayout;
// jegolayout = malloc(16 * sizeof(int));
// if (jegolayout == NULL) // routine malloc safeguard
// return (1);
//
// this function attempts to recursively populate a latin square from scratch spot-by-spot, guess-by-guess per spot,
// with a separate "check legality of whole square" function called after each guess
// then returns 1 itself if a global solution can be found. the array should stay modified without having to return it
//
// first called in main.c like:
// int possibility;
// possibility = population(0, jegolayout, params);
// if (possibility == 0){ return error message subfunction }
// else { solution printing subfunction }

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
	int	guess; // local loop var for testing 1234 on one spot

	guess = 0;
	if (spot == 16) // base case / terminating condition: all spots were already filled
		return 1;
	if (layout[spot] != 0) // THIS SHOULD ALLOW PREFILLED ARRAYS because it'll skip that spot, BUT still do recursion for the next spot
        return (population(spot + 1, layout, params));
	while (guess < 4)
	{
		guess ++;
		layout[spot] = guess;
		if (checklegal(layout, params) == 1)
		{
			if (population(spot + 1, layout, params) == 1) // goes into the next level of inception
				return 1; // this flags success for current path, but not necessarily global function success unless it's the last square
		}
	}
	layout[spot] = 0; // reset the spot when we are moving up inception levels so that the next recursion attempt can try something new
	return (0) ; // this flags fail for current path when going up, and also flags fail for global failure (no solutions possible at all)
}

// checklegal functions should check if a given integer array (of up to 16 ints, can have 0s or empty) can fulfill and satisfy the
// 16 parameters/tests that are inputted via the command line (argv's).