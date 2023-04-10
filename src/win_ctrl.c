/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:49:33 by andvieir          #+#    #+#             */
/*   Updated: 2023/04/04 12:00:46 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	get_zoom(int key, t_fdf *data)
{
	if (key == 65451 || key == 4)
		data->zoom += 0.2;
	if (key == 65453 || key == 5)
		data->zoom -= 0.2;
	refresh(data);
}

void	get_move3d(int key, t_fdf *data)
{
	if (!data->view2d)
	{
		if (key == 119)
		{
			data->shift_y -= 10;
			data->shift_x -= 10;
		}
		if (key == 115)
		{
			data->shift_y += 10;
			data->shift_x += 10;
		}
		if (key == 97)
		{
			data->shift_x -= 3;
			data->shift_y += 7;
		}
		if (key == 100)
		{
			data->shift_x += 3;
			data->shift_y -= 6.8;
		}
	}
	refresh(data);
}

void	get_move2d(int key, t_fdf *data)
{
	if (data->view2d)
	{
		if (key == 119)
			data->shift_y -= 10;
		if (key == 115)
			data->shift_y += 10;
		if (key == 97)
			data->shift_x -= 10;
		if (key == 100)
			data->shift_x += 10;
	}
	refresh(data);
}

void	get_trans(int key, t_fdf *data)
{
	if (key == 113)
		data->trans_x += 0.01;
	if (key == 101)
		data->trans_x -= 0.01;
	if (key == 122)
		data->trans_y += 0.01;
	if (key == 99)
		data->trans_y -= 0.01;
	refresh(data);
}

void	check_2d(int key, t_fdf *data)
{
	int	aux;

	aux = data->view2d;
	if (key == 65289)
	{
		if (!data->view2d)
			data->view2d = 1;
		else
			data->view2d = 0;
	}
	if (aux != data->view2d)
		refresh(data);
}
