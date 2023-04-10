/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:22:53 by andvieir          #+#    #+#             */
/*   Updated: 2023/04/04 12:00:25 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	apply_color(float z, float z1)
{
	int	colorcode;

	colorcode = 0xffffff;
	if ((z > 10 || z1 > 10) && (z <= 100 || z1 <= 100))
	{
		if (z <= 40 || z1 <= 40)
			colorcode = 0x228b22;
		else
			colorcode = 0xfffafa;
	}
	else if ((z <= 10 || z1 <= 10) && (z > 5 || z1 > 5))
		colorcode = 0x964b00;
	else if ((z >= 4 || z1 >= 4) && (z <= 5 || z1 <= 5))
		colorcode = 0xc2b280;
	else if ((z < 4 || z1 < 4) && (z >= 0 || z1 >= 0))
		colorcode = 0x253da1;
	else if (z < 0 || z1 < 0)
		colorcode = 0xffff00;
	return (colorcode);
}
