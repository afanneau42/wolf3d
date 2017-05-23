/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:29:38 by afanneau          #+#    #+#             */
/*   Updated: 2017/04/07 17:26:33 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define H 1080
# define ROTSPEED 0.04
# define SPEED 0.1

# define WIN_X 1920
# define WIN_Y 1080

# define CASE_X 256
# define CASE_Y 256
# define CASE_Z 256

typedef struct	s_cord
{
	double		x;
	double		y;
	double		z;
	double		dist;
	int			var;
}				t_cord;

typedef struct	s_mlx
{
	void		*ad;
	void		*win;
	void		*img_ad;
	void		*xpm;

	int			*bpp;
	int			*size_l;
	int			*edi;
	char		*img_mem;
}				t_mlx;

typedef struct	s_ray
{
	double		rayposx;
	double		rayposy;

	double		raydirx;
	double		raydiry;

	double		sidedistx;
	double		sidedisty;

	double		deltadistx;
	double		deltadisty;

	int			stepx;
	int			stepy;

	int			side;
	int			hit;

	double		perpwalldist;

	int			drawstart;
	int			drawend;

	int			mapx;
	int			mapy;
}				t_ray;

typedef struct	s_pos
{
	t_mlx		mlx;
	t_ray		ray;

	int			**tab;
	int			tab_x;
	int			tab_y;

	double		play_x;
	double		play_y;

	double		speed;

	double		dirx;
	double		diry;
	double		planex;
	double		planey;

	double		camerax;

	int			lvl;
	int			endlvl;
}				t_pos;

/*
**  Initialisation
*/

void			init(t_pos *pos);
void			init_tab(t_pos *pos, char *map);
void			clear_var(t_pos *pos);
void			check_tab(t_pos *pos, char *map);

/*
**  Events
*/

int				event_key(int key, t_pos *pos);
int				event_key_hold(int key, t_pos *pos);
int				event_quit(t_pos *pos, void *name);
void			next_lvl(t_pos *pos);
void			free_exit(t_pos *pos);

/*
**  Raycasting
*/

void			raycasting(t_pos *pos);
void			launch_ray(t_pos *pos);
void			ray_deltadist(t_pos *pos);
void			ray_traceline(t_pos *pos);
void			ray_calculheigh(t_pos *pos);

/*
**  Affichage
*/

void			set_cross(t_pos *pos);
void			reprint(t_pos *pos);
void			clear_img(t_mlx *mlx);
void			img_pixel_put(int x, int y, int color, t_mlx *mlx);
void			draw_map(t_pos *pos);
void			draw_xpm(t_pos *pos, char *str);

#endif
