/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abandonedchecklegal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerckx <jmerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 21:47:15 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/07 14:49:49 by jmerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// here lies a grave for wretched code

// // this function checks if a partial solution can fulfill all parameter checks in all lines
// // HOW DO I SKIP HAVING TO PASS PARAMS INTO THIS AS ONE OF THIS FUNCTION's PARAMETERS
// // params == 16 argvs we get from the command line;  squareguess = current solution array (partial or not)
// // is int*params necessary or can i copy it into the function another way?

// int	checklegal(int*squareguess, int*params)
// {
// 	int	solcount;
// 	int	prmcount;
// 	int spotcount;

// 	solcount = 0;
// 	prmcount = 0;
// 	spotcount;
// 	while (prmcount < 16) // this loop checks for if all params has been fulfilled
// 	{
// 		while (spotcount < 16) // this inner loop checks if a specific individual param has been fulfilled
// 		{
// 			spotcount ++;
// 			// e.g. does param 2 work for line "3 4 1 2"; the right side would be like does param 4 work for line "2 1 4 3"
// 			// A B C D
// 			// starting from the first block, solcount++, then i ignore any blocks behind it that's shorter than it
// 			// then I do the same thing for the next block until and including the last block
// 			// solcount must match the params element for the test to be true for that line
// 			// there's probably a way to simplify this process mathematically and specifically for 4 blocks
// 			//  but first.
// 			// how do I use params to ... pull out the four numbers I want.. do I have to hard code this.... or we use the 2-dimension configuration...
// 			// any given param INDEX already tells us which 4 mini-squares it wants to see in the squareguess
// 			// e.g. first param wants to see square indices 0 + 4n, ninth param wants to see square indices 0, 1, 2, 3. there's a way to code this for sure
// 			if (prmcount < 5) // hardcoding LOL
// 			{
// 				squarecount[0+0*4], squarecount[0+1*4], squarecount[0+2*4], squarecount[0+3*4]
// 				uh... 
// 			}

// 			if (params[prmcount] != solcount) // fail flag for a given param = whole function returns fail
// 				return (0);
// 		}
// 		prmcount ++;
// 	}
// 	return (1); // success
// }