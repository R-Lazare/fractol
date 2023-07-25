/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:18:35 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/25 17:14:00 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main_mandelbrot(t_data img)
{
	img.zoom = 0;
	img.width = 700;
	img.height = 466;
	img.xmin = -2;
	img.max_iter = 20;
	img.xmax = 1;
	img.colorint = 1;
	img.ymin = -1;
	img.ymax = 1;
	img.x0 = (img.xmax - img.xmin) / 2;
	img.y0 = (img.ymax - img.ymin) / 2;
	img.colorset = getlist(img.colorint, img, img.colorint * 200);
	img.colorpalette = colors(img.max_iter, img);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.width, img.height, "Mandelbrot");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img.current_fractal = &mandelbrot;
	img.current_fractal(img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}

int	main_julia(t_data img)
{
	img.zoom = 0;
	img.width = 700;
	img.height = 700;
	img.xmin = -1;
	img.xmax = 1;
	img.max_iter = 20;
	img.ymin = -1.2;
	img.ymax = 1.2;
	img.colorint = 1;
	img.x0 = (img.xmax - img.xmin) / 2;
	img.y0 = (img.ymax - img.ymin) / 2;
	img.colorset = getlist(img.colorint, img, img.colorint * 200);
	img.colorpalette = colors(img.max_iter, img);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.width, img.height, "Julia");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img.current_fractal = &julia;
	img.current_fractal(img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}

int	main_burningship(t_data img)
{
	img.zoom = 0;
	img.width = 700;
	img.height = 700;
	img.max_iter = 10;
	img.xmin = -2;
	img.xmax = 1.5;
	img.colorint = 1;
	img.ymin = -2;
	img.ymax = 0.5;
	img.colorset = getlist(img.colorint, img, img.colorint * 200);
	img.colorpalette = colors(img.max_iter, img);
	img.x0 = (img.xmax - img.xmin) / 2;
	img.y0 = (img.ymax - img.ymin) / 2;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.width, img.height, "Burningship");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img.current_fractal = &burningship;
	img.current_fractal(img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}

void	julia_no_args(t_data img)
{
	write(1, "Usage: ./fractol fractal re(C) img(C)\n", 38);
	arena_destroy(img.arena);
}

int	main(int argc, char **argv)
{
	t_data	img;

	img.arena = arena_init(2147483647);
	if (img.arena == NULL)
		return (0);
	if (argc < 2 || argc > 4)
		julia_no_args(img);
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		main_mandelbrot(img);
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc < 4)
			julia_no_args(img);
		else
		{
			img.c1 = ft_atod(argv[2]);
			img.c2 = ft_atod(argv[3]);
			main_julia(img);
		}
	}
	else if (ft_strcmp(argv[1], "burningship") == 0)
		main_burningship(img);
	else
		arena_destroy(img.arena);
	return (0);
}
