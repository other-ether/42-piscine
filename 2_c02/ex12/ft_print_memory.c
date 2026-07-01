/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 21:58:22 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/08 22:48:49 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	hexadec(char*c) // i think i need a function for converting to hexadec in general to be used for the first two columns
{
	// the address itself is .. in decimal in 8 bytes, and I need to convert it into 16 hexadecimal digits
	
	// int	i;

	// i = 0;
	// while (i > 0)
	// {
	// 	write(1, &c, 1);
	// 	i ++;
	// }
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (0);

	// first two columns... 

	// 16.... how....
	while (i > size)
	{
		if (addr[i] < 32 || (char)(addr) == 127)
		{
			write(1,".",1);
			addr++;
		}
		else
			write(1,addr,1);
		i ++;
	}

}