/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 23:08:15 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/16 23:09:53 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H
# include "structs.h"

int		min(int a, int b, int c);
void	dynamic(int *map, const int rows, const int cols);
t_win	find_best(int *map, const int rows, const int cols);
t_win	calc(int *map, const int rows, const int cols);

#endif