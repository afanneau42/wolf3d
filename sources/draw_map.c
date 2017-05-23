/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:53:13 by afanneau          #+#    #+#             */
/*   Updated: 2017/03/28 17:48:17 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_map(t_pos *pos)
{
	int		x;
	int		y;

	x = 1920 - pos->tab_x * 2 - 2;
	y = 0;
	while (y < pos->tab_y * 3)
	{
		x = 1920 - pos->tab_x * 2 - 2;
		while (x < 1920)
		{
			if (x == 1920 - pos->tab_x * 2 - 2 || x == 1917)
				img_pixel_put(x, y, 0x00000000, &pos->mlx);
			else if (pos->tab[y / 3][(x - (1920 - pos->tab_x * 2)) / 2] == 9)
				img_pixel_put(x, y, 0x00000000, &pos->mlx);
			else if (pos->tab[y / 3][(x - (1920 - pos->tab_x * 2)) / 2] == 4)
				img_pixel_put(x, y, 0x00FFFFFF, &pos->mlx);
			else
				img_pixel_put(x, y, 0x00CF7C63, &pos->mlx);
			if ((int)(y / 3) == (int)(pos->play_y) && (x - (1920 -
							pos->tab_x * 2)) / 2 == (int)(pos->play_x))
				img_pixel_put(x, y, 0x00FF0000, &pos->mlx);
			x++;
		}
		y++;
	}
}
