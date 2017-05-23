/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:45:18 by afanneau          #+#    #+#             */
/*   Updated: 2017/04/10 13:31:34 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycasting(t_pos *pos)
{
	pos->ray.rayposx = pos->play_x;
	pos->ray.rayposy = pos->play_y;
	pos->ray.raydirx = pos->dirx + pos->planex * pos->camerax;
	pos->ray.raydiry = pos->diry + pos->planey * pos->camerax;
	pos->ray.mapx = (int)pos->ray.rayposx;
	pos->ray.mapy = (int)pos->ray.rayposy;
	pos->ray.deltadistx = sqrt(1 + (pos->ray.raydiry * pos->ray.raydiry) /
			(pos->ray.raydirx * pos->ray.raydirx));
	pos->ray.deltadisty = sqrt(1 + (pos->ray.raydirx * pos->ray.raydirx) /
			(pos->ray.raydiry * pos->ray.raydiry));
	ray_deltadist(pos);
	ray_traceline(pos);
	ray_calculheigh(pos);
}

void	put_pixel(int y, int i, t_pos *pos)
{
	if (y < pos->ray.drawstart)
		img_pixel_put(i, y, 0x0085DCF2, &pos->mlx);
	else if (y < pos->ray.drawstart + 2 && pos->ray.drawstart > 0)
		img_pixel_put(i, y, 0x00000000, &pos->mlx);
	else if (y < pos->ray.drawend - 2 && y >
			pos->ray.drawstart + 2 && pos->ray.hit == 1)
	{
		if (pos->ray.side == 0 && pos->ray.stepx == 1)
			img_pixel_put(i, y, 0x003A8706, &pos->mlx);
		else if (pos->ray.side == 0 && pos->ray.stepx == -1)
			img_pixel_put(i, y, 0x0061E509, &pos->mlx);
		else if (pos->ray.side == 1 && pos->ray.stepy == 1)
			img_pixel_put(i, y, 0x0046A407, &pos->mlx);
		else if (pos->ray.side == 1 && pos->ray.stepy == -1)
			img_pixel_put(i, y, 0x0051BD08, &pos->mlx);
	}
	else if (y < pos->ray.drawend - 2 &&
			y > pos->ray.drawstart + 2 && pos->ray.hit == 2)
		img_pixel_put(i, y, 0x00FF99FF, &pos->mlx);
	else if (y <= pos->ray.drawend && pos->ray.drawend <= 1080)
		img_pixel_put(i, y, 0x00000000, &pos->mlx);
	else
		img_pixel_put(i, y, 0x00AE5A41, &pos->mlx);
}

void	launch_ray(t_pos *pos)
{
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (i < 1920)
	{
		pos->camerax = 2 * i / (double)1920 - 1;
		raycasting(pos);
		y = 0;
		while (y < 1080 - 1)
		{
			put_pixel(y, i, pos);
			y++;
		}
		i++;
	}
}
