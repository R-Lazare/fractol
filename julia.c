/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:42:00 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/15 01:02:36 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	julia_calc(n_c c, n_c z0, int max_iter)
{
	int	i;
	n_c	z;

	z = z0;
	i = 0;
	while (i < max_iter)
	{
		z = sum_i(pow_i(z), c);
		if (module(z) > 2)
			break ;
		i++;
	}
	if (i == max_iter)
		return (max_iter);
	return (i + 1 - log(log(module(z))) / log(1.30));
}

int	julia(t_data img)
{
	double x;
	double y;
	int m;
	n_c c;
	n_c z0;
	int max_iter;

	max_iter = (int)(95 + img.zoom * 1.4);
	x = 0;
	c.re = -0.7;
	c.img = 0.27015;
	img.colorset = getlist(img.colorint);
	while (x <= img.width)
	{
		y = 0;
		while (y <= img.height)
		{
			z0.re = img.xmin + (x / img.width) * (img.xmax - img.xmin);
			z0.img = img.ymin + (y / img.height) * (img.ymax - img.ymin);
			m = julia_calc(c, z0, max_iter);
			my_mlx_pixel_put(&img, (int)x, (int)y, colors(m, max_iter, img));
			y++;
		}
		x++;
	}
	return (0);
}