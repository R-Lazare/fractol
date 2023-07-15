/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:09:09 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/15 14:42:56 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL

# define FRACTOL
# include "minilibx-linux/mlx.h"
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
}			n_c;

int			facto(int n);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
int			key_hook(int keycode, t_data *img);
int			mandelbrot(t_data img);
n_c			mult_c(n_c a, n_c b);
n_c			pow_i(n_c c);
n_c			sum_i(n_c a, n_c b);
double		module(n_c C);
int			mouse_hook(int button, int x, int y, t_data *img);
int			julia(t_data img);
int			julia_calc(n_c c, n_c z, int max_iter);
int			colors(int m, int max_iter, t_data img);
int			**getlist(double b);
#endif