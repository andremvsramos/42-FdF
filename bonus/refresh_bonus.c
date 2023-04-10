/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:11:15 by andvieir          #+#    #+#             */
/*   Updated: 2023/04/04 12:00:41 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	refresh(t_fdf *data)
{
	ft_bzero(data->image->addr, (1920 * 1080 * (data->image->bpp / 8)));
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	win_draw(data);
}
