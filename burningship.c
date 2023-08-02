/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:51:47 by rluiz             #+#    #+#             */
/*   Updated: 2023/08/02 22:19:17 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:32:10 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/15 18:41:04 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burningship_calc(t_c c, t_data img)
{
	t_c		z;
	int		i;
	double	mod;
	t_c		temp;

	z.re = c.re;
	z.img = c.img;
	i = 0;
	mod = 0;
	while (i < img.max_iter && mod < 2)
	{
		temp.re = z.re;
		if (temp.re < 0)
			temp.re = -temp.re;
		temp.img = z.img;
		if (temp.img < 0)
			temp.img = -temp.img;
		z = sum_i(pow_c(z,img.power), c);
		mod = module(z);
		i++;
	}
	if (i == img.max_iter)
		return (img.max_iter);
	return (i + 1 - log(log(module(z))) / log(1.4 - (0.75 + cos(img.colorint
					/ 10) / 3)));
}

int	burningship(t_data img)
{
	double	x;
	double	y;
	int		m;
	t_c		c;

	x = 0;
	while (x <= img.width)
	{
		y = 0;
		while (y <= img.height)
		{
			c.re = img.xmin + (x / img.width) * (img.xmax - img.xmin);
			c.img = img.ymin + (y / img.height) * (img.ymax - img.ymin);
			m = burningship_calc(c, img);
			my_pixel_put(&img, (int)x, (int)y, (int)(img.colorpalette[m]));
			y++;
		}
		x++;
	}
	return (0);
}

int	freeall(t_data *img)
{
	if (img->arena)
	{
		arena_destroy(img->arena);
		if (img->img)
		{
			mlx_destroy_image(img->mlx, img->img);
			if (img->win)
				mlx_destroy_window(img->mlx, img->win);
			if (img->mlx)
				mlx_destroy_display(img->mlx);
			if (img->mlx)
				free(img->mlx);
		}
	}
	exit(0);
	return (0);
}
