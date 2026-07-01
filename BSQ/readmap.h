/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 22:44:16 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/16 17:32:21 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READMAP_H
# define READMAP_H

int		has_newline(char *buff);
int		firstline(char *buff, t_map *m);
int		findcols(char *buff, t_map *m);
t_map	readmap(char *mapname);

#endif