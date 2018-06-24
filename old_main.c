/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:34:18 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/06/23 20:37:57 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rtv1_ray_tracing(t_env *e)
{
	int		nx;
	int		ny;
	int		y;
	int		x;
	float	r, g, b;
	int		ir, ig, ib;

	nx = (int)e->win_x;
	ny = (int)e->win_y;
	y = ny;
	int	tmp_y = 0;
	while (--y >= 0)
	{
		x = -1;
		while (++x < nx)
		{
			r = (float)x / (float)nx;
			g = (float)y / (float)ny;
			b = 0.2;
			ir = (255 * r);
			ig = (255 * g);
			ib = (255 * b);
		e->data[(tmp_y * (int)e->win_x) + x] = ((ir & 0xFF) << 16) + ((ig & 0xFF) << 8) + (ib & 0xFF);
		}
		tmp_y++;
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
}

int		rtv1_exit(t_env *e)
{
	if (e->img_ptr)
		mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	if (e->win_ptr)
		mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	exit(0);
}

int		rtv1_key(int key, t_env *e)
{
	key == 53 ? rtv1_exit(e) : 0;
	return (0);
}

void	rtv1_start(t_env *e, char *str)
{
	char	*name;

	name = str;
	ft_bzero(e->data, e->win_x * e->win_y * 4);
	mlx_hook(e->win_ptr, 2, 2, rtv1_key, e);
	mlx_hook(e->win_ptr, 17, 0, rtv1_exit, e);
	rtv1_ray_tracing(e);
	mlx_loop(e->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
	{
		ft_printf("%s\n", "usage: ./rtv1 [shape]");
		exit(0);
	}
	e.win_x = 500;
	e.win_y = 500;
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, e.win_x, e.win_y, "rtv1");
	e.img_ptr = mlx_new_image(e.mlx_ptr, e.win_x, e.win_y);
	e.data = (int*)mlx_get_data_addr(e.img_ptr, &e.bpp, &e.size_line,
			&e.endian);
	rtv1_start(&e, av[1]);
	return (0);
}
