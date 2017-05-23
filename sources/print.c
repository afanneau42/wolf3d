/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:42:15 by afanneau          #+#    #+#             */
/*   Updated: 2017/03/29 18:10:47 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	img_pixel_put(int x, int y, int color, t_mlx *mlx)
{
	mlx->img_mem[x * 4 + y * WIN_X * 4] = color & 255;
	mlx->img_mem[1 + x * 4 + y * WIN_X * 4] = (color >> 8) & 255;
	mlx->img_mem[2 + x * 4 + y * WIN_X * 4] = (color >> 16) & 255;
}

void	clear_img(t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < 1080 * WIN_X * 4)
	{
		mlx->img_mem[i] = 0;
		i++;
	}
}

void	reprint(t_pos *pos)
{
	clear_img(&pos->mlx);
	launch_ray(pos);
	set_cross(pos);
	draw_map(pos);
	mlx_clear_window(pos->mlx.ad, pos->mlx.win);
	mlx_put_image_to_window(pos->mlx.ad, pos->mlx.win,
			pos->mlx.img_ad, 0, 0);
}

void	set_cross(t_pos *pos)
{
	int		i;

	i = 950;
	while (i < 970)
	{
		if (i < 957 || i > 963)
			img_pixel_put(i, 540, 0x00FF0000, &pos->mlx);
		i++;
	}
	i = 530;
	while (i < 550)
	{
		if (i < 537 || i > 543)
			img_pixel_put(960, i, 0x00FF0000, &pos->mlx);
		i++;
	}
}
