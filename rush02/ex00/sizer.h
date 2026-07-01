/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 06:21:05 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/14 20:16:55 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZER_H
# define SIZER_H

int			fill_buff(int fd, char *buf);
int			dict_prep(const char *dictname, char **buf_ptr);

#endif