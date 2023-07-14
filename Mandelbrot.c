/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:32:10 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/15 01:03:50 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	mandelbrot_calc(n_c c, int max_iter)
{
	n_c		z;
	int		i;
	double	mod;

	z.re = 0;
	z.img = 0;
	i = 0;
	mod = 0;
	while (i < max_iter && mod < 2)
	{
		z = sum_i(pow_i(z), c);
		mod = module(z);
		i++;
	}
	if (i == max_iter)
		return (max_iter);
	return (i + 1 - log(log(mod)) / log(1.3));
}

int	mandelbrot(t_data img)
{
	double	x;
	double	y;
	int		m;
	n_c		c;
	int		max_iter;

	max_iter = (int)(50 + img.zoom * 1.3);
	x = 0;
	img.colorset = getlist(img.colorint);
	while (x <= img.width)
	{
		y = 0;
		while (y <= img.height)
		{
			c.re = img.xmin + (x / img.width) * (img.xmax - img.xmin);
			c.img = img.ymin + (y / img.height) * (img.ymax - img.ymin);
			m = mandelbrot_calc(c, max_iter);
			my_mlx_pixel_put(&img, (int)x, (int)y, colors(m, max_iter, img));
			y++;
		}
		x++;
	}
	return (0);
}
