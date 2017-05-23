/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 16:09:25 by afanneau          #+#    #+#             */
/*   Updated: 2017/04/07 18:03:24 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_wall_line(t_pos *pos, char *map, int *y)
{
	int		x;

	x = 0;
	while (x < pos->tab_x)
	{
		if (pos->tab[*y][x] != 9)
			event_quit(pos, map);
		x++;
	}
	y++;
}

int		check_inside(t_pos *pos, int *y, int *s, int *p)
{
	int x;

	x = 1;
	while ((pos->tab[*y][x] == 0 || pos->tab[*y][x] == 3 || pos->tab[*y][x]
			== 4 || pos->tab[*y][x] == 9) && x < pos->tab_x)
	{
		if (pos->tab[*y][x] == 3)
			*p += 1;
		if (pos->tab[*y][x] == 4)
			*s += 1;
		x += 1;
	}
	return (x);
}

void	check_tab(t_pos *pos, char *map)
{
	int		y;
	int		p;
	int		s;

	p = 0;
	s = 0;
	y = 0;
	check_wall_line(pos, map, &y);
	while (y < pos->tab_y - 1)
	{
		pos->tab[y][0] != 9 ? event_quit(pos, map) : 0;
		pos->tab[y][pos->tab_x - 1] != 9 ? event_quit(pos, map) : 0;
		if (pos->tab_x != check_inside(pos, &y, &s, &p))
		{
			event_quit(pos, map);
		}
		y++;
	}
	check_wall_line(pos, map, &y);
	if (p != 1 || s != 1)
		event_quit(pos, map);
}
