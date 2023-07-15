/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:48:13 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/15 17:57:27 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	*getlist_helper(double b, int n)
{
	double	*u;
	double	*rs;
	double	*x;
	int		i;

	rs = malloc(n * sizeof(double));
	x = malloc(n * sizeof(double));
	u = malloc(n * sizeof(double));
	i = 0;
	while (i < n)
	{
		rs[i] = 3.98 + ((3.985 - 3.98) / n) * i;
		i++;
	}
	x[0] = 0.5 + b * 0.0001;
	i = 0;
	while (i++ < n)
		x[i] = rs[i] * x[i - 1] * (1 - x[i - 1]);
	i = 0;
	while (i < n && (i + 95) < n)
	{
		u[i] = x[i + 95];
		i++;
	}
	return (u);
}

int	**getlist(double b)
{
	int		j;
	int		**list;
	double	*u;
	int		*x;

	j = 0;
	list = malloc(200 * sizeof(int *));
	u = getlist_helper(b, 200);
	x = malloc(200 * sizeof(int));
	while (j++ < 200)
		x[j] = round(u[j % 200] * 255);
	j = 0;
	while (j < 200)
	{
		list[j / 4] = malloc(3 * sizeof(int));
		list[j / 4][0] = x[j] * x[(j + 4) % 200] % 256;
		list[j / 4][1] = x[(j + 1) % 200] * x[(j + 4) % 200] % 256;
		list[j / 4][2] = x[(j + 2) % 200] * x[(j + 4) % 200] % 256;
		j += 4;
	}
	free(u);
	free(x);
	return (list);
}

int	*colors_helper(int m, int max_iter, t_data img)
{
	int	*color;
	int	i;
	int	c;

	c = 22;
	i = 0;
	color = malloc(sizeof(int) * 3);
	while (i < c)
	{
		if (m < max_iter / c * (i + 1))
		{
			color[0] = 2 * cos(m * 2 / 100) * img.colorset[i][0] * (m - max_iter
					/ c * i) / (max_iter / c);
			color[1] = img.colorset[i][1] * (m - max_iter / c * i) / (max_iter
					/ c);
			color[2] = img.colorset[i][2] * (m - max_iter / c * i) / (max_iter
					/ c);
			break ;
		}
		i++;
	}
	return (color);
}

int	colors(int m, int max_iter, t_data img)
{
	int	*color;
	int	i;

	color = malloc(sizeof(int) * 3);
	if (color == NULL)
	{
		return (0);
	}
	if (m == max_iter)
	{
		color[0] = (int)(img.colorset[0][0] / 100);
		color[1] = (int)(img.colorset[0][1] / 100);
		color[2] = (int)(img.colorset[0][2] / 100);
	}
	else
	{
		color = colors_helper(m, max_iter, img);
	}
	i = create_trgb(0, color[0], color[1], color[2]);
	free(color);
	return (i);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
