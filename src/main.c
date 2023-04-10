/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:58:26 by marvin            #+#    #+#             */
/*   Updated: 2023/01/08 21:58:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	draw_init(t_draw *draw)
{
	draw->x0 = 0;
	draw->y0 = 0;
	draw->x1 = 0;
	draw->y1 = 0;
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 65307)
		if (win_close(data))
			exit (1);
	check_2d(key, data);
	get_zoom(key, data);
	get_move3d(key, data);
	get_move2d(key, data);
	get_trans(key, data);
	return (0);
}

int	win_close(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	mlx_destroy_image(data->mlx_ptr, data->image->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->file_name);
	free(data->image);
	free(data->mlx_ptr);
	free(data);
	return (1);
}

char	*get_fd_name(char *str)
{
	int		i;
	int		j;
	char	*name;

	j = 0;
	if (!str)
		return (0);
	j = 0;
	i = 0;
	while (*str != '/')
		str++;
	str++;
	name = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!name)
	{
		free(name);
		return (0);
	}
	while (str[i])
		name[j++] = str[i++];
	name[j] = '\0';
	return (name);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc == 2 && check_if_fdf(argv[1]))
	{
		if (!argv[1])
			return (0);
		data = (t_fdf *)malloc(sizeof(t_fdf));
		if (!data)
			return (0);
		data->image = (t_i *)malloc(sizeof(t_i));
		if (!data->image)
			return (0);
		if (!boot(argv[1], data))
		{
			ft_printf("Oops. Something went wrong! Aborting...");
			win_close(data);
			return (0);
		}
	}
	else
	{
		ft_printf("Invalid ammount of parameters or file type.\n");
		ft_printf("Please input a valid FdF file path.\n");
	}
	return (0);
}
