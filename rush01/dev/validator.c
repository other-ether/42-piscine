/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:49:46 by jmerckx           #+#    #+#             */
/*   Updated: 2026/06/07 17:17:44 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "see_validator.h"
#include "unique_validator.h"

char	is_valid(int values[], int solution[4][4])
{
	if (is_valid_unique(solution) == 0)
		return (0);
	if (is_valid_see(values, solution) == 0)
		return (0);
	return (1);
}
