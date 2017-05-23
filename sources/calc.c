/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:45:18 by afanneau          #+#    #+#             */
/*   Updated: 2017/04/10 13:35:10 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ray_deltadist(t_pos *pos)
{
	if (pos->ray.raydirx < 0)
	{
		pos->ray.stepx = -1;
		pos->ray.sidedistx = (pos->ray.rayposx - pos->ray.mapx)
			* pos->ray.deltadistx;
	}
	else
	{
		pos->ray.stepx = 1;
		pos->ray.sidedistx = (pos->ray.mapx + 1.0 - pos->ray.rayposx)
			* pos->ray.deltadistx;
	}
	if (pos->ray.raydiry < 0)
	{
		pos->ray.stepy = -1;
		pos->ray.sidedisty = (pos->ray.rayposy - pos->ray.mapy)
			* pos->ray.deltadisty;
	}
	else
	{
		pos->ray.stepy = 1;
		pos->ray.sidedisty = (pos->ray.mapy + 1.0 - pos->ray.rayposy)
			* pos->ray.deltadisty;
	}
}

void	ray_traceline(t_pos *pos)
{
	pos->ray.hit = 0;
	pos->ray.side = 0;
	while (pos->ray.hit == 0)
	{
		if (pos->ray.sidedistx < pos->ray.sidedisty)
		{
			pos->ray.side = 0;
			pos->ray.sidedistx += pos->ray.deltadistx;
			pos->ray.mapx += pos->ray.stepx;
		}
		else
		{
			pos->ray.side = 1;
			pos->ray.sidedisty += pos->ray.deltadisty;
			pos->ray.mapy += pos->ray.stepy;
		}
		if (pos->tab[(int)(pos->ray.mapy)][(int)(pos->ray.mapx)] == 9)
			pos->ray.hit = 1;
		if (pos->tab[(int)(pos->ray.mapy)][(int)(pos->ray.mapx)] == 4)
			pos->ray.hit = 2;
	}
}

void	ray_calculheigh(t_pos *pos)
{
	double lineheight;

	lineheight = 0;
	if (pos->ray.side == 0)
	{
		pos->ray.perpwalldist = (pos->ray.mapx - pos->ray.rayposx +
			(1 - pos->ray.stepx) / 2) / pos->ray.raydirx;
	}
	else
	{
		pos->ray.perpwalldist = (pos->ray.mapy - pos->ray.rayposy +
			(1 - pos->ray.stepy) / 2) / pos->ray.raydiry;
	}
	lineheight = (int)(H / pos->ray.perpwalldist);
	pos->ray.drawstart = -lineheight / 2 + H / 2 - 10;
	pos->ray.drawend = lineheight / 2 + H / 2 + 10;
}
