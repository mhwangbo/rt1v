/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:17:43 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/06/23 20:52:36 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../lib/libft/includes/libft.h"
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include <stdio.h>
# include <stddef.h>

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	start;
	t_vector	dir;
}				t_ray;

typedef struct	s_sphere
{
	t_vector	pos;
	float		radius;
	int			material
}				t_sphere;

typedef struct	s_color
{
	float		red;
	float		green;
	float		blue;
}				t_color;

typedef struct	s_light
{
	t_vector	pos;
	t_color		intensity;
}				t_light;

typedef struct	s_material
{
	t_color		diffuse;
	float		reflection;
}				t_material;

typedef struct	s_env
{
	double		win_x;
	double		win_y;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	int			*data;
	t_vec		vec;
}				t_env;

#endif
