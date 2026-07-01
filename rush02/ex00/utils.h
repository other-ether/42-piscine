/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 06:21:07 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/14 23:14:31 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "printvalue.h"
# include "split.h"

typedef struct buffering
{
	int		fd;
	int		total;
	int		nlen;
	int		size;
	int		i;
	ssize_t	n;
}	t_info;

void	printvalue(char *dictbuf, char *val);

#endif