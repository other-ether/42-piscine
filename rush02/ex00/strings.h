/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:16:18 by guoliu            #+#    #+#             */
/*   Updated: 2026/06/14 22:27:24 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		matchkey(char *s1, char *s2, unsigned int n);
char	*ft_strstr(char *haystack, char *to_find);

#endif