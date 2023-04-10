/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:48:06 by andvieir          #+#    #+#             */
/*   Updated: 2023/04/04 12:00:31 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	fdf_init(t_fdf *data)
{
	data->width = 0;
	data->height = 0;
	data->z_matrix = NULL;
	data->trans_x = 0.8;
	data->trans_y = 0.8;
	data->zoom = 10;
	data->color = 0xff0000;
	data->shift_x = 0;
	data->shift_y = 0;
	if (VIEW == 3)
		data->view2d = 0;
	else if (VIEW == 2)
		data->view2d = 1;
	else
	{
		ft_printf("View point not recognized. Exiting program.");
		return ;
	}
}

void	graphics_init(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WIN_X, WIN_Y, data->file_name);
	data->image->img = mlx_new_image(data->mlx_ptr, WIN_X, WIN_Y);
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bpp,
			&data->image->len, &data->image->endian);
}

int	boot(char *file, t_fdf *data)
{
	fdf_init(data);
	data->file_name = get_fd_name(file);
	if (!data->file_name)
		return (0);
	if (!read_file(file, data))
		return (0);
	graphics_init(data);
	win_draw(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, deal_key, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, win_close, data);
	mlx_mouse_show(data->mlx_ptr, data->win_ptr);
	mlx_mouse_move(data->mlx_ptr, data->win_ptr, 960, 540);
	mlx_loop(data->mlx_ptr);
	return (1);
}
