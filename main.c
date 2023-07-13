/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:18:35 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/13 20:35:21 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	main(void)
{
	t_data	img;
	
	img.zoom = 0;
	img.mlx = mlx_init();
	img.width = 600;
	img.height = 400;
	img.xmin = -2;
	img.xmax = 1;
	img.ymin = -1;
	img.ymax = 1;
	img.x0 = (img.xmax - img.xmin)/2;
	img.y0 = (img.ymax - img.ymin)/2;
	img.win = mlx_new_window(img.mlx, img.width, img.height, "Hello world!");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mandelbrot(img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
