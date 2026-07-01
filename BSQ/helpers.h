/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:01:29 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/16 23:09:49 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "structs.h"
# include "_1Dbuffer.h"
# include "compliance.h"
# include "readmap.h"
# include "questionarray.h"
# include "stdinbuffer.h"
# include "calc.h"

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_atoi_n(const char *str, size_t n);
void	ft_putnbr(int n);
void	print_map(int *arr, int rows, int cols);

#endif