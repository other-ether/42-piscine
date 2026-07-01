/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerckx <jmerckx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:49:46 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 17:01:46 by jmerckx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	is_valid_see(int values[], int solution[4][4]);
char	is_valid_unique(int solution[4][4]);

char	is_valid(int values[16], int solution[4][4])
{
	if (is_valid_unique(solution) == 0)
		return (0);
	if (is_valid_see(values, solution) == 0)
		return (0);
	return (1);
}
