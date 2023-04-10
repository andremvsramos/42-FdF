/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:31:24 by andvieir          #+#    #+#             */
/*   Updated: 2023/04/04 12:00:28 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	max(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a > b)
		return (a);
	return (b);
}

void	apply_zoom_shift_color(t_draw *draw, t_fdf *data, float z, float z1)
{
	draw->x0 *= data->zoom;
	draw->y0 *= data->zoom;
	draw->x1 *= data->zoom;
	draw->y1 *= data->zoom;
	draw->x0 += data->shift_x;
	draw->y0 += data->shift_y;
	draw->x1 += data->shift_x;
	draw->y1 += data->shift_y;
	data->color = apply_color(z, z1);
}

void	isometric(float *x, float *y, float z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->trans_x);
	*y = (*x + *y) * sin(data->trans_y) - z;
}

void	bresenham(t_draw draw, t_fdf *data)
{
	float	draw_x;
	float	draw_y;
	int		max_mod;
	float	z;
	float	z1;

	draw_x = 0.0;
	draw_y = 0.0;
	z = data->z_matrix[(int)draw.y0][(int)draw.x0];
	z1 = data->z_matrix[(int)draw.y1][(int)draw.x1];
	apply_zoom_shift_color(&draw, data, z, z1);
	if (!data->view2d)
	{
		isometric(&draw.x0, &draw.y0, z, data);
		isometric(&draw.x1, &draw.y1, z1, data);
	}
	draw_x = draw.x1 - draw.x0;
	draw_y = draw.y1 - draw.y0;
	max_mod = max(draw_x, draw_y);
	draw_x /= max_mod;
	draw_y /= max_mod;
	print_pixels(draw, data, draw_x, draw_y);
}

/* Print grid on 2D plane using Δx and Δy
through Bresenham’s Line Drawing Algorithm*/
void	win_draw(t_fdf *data)
{
	t_draw	*aux;

	aux = ft_calloc(1, sizeof(t_draw));
	draw_init(aux);
	mlx_get_screen_size(data->mlx_ptr, &data->sizex, &data->sizey);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		0, 0, 0xffffff, data->file_name);
	aux->y0 = 0;
	aux->y1 = aux->y0;
	lines(aux, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->image->img, 0, 0);
	free(aux);
}
