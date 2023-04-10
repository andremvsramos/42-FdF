/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:03:16 by marvin            #+#    #+#             */
/*   Updated: 2023/01/08 22:03:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

//Check how many lines there are to know f(x)
int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

//Check length of first line to know f(y)
int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_strlensep(line, ' ');
	free(line);
	close(fd);
	return (width);
}

/*-Fill each f(y,x++)
fill_matrix() on main increments y-*/
// void	fill_matrix(int	*z_line, char *line)
void	fill_matrix(t_fdf *data, int index, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (i < data->width)
	{
		data->z_matrix[index][i] = ft_atoi(nums[i]);
		i++;
	}
	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

int	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (mem_free(line, fd, 0));
	mem_alloc(data, line, fd, file_name);
	i = 0;
	while (line)
	{
		fill_matrix(data, i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (mem_free(line, fd, 1));
}
