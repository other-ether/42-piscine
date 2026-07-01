/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:53:01 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/09 22:25:11 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	remn;

	if (*b != 0)
		div = *a / *b;
	remn = *a % *b;
	*a = div;
	*b = remn;
}

int main (void)
{
	
}