/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:42:00 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/18 17:50:47 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_calc(t_c c, t_c z0, t_data img)
{
	int	i;
	t_c	z;

	z = z0;
	i = 0;
	while (i < img.max_iter)
	{
		z = sum_i(pow_i(z), c);
		if (module(z) > 2)
			break ;
		i++;
	}
	if (i == img.max_iter)
		return (img.max_iter);
	return (i + 1 - log(log(module(z))) / log(1.4 - (0.75 + cos(img.colorint
					/ 10) / 3)));
}

int	julia(t_data img)
{
	double	x;
	double	y;
	int		m;
	t_c		c;
	t_c		z0;

	x = 0;
	c.re = img.c1;
	c.img = img.c2;
	img.colorset = getlist(img.colorint, img, 300);
	while (x <= img.width)
	{
		y = 0;
		while (y <= img.height)
		{
			z0.re = img.xmin + (x / img.width) * (img.xmax - img.xmin);
			z0.img = img.ymin + (y / img.height) * (img.ymax - img.ymin);
			m = julia_calc(c, z0, img);
			my_pixel_put(&img, (int)x, (int)y, colors(m, img.max_iter, img));
			y++;
		}
		x++;
	}
	return (0);
}
