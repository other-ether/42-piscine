/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 19:20:58 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/16 22:54:07 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <stdlib.h>

typedef struct map_instructions
{
	int		rows;
	int		cols;
	char	empty;
	char	obst;
	char	full;
	int		i;
	char	*buff;
	int		valid;
	int		*question;
}	t_map;

typedef struct s_map_chunk
{
	char				chunk[4096];
	int					bytes;
	struct s_map_chunk	*next;
}	t_map_chunk;

typedef struct buffering
{
	int		fd;
	int		total;
	int		size;
	ssize_t	n;
}	t_info;

typedef struct s_win
{
	int	i;
	int	j;
	int	z;
}	t_win;

#endif