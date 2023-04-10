/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:54:05 by andvieir          #+#    #+#             */
/*   Updated: 2023/04/04 12:00:36 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	mem_alloc(t_fdf *data, char *line, int fd, char *file_name)
{
	int	i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = ft_calloc(data->height, sizeof(int *));
	if (!data->z_matrix)
	{
		free(line);
		close(fd);
		return ;
	}
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = ft_calloc(data->width, sizeof(int));
		if (!data->z_matrix[i])
		{
			free(line);
			close(fd);
			return ;
		}
		i++;
	}
}

int	mem_free(char *line, int fd, int f)
{
	free(line);
	close(fd);
	return (f);
}
