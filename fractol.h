/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:37:11 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/15 18:06:58 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include "includes/minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	int		width;
	int		(*current_fractal)(struct s_data);
	int		max_iter;
	int		height;
	int		zoom;
	char	*addr;
	int		**colorset;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	double	xmin;
	double	c1;
	double	c2;
	double	xmax;
	int		colorint;
	double	ymin;
	double	ymax;
	double	x0;
	double	y0;
	void	*win;
}			t_data;

typedef struct nb_c
{
	double	re;
	double	img;
}			t_c;

int			facto(int n);
void		my_pixel_put(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
int			key_hook(int keycode, t_data *img);
int			mandelbrot(t_data img);
t_c			mult_c(t_c a, t_c b);
t_c			pow_i(t_c c);
t_c			sum_i(t_c a, t_c b);
double		module(t_c C);
double		ft_atod(char *str);
int			mouse_hook(int button, int x, int y, t_data *img);
int			julia(t_data img);
int			colors(int m, int max_iter, t_data img);
int			**getlist(double b);
int			key_hook_arrows(int keycode, t_data *img);
#endif