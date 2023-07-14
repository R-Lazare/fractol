/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minihelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:32:00 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/14 18:48:40 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362)
	{
		img->ymin = img->ymin - 0.1 * (1 / cosh(pow(img->zoom, 0.75)));
		img->ymax = img->ymax - 0.1 * (1 / cosh(pow(img->zoom, 0.75)));
	}
	if (keycode == 65364)
	{
		img->ymin = img->ymin + 0.1 * (1 / cosh(pow(img->zoom, 0.75)));
		img->ymax = img->ymax + 0.1 * (1 / cosh(pow(img->zoom, 0.75)));
	}
	if (keycode == 65361)
	{
		img->xmin = img->xmin - 0.1 * (1 / cosh(pow(img->zoom, 0.75)));
		img->xmax = img->xmax - 0.1 * (1 / cosh(pow(img->zoom, 0.75)));
	}
	if (keycode == 65363)
	{
		img->xmin = img->xmin + 0.1 * (1 / cosh(pow(img->zoom, 0.75)));
		img->xmax = img->xmax + 0.1 * (1 / cosh(pow(img->zoom, 0.75)));
	}
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	img->current_fractal(*img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *img)
{
	img->x0 = (double)x / img->width;
	img->y0 = (double)y / img->height;
	if (button == 4)
	{
		img->zoom++;
		img->xmin = img->xmin + (img->x0) * (img->xmax - img->xmin) / 2;
		img->xmax = img->xmax - (1 - img->x0) * (img->xmax - img->xmin) / 2;
		img->ymin = img->ymin + (img->y0) * (img->ymax - img->ymin) / 2;
		img->ymax = img->ymax - (1 - img->y0) * (img->ymax - img->ymin) / 2;
	}
	if (button == 5)
	{
		img->zoom--;
		img->xmin = img->xmin - (img->x0) * (img->xmax - img->xmin) / 2;
		img->xmax = img->xmax + (1 - img->x0) * (img->xmax - img->xmin) / 2;
		img->ymin = img->ymin - (img->y0) * (img->ymax - img->ymin) / 2;
		img->ymax = img->ymax + (1 - img->y0) * (img->ymax - img->ymin) / 2;
	}
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	img->current_fractal(*img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}
