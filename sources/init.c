/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:50:30 by afanneau          #+#    #+#             */
/*   Updated: 2017/04/07 17:28:28 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	size_of_file(t_pos *pos, char *map)
{
	int		fd;
	char	*line;

	pos->tab_x = 0;
	pos->tab_y = 0;
	fd = open(map, O_RDONLY);
	fd == -1 ? event_quit(pos, map) : 0;
	if (get_next_line(fd, &line) > 0)
	{
		while (line[pos->tab_x])
			pos->tab_x++;
		pos->tab_y++;
		free(line);
	}
	while (get_next_line(fd, &line) > 0)
	{
		pos->tab_y++;
		free(line);
	}
	free(line);
	close(fd);
}

void	create_tab(t_pos *pos, char *map)
{
	int		fd;
	int		x;
	int		y;
	char	*line;

	x = 0;
	y = 0;
	fd = open(map, O_RDONLY);
	pos->tab = (int**)malloc(sizeof(pos->tab) * pos->tab_y);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		pos->tab[y] = (int*)malloc(sizeof(int) * pos->tab_x);
		while (line[x])
		{
			pos->tab[y][x] = line[x] - '0';
			x++;
		}
		y++;
		free(line);
	}
	free(line);
	close(fd);
}

void	init_tab(t_pos *pos, char *map)
{
	pos->play_y = 0;
	pos->play_x = 0;
	size_of_file(pos, map);
	create_tab(pos, map);
	check_tab(pos, map);
	while ((int)pos->play_y < (int)pos->tab_y &&
			pos->tab[(int)pos->play_y][(int)pos->play_x] != 3)
	{
		pos->play_x = 0;
		while (pos->tab[(int)pos->play_y][(int)pos->play_x] != 3 &&
				pos->play_x < pos->tab_x)
			pos->play_x++;
		if (pos->tab[(int)pos->play_y][(int)pos->play_x] != 3)
			pos->play_y++;
	}
	pos->play_y = pos->play_y + 0.5;
	pos->play_x = pos->play_x + 0.5;
	pos->tab[(int)pos->play_y][(int)pos->play_x] = 0;
}

void	init(t_pos *pos)
{
	pos->mlx.ad = mlx_init();
	pos->mlx.win = mlx_new_window(pos->mlx.ad, WIN_X, WIN_Y, "Wolf3d");
	pos->mlx.img_ad = mlx_new_image(pos->mlx.ad, WIN_X, WIN_Y);
	pos->mlx.bpp = malloc(sizeof(int) * 4);
	pos->mlx.size_l = malloc(sizeof(int) * WIN_X * 4);
	pos->mlx.edi = malloc(sizeof(int));
	pos->mlx.img_mem = mlx_get_data_addr(pos->mlx.img_ad, pos->mlx.bpp,
			pos->mlx.size_l, pos->mlx.edi);
	pos->speed = SPEED;
	pos->planex = 0;
	pos->planey = 0.6;
	pos->dirx = -1;
	pos->diry = 0;
	pos->lvl = 0;
	free(pos->mlx.bpp);
	free(pos->mlx.size_l);
	free(pos->mlx.edi);
	init_tab(pos, "./maps/map0");
}
