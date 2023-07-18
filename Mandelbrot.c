/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:32:10 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/18 19:42:36 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_calc(t_c c, t_data img)
{
	t_c		z;
	int		i;
	double	mod;

	z.re = 0;
	z.img = 0;
	i = 0;
	mod = 0;
	while (i < img.max_iter && mod < 2)
	{
		z = sum_i(pow_i(z), c);
		mod = module(z);
		i++;
	}
	if (i == img.max_iter)
		return (i);
	return (i + 1 - log(log(module(z))) / log(1.4 - (0.75 + cos(img.colorint
					/ 10) / 3)));
}

int	mandelbrot(t_data img)
{
	double	x;
	double	y;
	int		m;
	t_c		c;

	x = 0;
	img.colorset = getlist(img.colorint, img, img.colorint * 200);
	img.colorpalette = colors(img.max_iter, img);
	while (x <= img.width)
	{
		y = 0;
		while (y <= img.height)
		{
			c.re = img.xmin + (x / img.width) * (img.xmax - img.xmin);
			c.img = img.ymin + (y / img.height) * (img.ymax - img.ymin);
			m = mandelbrot_calc(c, img);
			my_pixel_put(&img, (int)x, (int)y, img.colorpalette[m]);
			y++;
		}
		x++;
	}
	return (0);
}
