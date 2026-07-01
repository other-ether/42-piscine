/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guoliu <guoliu@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:56:50 by kitang            #+#    #+#             */
/*   Updated: 2026/06/14 23:00:18 by guoliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	get_chunks(char *nbr, int *total_len)
{
	int	chunks;

	*total_len = 0;
	while (nbr[*total_len] != '\0')
		(*total_len)++;
	chunks = *total_len / 3;
	if (*total_len % 3 != 0)
		chunks += 1;
	return (chunks);
}

char	*make_chunk(char *nbr, int *str_idx, int chunk_len)
{
	char	*chunk;
	int		j;

	chunk = (char *)malloc((chunk_len + 1) * sizeof(char));
	if (!chunk)
		return (NULL);
	j = 0;
	while (j < chunk_len)
	{
		chunk[j] = nbr[*str_idx];
		(*str_idx)++;
		j++;
	}
	chunk[j] = '\0';
	return (chunk);
}

int	get_chunk_len(int i, int total_len)
{
	if (i == 0 && (total_len % 3 != 0))
		return (total_len % 3);
	return (3);
}

int	fill_chunks(char *nbr, char **result, int chunks, int total_len)
{
	int	str_idx;
	int	i;

	str_idx = 0;
	i = 0;
	while (i < chunks)
	{
		result[i] = make_chunk(nbr, &str_idx, get_chunk_len(i, total_len));
		if (!result[i])
			return (-1);
		i++;
	}
	return (0);
}

char	**split_threes(char *nbr, int *size)
{
	int		total_len;
	int		chunks;
	char	**result;

	if (!nbr)
		return (NULL);
	chunks = get_chunks(nbr, &total_len);
	if (total_len == 0)
		return (NULL);
	*size = chunks;
	result = (char **)malloc(chunks * sizeof(char *));
	if (!result)
		return (NULL);
	if (fill_chunks(nbr, result, chunks, total_len) < 0)
		return (NULL);
	return (result);
}
