/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:43:11 by andvieir          #+#    #+#             */
/*   Updated: 2023/04/04 12:00:43 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	ft_strlensep(char *str, char c)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = ft_split(str, c);
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (i);
}

int	check_if_fdf(char *file_name)
{
	int		len;
	int		fdflen;
	char	*fdf;

	fdf = ".fdf";
	fdflen = 4;
	len = ft_strlen(file_name) - 1;
	while (fdflen)
		if (file_name[len--] != fdf[--fdflen])
			return (0);
	return (1);
}

void	my_mlx_pixel_put(t_i *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	print_pixels(t_draw draw, t_fdf *data, float draw_x, float draw_y)
{
	while ((int)(draw.x0 - draw.x1) || (int)(draw.y0 - draw.y1))
	{
		if (draw.y0 > data->sizey || draw.y0 < 0)
		{
			if (draw.x0 > (data->sizex / 2)
				|| draw.x0 < (-1 * (data->sizex / 2)))
				my_mlx_pixel_put(data->image, 0, 0, 0x000000);
			else
				my_mlx_pixel_put(data->image,
					draw.x0 + (data->sizex / 2), 0, 0x000000);
		}
		else if (draw.x0 > (data->sizex / 2)
			|| draw.x0 < (-1 * (data->sizex / 2)))
			my_mlx_pixel_put(data->image, 0, draw.y0, 0x000000);
		else
			my_mlx_pixel_put(data->image,
				draw.x0 + (data->sizex / 2), draw.y0, data->color);
		draw.x0 += draw_x;
		draw.y0 += draw_y;
	}
}

void	lines(t_draw *aux, t_fdf *data)
{
	while ((int)aux->y0 < data->height)
	{
		aux->x0 = 0;
		while ((int)aux->x0 < data->width)
		{
			if ((int)aux->x0 < data->width - 1)
			{
				aux->x1 = aux->x0 + 1;
				bresenham(*aux, data);
			}
			if ((int)aux->y0 < data->height - 1)
			{
				aux->y1 = aux->y0 + 1;
				aux->x1 = aux->x0;
				bresenham(*aux, data);
				aux->y1 = aux->y0;
			}
			aux->x0++;
		}
		aux->y0++;
		aux->y1 = aux->y0;
	}
}
