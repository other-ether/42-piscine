/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 23:18:13 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/09 18:05:00 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	check_legal(char*guess) // ok i either have a 1d array or a 2d array... if 1d, it'll be pointer arithmetic lor
{
	// check row, check column, check down horizontal, check up horizontal
}

int	*empty(int *arr) // 10x10 is index 0 to 99
{
	int	i;

	i = 0;
	while (i <= 99)
	{

	}
}

int	ft_ten_queens_puzzle(void)
{
	// the base condition doesn't actually stop the function. it increments solcount + prints the solution, then continue recursions until 0 solutions left globally
}

int	main(void)
{
	int	solcount;
	int	*board[100];

	

	// solcount = ft_ten_queens_puzzle;
	// printf("There are %d solutions", solcount);
	// return (0);
}