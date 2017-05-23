/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:29:53 by afanneau          #+#    #+#             */
/*   Updated: 2017/04/07 15:55:33 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(void)
{
	t_pos	pos;

	init(&pos);
	launch_ray(&pos);
	draw_map(&pos);
	draw_xpm(&pos, "./ressources/menu1.xpm");
	mlx_string_put(pos.mlx.ad, pos.mlx.win, 1300, 130, 0x00FFFFFF,
			"Your mission is to reach the pink case");
	mlx_string_put(pos.mlx.ad, pos.mlx.win, 1355, 180, 0x00FF99FF,
			"(cuz ur a fking soldier !)");
	mlx_hook(pos.mlx.win, 2, (1L << 0), event_key_hold, &pos);
	mlx_hook(pos.mlx.win, 17, (1L << 17), event_quit, &pos);
	mlx_key_hook(pos.mlx.win, event_key, &pos);
	mlx_loop(pos.mlx.ad);
	return (0);
}
