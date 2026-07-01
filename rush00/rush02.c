/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 15:46:42 by hwelee            #+#    #+#             */
/*   Updated: 2026/05/31 17:50:33 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	print_row(char side, char middle, int width);
int		check_error(int x, int y);

void	rush(int x, int y)
{
	int	current_row;

	if (check_error(x, y) != -1)
	{
		current_row = 1;
		print_row('A', 'B', x);
		if (y > 1)
		{
			while (current_row < y - 1)
			{
				print_row('B', ' ', x);
				current_row ++;
			}
			print_row('C', 'B', x);
		}
	}
}

// Prints a row
void	print_row(char side, char middle, int width)
{
	int	current_col;

	current_col = 1;
	ft_putchar(side);
	if (width > 1)
	{
		while (current_col < width - 1)
		{
			ft_putchar(middle);
			current_col++;
		}
		ft_putchar(side);
	}
	ft_putchar('\n');
}

int	check_error(int x, int y)
{
	char	*errmsg1;
	char	*errmsg2;

	errmsg1 = " Values too high (x>221 or y>55) may cause display issues.\n";
	errmsg2 = " You must use positive numbers for x and y.\n";
	if (x > 211 || y > 55)
	{
		while (*errmsg1++ > 0)
			ft_putchar(*errmsg1);
		return (-1);
	}
	else if (x < 1 || y < 1)
	{
		while (*errmsg2++ > 0)
			ft_putchar(*errmsg2);
		return (-1);
	}
	else
		return (0);
}
