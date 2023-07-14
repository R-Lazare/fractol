/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:48:13 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/14 19:27:25 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	***getlist(double b)
{
	double	*rs;
	double	*x;
	int		***LIST;
	double	*u;
	int		*X;
	int		**list;

	rs = (double *)malloc(100 * sizeof(double));
	x = (double *)malloc(100 * sizeof(double));
	LIST = malloc(100 * sizeof(int **));
	u = (double *)malloc(5 * sizeof(double));
	for (int i = 0; i < 100; i++)
	{
		rs[i] = 3.98 + ((3.985 - 3.98) / 100) * i;
	}
	x[0] = 0.5 + b * 0.0001;
	for (int ri = 0; ri < 100; ri++)
	{
		for (int n = 1; n < 100; n++)
		{
			x[n] = rs[ri] * x[n - 1] * (1 - x[n - 1]);
		}
	for (int i = 95, j = 0; i < 100; i++, j++)
	{
		u[j] = x[i];
	}
	list = malloc(100 * sizeof(int *));
	X = malloc(100 * sizeof(int));
	X[0] = round(u[0] * 255);
	for (int j = 0; j < 100; j++)
	{
		for (int i = 0; i < 100 - 4; i += 4)
		{
			X[i] = round(u[j] * 255);
			list[j] = malloc(3 * sizeof(int));
			list[j][0] = fmod(X[i] * X[i + 4], 256);
			list[j][1] = fmod(X[i + 1] * X[i + 4], 256);
			list[j][2] = fmod(X[i + 2] * X[i + 4], 256);
		}
	}
		LIST[ri] = list;
	}
	return (LIST);
}

int	colors(int m, int max_iter, t_data img)
{
	int	*color;
	int	**colorset;
	int	i;

	i = img.colorint;
	color = malloc(sizeof(int) * 3);
	colorset = malloc(sizeof(int*) * 7);
	for (int i = 0; i < 7; i++)
	{
		colorset[i] = malloc(sizeof(int) * 3);
	}
	colorset[0][0] = 255;
	colorset[0][1] = 0;
	colorset[0][2] = 0;
	
	colorset[1][0] = 0;
	colorset[1][1] = 0;
	colorset[1][2] = 255;
	
	colorset[2][0] = 0;
	colorset[2][1] = 255;
	colorset[2][2] = 0;
	
	colorset[3][0] = 255;
	colorset[3][1] = 255;
	colorset[3][2] = 0;
	
	colorset[4][0] = 255;
	colorset[4][1] = 0;
	colorset[4][2] = 255;

	colorset[5][0] = 0;
	colorset[5][1] = 255;
	colorset[5][2] = 255;
	
	colorset[6][0] = 255;
	colorset[6][1] = 255;
	colorset[6][2] = 255;

	if (color == NULL)
	{
		return (0);
	}
	if (m == max_iter)
	{
		color[0] = 15;
		color[1] = 0;
		color[2] = 2;
	}
	else
	{
		for (int i = 0; i < 7; i++)
		{
			if (m < max_iter / 7 * (i + 1))
			{
				color[0] = 2 * cos(m / 100) * colorset[i][0] * (m - max_iter / 7 * i) / (max_iter / 7);
				color[1] = colorset[i][1] * (m - max_iter / 7 * i) / (max_iter / 7);
				color[2] = colorset[i][2] * (m - max_iter / 7 * i) / (max_iter / 7);
				break;
			}
		}
	}
	i = create_trgb(0, color[0], color[1], color[2]);
	free(color);
	free(colorset);
	
	return (i);
}
