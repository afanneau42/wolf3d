/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_lvl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 18:39:17 by afanneau          #+#    #+#             */
/*   Updated: 2017/04/26 14:10:27 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	clear_var(t_pos *pos)
{
	int		y;

	y = 0;
	while (y < pos->tab_y)
	{
		free(pos->tab[y]);
		y++;
	}
	free(pos->tab);
	pos->tab = NULL;
}

void	next_lvl(t_pos *pos)
{
	if (pos->lvl == 4)
		draw_xpm(pos, "./ressources/win.xpm");
	else
	{
		clear_var(pos);
		pos->speed = SPEED;
		pos->planex = 0;
		pos->planey = 0.6;
		pos->dirx = -1;
		pos->diry = 0;
		if (pos->lvl == 1)
			init_tab(pos, "./maps/map1");
		if (pos->lvl == 2)
			init_tab(pos, "./maps/map2");
		if (pos->lvl == 3)
			init_tab(pos, "./maps/map3");
		reprint(pos);
	}
}
