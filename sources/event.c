/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:52:03 by afanneau          #+#    #+#             */
/*   Updated: 2017/04/10 13:35:50 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		event_key(int key, t_pos *pos)
{
	if (key == 53 && pos)
		event_quit(pos, 0);
	if (key == 257 && pos->lvl != 4)
	{
		if (pos->speed == SPEED)
			pos->speed *= 1.5;
		else
			pos->speed = SPEED;
	}
	return (0);
}

int		event_quit(t_pos *pos, void *name)
{
	if (name)
	{
		ft_putstr("Error : File ");
		ft_putstr(name);
		ft_putendl(" missing or not conveniant");
	}
	else
		clear_var(pos);
	exit(0);
	return (0);
}

void	draw_xpm(t_pos *pos, char *str)
{
	int		x;
	int		y;
	void	*xmp;

	x = 1920;
	y = 1080;
	clear_img(&pos->mlx);
	mlx_clear_window(pos->mlx.ad, pos->mlx.win);
	xmp = mlx_xpm_file_to_image(pos->mlx.ad, str, &x, &y);
	mlx_put_image_to_window(pos->mlx.ad, pos->mlx.win, xmp, 0, 0);
}

void	rotation(int key, t_pos *pos)
{
	double	olddirx;
	double	oldplanex;

	if (key == 124)
	{
		olddirx = pos->dirx;
		pos->dirx = pos->dirx * cos(-ROTSPEED) - pos->diry * sin(-ROTSPEED);
		pos->diry = olddirx * sin(-ROTSPEED) + pos->diry * cos(-ROTSPEED);
		oldplanex = pos->planex;
		pos->planex = pos->planex * cos(-ROTSPEED) -
			pos->planey * sin(-ROTSPEED);
		pos->planey = oldplanex * sin(-ROTSPEED) + pos->planey * cos(-ROTSPEED);
		reprint(pos);
	}
	if (key == 123)
	{
		olddirx = pos->dirx;
		pos->dirx = pos->dirx * cos(ROTSPEED) - pos->diry * sin(ROTSPEED);
		pos->diry = olddirx * sin(ROTSPEED) + pos->diry * cos(ROTSPEED);
		oldplanex = pos->planex;
		pos->planex = pos->planex * cos(ROTSPEED) -
			pos->planey * sin(ROTSPEED);
		pos->planey = oldplanex * sin(ROTSPEED) + pos->planey * cos(ROTSPEED);
		reprint(pos);
	}
}

int		event_key_hold(int key, t_pos *pos)
{
	if (pos->lvl == 4)
		return (0);
	if (key == 124 || key == 123)
		rotation(key, pos);
	if (key == 126 && pos->tab[(int)(pos->play_y + pos->diry * pos->speed)]
			[(int)(pos->play_x + pos->dirx * pos->speed)] != 9)
	{
		pos->play_x += pos->dirx * pos->speed;
		pos->play_y += pos->diry * pos->speed;
		reprint(pos);
	}
	if (key == 125 && pos->tab[(int)(pos->play_y - pos->diry * pos->speed)]
			[(int)(pos->play_x - pos->dirx * pos->speed)] != 9)
	{
		pos->play_x -= pos->dirx * pos->speed;
		pos->play_y -= pos->diry * pos->speed;
		reprint(pos);
	}
	if (pos->tab[(int)(pos->play_y)][(int)(pos->play_x)] == 4)
	{
		pos->lvl += 1;
		next_lvl(pos);
	}
	return (0);
}
