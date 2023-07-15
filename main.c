/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:18:35 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/15 17:57:27 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return ((s1[i] - s2[i]));
		i++;
	}
	return (0);
}

int	main_mandelbrot(t_data img)
{
	img.zoom = 0;
	img.mlx = mlx_init();
	img.width = 900;
	img.height = 600;
	img.xmin = -2;
	img.xmax = 1;
	img.colorint = 1;
	img.ymin = -1;
	img.ymax = 1;
	img.x0 = (img.xmax - img.xmin) / 2;
	img.y0 = (img.ymax - img.ymin) / 2;
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

int	main_julia(t_data img, double c1, double c2)
{
	img.zoom = 0;
	img.mlx = mlx_init();
	img.width = 600;
	img.height = 600;
	img.xmin = -1;
	img.xmax = 1;
	img.ymin = -1.2;
	img.c1 = c1;
	img.c2 = c2;
	img.ymax = 1.2;
	img.colorint = 1;
	img.x0 = (img.xmax - img.xmin) / 2;
	img.y0 = (img.ymax - img.ymin) / 2;
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

int	main(int argc, char **argv)
{
	t_data	img;
	char	*str1;
	char	*str2;

	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		main_mandelbrot(img);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc < 4)
		{
			printf("Error\n");
			return (0);
		}
		str1 = argv[2];
		str2 = argv[3];
		main_julia(img, ft_atod(str1), ft_atod(str2));
	}
	else if (ft_strcmp(argv[1], "burningship") == 0)
	{
		printf("burningship\n");
	}
}
